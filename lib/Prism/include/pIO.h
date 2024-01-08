#pragma once
#include <pObject.h>

namespace pIO{
    namespace mouseHandler{
        void anchorObjects(std::vector<pObject*> &vPrism);

        void deanchorObjects(std::vector<pObject*> &vPrism);

        void movebymice(std::vector<pObject*> &vPrism);
    }

    namespace fileHandler{
        void parseString(const char* str, std::vector<std::string> &vStr);
    }
}