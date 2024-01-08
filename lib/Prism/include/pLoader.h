#pragma once
#include <pObject.h>
#include <pRender.h>
#include <pIO.h>

#include <fstream>

namespace pLoader{
    pObject* loadSingleObject(std::vector<std::string> vPrismArgs, SDL_Renderer* rend);
    pTextObject* loadSingleTextObject(std::vector<std::string> vPrismArgs, SDL_Renderer* rend);

    void loadPack(const char* fileDir, std::vector<pObject*> &vPrism, SDL_Renderer* rend);
}