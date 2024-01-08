#include "initPrism.h"

void initPrism(SDL_Window*& win, SDL_Renderer*& rend, const char* configFile){
    if (SDL_Init(SDL_INIT_VIDEO) != 0){
        puts("Error initializing video output.");
        exit(-1);
    }
    if(TTF_Init() == -1)
        std::cout << SDL_GetError() << std::endl;

    std::ifstream filein;
    filein.open(configFile, std::ios::in);
    int x, y;
    filein >> x;
    filein >> y;

    win = SDL_CreateWindow("2048 - [PRISM 0.9] [DEV_ALPHA]", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, x, y, SDL_WINDOW_RESIZABLE);
    if (!win){
        puts("Error creating window.");
        SDL_Quit();
    }

    rend = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (!rend){
      puts("Error creating renderer.");
      SDL_DestroyWindow(win);
      SDL_Quit();
    }
}