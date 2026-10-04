# Chess (Ajedrez) — agent notes

Single-binary C++17 OpenGL/GLUT chess game. No package manager, no test suite, no CI, no `.gitignore`.

## Build & run (verified)

```bash
cmake -S . -B /tmp/chess-build && cmake --build /tmp/chess-build -j
cd /home/yoyosplay/repos/Chess && /tmp/chess-build/ChessGame   # MUST run from repo root
```

- Build **out of tree**. `build/` and `build_test/` are committed to git *including* their `.o` files and a `CMakeCache.txt` with absolute paths; building in them dirties tracked files and a moved checkout breaks the cache.
- Must run with CWD = repo root: textures/fonts are loaded with relative paths (`imagenes/*.png`, `fuentes/*.ttf`), resolved through the tracked symlinks `imagenes -> bin/imagenes` and `fuentes -> bin/fuentes`. **Do not delete those symlinks.** Launching elsewhere only prints `ETSIDI: Failed to load texture/font` and renders blank.
- Needs a display (`DISPLAY` set); there is no headless/screenshot path. No xvfb on this machine.
- `file(GLOB src/*.cpp lib/*.cpp)` picks up new files automatically.
- Pre-existing warnings are expected (do not "fix" as part of unrelated work): `APIENTRY` redefined (bundled `lib/glut.h` shadows the system header), `-Wwrite-strings` from `Pieza::setNombre(char*)`, `control reaches end of non-void function` in `Rey::PuedoMoverRey`.

## Controls

`T` top-down view (also starts the game from the menu), `R` 3D/mouse view, `P` pause, `E` unpause. Move by mouse click-click, or by typing 4 chars: file, rank, file, rank (`e2e4`); `Backspace`/`Esc` cancels. Promotion prompts take `Q`/`R`/`B`/`N` (dama/torre/alfil/caballo).

## Wiring

`src/Ajedrez.cpp:main` → one global `CoordinadorAjedrez` → state machine `INICIO | JUEGO | PAUSA` → `Mundo` owns the 32 named piece objects, selection/entry state, and all in-game rendering. `OnDraw` caches modelview/projection into `g_modelview`/`g_projection`/`g_viewport`; `Mundo::convertirpixelscoordenadas` `extern`s those globals to unproject mouse clicks. `Mundo::Dibuja` draws every piece by explicitly listing the 32 members — a new piece must be added there.

## State model (the part that bites)

- Board truth lives in **static globals** defined in `src/Tablero.cpp`: `Tablero::MatrizPuntero[8][8]` (piece pointers) and `Tablero::posiciones[8][8]` (`0` empty / `1` white / `2` black). They must stay in sync.
- Turn is `static bool CoordinadorAjedrez::quien` (`1` = white) — not on `Mundo`, not `Tablero::TURNO` (dead).
- Piece coords are logical `1..8`; world position is `Ancho_Cuadrado * pos - 1` (`Ancho_Cuadrado == 2`). Each `dibujarXconposicion()` does its own translate.
- Always move a piece via `Pieza::SetPos(x, y)`: it validates `1..8`, captures any occupant, and updates both matrices. `setDisplayPos` is display-only — it is how captured pieces are parked off-board at `x = 9..12`. Anything that must survive outside `1..8` (promotion) has to null its `MatrizPuntero` slot by hand first, as `Mundo::ejecutarPromocion` does.
- Rule reuse is via inheritance, not composition: `Torre`/`Alfil` inherit `Pieza` **virtually**, and `Dama`/`Rey` = `Torre` + `Alfil`, `Peon` = `Alfil` + `Torre`, delegating to `Torre::moverPieza` / `Alfil::moverPieza`. Keep `virtual` on the `Pieza` base or the diamond breaks. Every rule is duplicated between `moverPieza` and `PuedoMoverX` — change both.

## lib/ETSIDI is a local reimplementation

`lib/ETSIDI.cpp` reimplements the ETSIDI API (`setFont`, `setTextColor`, `printxy`, `getTexture`) on FreeType + bundled `lib/stb_image.h`; `bin/ETSIDI.dll` / `Pang.sln` are the original MSVC versions and are not used by the CMake build. `printxy` takes **world units, not pixels** — it scales the glyph quad by `1/15` and treats `(x, y)` as the lower-left corner — and it creates and deletes a texture on every call, every frame, so it is the main per-frame cost when drawing HUD text. Only `fuentes/Bitwise.ttf` and `fuentes/HarryPotter.ttf` exist. `getTexture` is cached; text is not.

## Known gaps (verified — don't rediscover these as new bugs)

- No check legality filter: `JaqueN()`/`JaqueB()` only set `rey*.jaque` for the red-king tint; moves that leave your own king attacked are allowed.
- No checkmate/stalemate detection, so `juegoTerminado` is never set `true` and the game-over overlay plus Enter/Space restart in `Mundo::dibujarEstado` are unreachable.
- Promoted pieces are registered in `MatrizPuntero` and stored in `Mundo::transfor`, which `Mundo::Dibuja` never iterates → they move correctly but are invisible.
- `Mundo::Transformacion()` is dead `cin`-based console code; `Tablero::TURNO`, `Tablero::jaqueB`, `Pieza::ImprimeNombre`, and `src/OpenGL.{h,cpp}` (empty) are unused.
- `Rey::PuedoMoverRey` falls off the end for moves that aren't 1 square away (UB, currently "works"); `Rey::enroque` is set on any king move but `Torre::enroque` is never set, so rook castling rights are never invalidated.

## Committed build junk

`Pang.sln`, `Pang.vcxproj`, `.vs/` (98 MB), `tmp/`, `Pang.sdf` (60 MB), `bin/*.dll`, `bin/Pang.exe` are Windows/MSVC artifacts from the original university project. Don't build against them or add files to the `.vcxproj` for new work; don't delete them unless asked.