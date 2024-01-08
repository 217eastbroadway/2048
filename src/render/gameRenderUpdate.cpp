#include "gameRender.h"

namespace gameRender{
    void updateGraphic(std::vector<pObject*> &vPrism, int vNew[4][4], int vOld[4][4], int width, int height, SDL_Renderer* rend){
        for(int i = 0; i < height; i++)
            for(int j = 0; j < width; j++){
                /*
                if(vNew[i][j] != vOld[i][j]){
                    //get ready for some really shitty code...
                    // /vPrism.push_back(new pObject(std::to_string(i + j).c_str(), std::to_string(vNew[i][j]).c_str()))
                    int index = getObjectIndexByID(vPrism, std::to_string(i + j).c_str());

                    if(index == -1 && vNew[i][j] != 0) //Graphical rappresentation doesn't exist yet.
                        vPrism.push_back(new pTextObject(std::to_string(i + j).c_str(), std::to_string(vNew[i][j]).c_str(), "assets/fonts/helvetica_neue_65.ttf", 162, {255, 255, 255, 0}, 162*i, 162*j, false, false, rend));
                    
                    else if(index != - 1 && vNew[i][j] == 0){//Graphical rappresentation exists but must be deleted now.
                        pRender::moveQueue(vPrism, index, vPrism.size()-1);
                        delete vPrism[vPrism.size()-1];
                        vPrism.pop_back();
                    }
                    else if(index != -1 && vNew[i][j] != 0)//Graphical rappresentation already exists and can be updated.
                        static_cast<pTextObject*>(vPrism[index])->setText(std::to_string(vNew[i][j]).c_str());
                }
                */
                int index = getObjectIndexByID(vPrism, std::to_string(i + j).c_str());
                if(index != -1){
                    pRender::moveQueue(vPrism, index, vPrism.size()-1);
                    delete vPrism[vPrism.size()-1];
                    vPrism.pop_back();
                }

                if(vNew[i][j] != 0)
                    vPrism.push_back(new pTextObject(std::to_string(i + j).c_str(), std::to_string(vNew[i][j]).c_str(), "assets/fonts/helvetica_neue_65.ttf", 50, {255, 255, 255, 0}, 50 * j, 50 * i, false, false, rend));
            }
    }
}