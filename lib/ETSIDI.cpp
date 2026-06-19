#include "ETSIDI.h"
#include <ft2build.h>
#include FT_FREETYPE_H
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
#include <string>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

static FT_Library ftLibrary = nullptr;
static FT_Face ftFace = nullptr;
static int currentFontSize = 12;
static float textR = 1.0f, textG = 1.0f, textB = 1.0f, textA = 1.0f;
static std::string currentFontPath;

/*  Texture cache: avoids loading PNG from disk every frame.
 *  getTexture() checks this map first and only loads+uploads on a miss. */
static std::map<std::string, ETSIDI::GLTexture> s_textureCache;

static bool initFreeType() {
    if (ftLibrary) return true;
    if (FT_Init_FreeType(&ftLibrary) != 0) {
        fprintf(stderr, "ETSIDI: Failed to init FreeType\n");
        return false;
    }
    return true;
}

static bool loadFont(const char *path, int size) {
    if (!initFreeType()) return false;
    if (ftFace && currentFontPath == path && currentFontSize == size) return true;
    if (ftFace) {
        FT_Done_Face(ftFace);
        ftFace = nullptr;
    }
    if (FT_New_Face(ftLibrary, path, 0, &ftFace) != 0) {
        fprintf(stderr, "ETSIDI: Failed to load font: %s\n", path);
        return false;
    }
    FT_Set_Pixel_Sizes(ftFace, 0, size);
    currentFontPath = path;
    currentFontSize = size;
    return true;
}

ETSIDI::GLTexture ETSIDI::getTexture(const char *texturePath) {
    /* Check cache first */
    auto it = s_textureCache.find(texturePath);
    if (it != s_textureCache.end())
        return it->second;

    GLTexture result = {0, 0, 0};
    int w, h, channels;
    unsigned char *data = stbi_load(texturePath, &w, &h, &channels, 4);
    if (!data) {
        fprintf(stderr, "ETSIDI: Failed to load texture: %s\n", texturePath);
        return result;
    }
    GLuint texId;
    glGenTextures(1, &texId);
    glBindTexture(GL_TEXTURE_2D, texId);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    stbi_image_free(data);
    result.id = texId;
    result.width = w;
    result.height = h;
    s_textureCache[texturePath] = result;
    return result;
}

void ETSIDI::setTextColor(float r, float g, float b, float alpha) {
    textR = r / 255.0f;
    textG = g / 255.0f;
    textB = b / 255.0f;
    textA = alpha;
}

void ETSIDI::setFont(const char *fuente, int size) {
    loadFont(fuente, size);
}

void ETSIDI::printxy(const char *txt, int x, int y, int z) {
    if (!txt || !*txt) return;
    if (!ftFace && !loadFont(currentFontPath.empty() ? "fuentes/Bitwise.ttf" : currentFontPath.c_str(), currentFontSize)) return;
    FT_Set_Pixel_Sizes(ftFace, 0, currentFontSize);
    FT_GlyphSlot slot = ftFace->glyph;
    int penX = 0, penY = 0;
    int minX = 0, maxX = 0, minY = 0, maxY = 0;
    bool first = true;
    for (const char *p = txt; *p; p++) {
        if (FT_Load_Char(ftFace, (unsigned char)*p, FT_LOAD_RENDER)) continue;
        int x0 = penX + slot->bitmap_left;
        int y0 = penY - slot->bitmap_top;
        int x1 = x0 + (int)slot->bitmap.width;
        int y1 = y0 + (int)slot->bitmap.rows;
        if (first) {
            minX = x0; maxX = x1; minY = y0; maxY = y1;
            first = false;
        } else {
            if (x0 < minX) minX = x0;
            if (x1 > maxX) maxX = x1;
            if (y0 < minY) minY = y0;
            if (y1 > maxY) maxY = y1;
        }
        penX += slot->advance.x >> 6;
    }
    int w = maxX - minX;
    int h = maxY - minY;
    if (w <= 0 || h <= 0) return;
    unsigned char *buffer = (unsigned char *)calloc(w * h, 4);
    penX = 0;
    for (const char *p = txt; *p; p++) {
        if (FT_Load_Char(ftFace, (unsigned char)*p, FT_LOAD_RENDER)) continue;
        int x0 = penX + slot->bitmap_left - minX;
        int y0 = penY - slot->bitmap_top - minY;
        for (unsigned int j = 0; j < slot->bitmap.rows; j++) {
            for (unsigned int i = 0; i < slot->bitmap.width; i++) {
                int bufIdx = (y0 + (int)j) * w + (x0 + (int)i);
                unsigned char val = slot->bitmap.buffer[j * slot->bitmap.width + i];
                buffer[bufIdx * 4 + 0] = (unsigned char)(textR * 255.0f);
                buffer[bufIdx * 4 + 1] = (unsigned char)(textG * 255.0f);
                buffer[bufIdx * 4 + 2] = (unsigned char)(textB * 255.0f);
                buffer[bufIdx * 4 + 3] = val;
            }
        }
        penX += slot->advance.x >> 6;
    }
    /* FreeType pixel sizes become enormous in world space with a perspective
     * projection (the visible area is only ~80×60 units).  Scale the quad
     * down so text fits on screen.  Tweak this factor as needed. */
    const float kScale = 1.0f / 12.0f;
    float sw = (float)w * kScale;
    float sh = (float)h * kScale;

    GLuint texId;
    glGenTextures(1, &texId);
    glBindTexture(GL_TEXTURE_2D, texId);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, buffer);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    /* Prevent transparent text texels from writing phantom depth values
     * that occlude board geometry behind them. */
    glDepthMask(GL_FALSE);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texId);
    glBegin(GL_POLYGON);
    glTexCoord2d(0, 0); glVertex3f((float)x, (float)y, (float)z);
    glTexCoord2d(1, 0); glVertex3f((float)(x + sw), (float)y, (float)z);
    glTexCoord2d(1, 1); glVertex3f((float)(x + sw), (float)(y + sh), (float)z);
    glTexCoord2d(0, 1); glVertex3f((float)x, (float)(y + sh), (float)z);
    glEnd();
    glDisable(GL_TEXTURE_2D);
    glDepthMask(GL_TRUE);
    glDisable(GL_BLEND);
    glDeleteTextures(1, &texId);
    free(buffer);
}
