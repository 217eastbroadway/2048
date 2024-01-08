#include "prismFinder.h"

int getObjectIndexByID(std::vector<pObject*> vPrism, const char* id){
    for(int i = 0; i < vPrism.size(); i++)
        if(!strcmp(vPrism[i]->getID(), id))
            return i;

    return -1;
}