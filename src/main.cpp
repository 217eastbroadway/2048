#include <Prism.h>
#include <iostream>

#include "misc/initPrism.h"
#include "logic/gameLogic.h"
#include "render/gameRender.h"

void initGame(int v[4][4], std::vector<pObject*> &vPrism){
	gameLogic::generateNewCell(v, 4, 4, 0);
	gameLogic::generateNewCell(v, 4, 4, 15);
	
    gameRender::updateGraphic(vPrism, v, 4, 4);
}

int main(){
    initPrism("assets/config.psconfig");

    std::vector<pObject*> vPrism;
    pLoader::loadPack("assets/mainlevel.pspkg", vPrism);

    int v[4][4];
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++)
            v[i][j] = 0;

    initGame(v, vPrism);

    bool userQuit = false;
    while(!userQuit){
        SDL_Event ev;
        while(SDL_PollEvent(&ev)){
            if(ev.type == SDL_QUIT)
                userQuit = true;

            if(ev.type == SDL_KEYDOWN){
                switch(ev.key.keysym.sym){
                    case SDLK_UP:
                        if(gameLogic::updateGameMatrix(v, 4, 4, Up))
                            gameLogic::generateNewCell(v, 4, 4, 15);
                        gameRender::updateGraphic(vPrism, v, 4, 4);
                        break;

                    case SDLK_DOWN:
                        if(gameLogic::updateGameMatrix(v, 4, 4, Down))
                            gameLogic::generateNewCell(v, 4, 4, 15);
                        gameRender::updateGraphic(vPrism, v, 4, 4);
                        break;

                    case SDLK_LEFT:
                        if(gameLogic::updateGameMatrix(v, 4, 4, Left))
                            gameLogic::generateNewCell(v, 4, 4, 15);
                        gameRender::updateGraphic(vPrism, v, 4, 4);
                        break;

                    case SDLK_RIGHT:
                        if(gameLogic::updateGameMatrix(v, 4, 4, Right))
                            gameLogic::generateNewCell(v, 4, 4, 15);

                        gameRender::updateGraphic(vPrism, v, 4, 4);
                        break;
                }
            }
        }

        pObject::updateRenderer(vPrism);
        SDL_Delay(125);
    }

    for(auto &obj : vPrism)
        delete obj;
    
    return 0;
}