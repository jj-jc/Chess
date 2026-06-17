#pragma once
#include <GL/gl.h>
#include <GL/glu.h>
#include <cmath>

namespace ETSIDI {
    struct GLTexture {
        GLuint id;
        int width;
        int height;
    };

    GLTexture getTexture(const char *texturePath);
    void setTextColor(float r, float g, float b, float alpha = 1.0F);
    void setFont(const char *fuente, int size = 12);
    void printxy(const char *txt, int x, int y, int z = 0);
}
