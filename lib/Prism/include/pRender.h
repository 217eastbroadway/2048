#pragma once
#include <iostream>
#include <vector>
#include <string>

#include <SDL.h>
#include <SDL_image.h>

extern SDL_Renderer* renderer;
extern SDL_Window* win;

namespace pRender{
    SDL_Texture* makeTextureFromImage(std::string textureDir);

    void copyToRender(SDL_Texture* srcTexture, SDL_Rect *destRectangle);

    template <typename T>
    void moveQueue(std::vector<T>& vT, int currentPos, int newPos){
        if(currentPos > newPos){
            T copy = vT[currentPos];

            for(int i = currentPos; i > newPos; i--)
                vT[i] = vT[i-1];

            vT[newPos] = copy;
        }

        if(currentPos < newPos){
            T copy = vT[currentPos];

            for(int i = currentPos; i < newPos; i++)
                vT[i] = vT[i+1];

            vT[newPos] = copy;
        }

        if(currentPos == newPos)
            return;
    }

    void clearWindow();

    void updateWindow();
}