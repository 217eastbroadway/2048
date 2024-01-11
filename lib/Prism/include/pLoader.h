#pragma once
#include <pObject.h>
#include <pRender.h>
#include <pIO.h>

#include <fstream>

namespace pLoader{
    pObject* loadSingleObject(std::vector<std::string> vPrismArgs);
    pTextObject* loadSingleTextObject(std::vector<std::string> vPrismArgs);

    void loadPack(const char* fileDir, std::vector<pObject*> &vPrism);
}