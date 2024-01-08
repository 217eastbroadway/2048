#include <Prism.h>
#include <iostream>

#include "misc/initPrism.h"
#include "logic/gameLogic.h"
#include "render/gameRender.h"

void printMatrix(int v[4][4]){
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++)
			if(v[i][j] == 0)
				std::cout << "[-]";
			else
				std::cout << "[" << v[i][j] << "]";
		std::cout << '\n';
	}
}	

void initGame(int v[4][4], std::vector<pObject*> &vPrism, SDL_Renderer* rend){
    gameLogic::generateNewCell(v, 4, 4, 0);
    gameLogic::generateNewCell(v, 4, 4, 15);
    gameRender::updateGraphic(vPrism, v, v, 4, 4, rend);
}

int main(){
    SDL_Renderer* rend;
    SDL_Window* win;

    initPrism(win, rend, "assets/config.psconfig");

    std::vector<pObject*> vPrism;
    pLoader::loadPack("assets/mainlevel.pspkg", vPrism, rend);

    int v[4][4];
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++)
            v[i][j] = 0;

    initGame(v, vPrism, rend);

    bool userQuit = false;
    while(!userQuit){
        int vOld[4][4];
        for(int i = 0; i < 4; i++)
            for(int j = 0; j < 4; j++)
                vOld[i][j] = v[i][j];

        SDL_Event ev;
        while(SDL_PollEvent(&ev)){
            if(ev.type == SDL_QUIT)
                userQuit = true;

            if(ev.type == SDL_KEYDOWN){
                switch(ev.key.keysym.sym){
                    case SDLK_UP:
                        gameLogic::updateGameMatrix(v, 4, 4, Up);
                        gameLogic::generateNewCell(v, 4, 4, 15);
                        gameRender::updateGraphic(vPrism, v, vOld, 4, 4, rend);
                        break;
                    case SDLK_DOWN:
                        gameLogic::updateGameMatrix(v, 4, 4, Down);
                        gameLogic::generateNewCell(v, 4, 4, 15);
                        gameRender::updateGraphic(vPrism, v, vOld, 4, 4, rend);
                        break;
                    case SDLK_LEFT:
                        gameLogic::updateGameMatrix(v, 4, 4, Left);
                        gameLogic::generateNewCell(v, 4, 4, 15);
                        gameRender::updateGraphic(vPrism, v, vOld, 4, 4, rend);
                        break;
                    case SDLK_RIGHT:
                        gameLogic::updateGameMatrix(v, 4, 4, Right);
                        gameLogic::generateNewCell(v, 4, 4, 15);
                        gameRender::updateGraphic(vPrism, v, vOld, 4, 4, rend);
                        break;
                }
                system("clear");
                printMatrix(v);
                std::cout << "--- END ---" << std::endl << std::endl;
            }
        }

        pRender::clearWindow(rend);
            for(auto obj : vPrism)
                obj->update();
        pRender::updateWindow(rend);
    }

    for(auto &obj : vPrism)
        delete obj;
    
    return 0;
}