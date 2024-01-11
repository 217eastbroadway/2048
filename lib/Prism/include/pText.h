#pragma once
#include <pRender.h> //Prism render module
#include <SDL_ttf.h> //SDL TrueType-Font library

#define PRISMTEXTRED {255, 0, 0}
#define PRISMTEXTGREEN {0, 255, 0}
#define PRISMTEXTBLUE {0, 0, 255}
#define PRISMTEXTWHITE {255, 255, 255}

namespace pText{
    SDL_Texture* textToTexture(const char* text, TTF_Font* font, const SDL_Color textColor);

    void getFontSize(const char* text, TTF_Font* font, int* width, int* height);
}