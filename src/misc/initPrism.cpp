#include "initPrism.h"

void initPrism(const char* configFile){
    std::ifstream filein;
    filein.open(configFile, std::ios::in);
    int x, y;
    filein >> x;
    filein >> y;

    pWindow::createWindow(x, y, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, "2048 - [PRISM 1.0] [DEV_ALPHA]");
}