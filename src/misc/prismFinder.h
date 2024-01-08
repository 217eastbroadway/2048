#include <Prism.h>
#include <string>

int getObjectIndexByID(std::vector<pObject*> vPrism, const char* id);
//Will return index of object if found, upon failure will return -1