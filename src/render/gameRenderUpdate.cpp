#include "gameRender.h"

namespace gameRender{
    void updateGraphic(std::vector<pObject*> &vPrism, int v[4][4], int width, int height, SDL_Renderer* rend){
        for(int i = 0; i < height; i++)
            for(int j = 0; j < width; j++){
                int index = getObjectIndexByID(vPrism, std::string(std::to_string(i+1) + "_" + std::to_string(j+1)).c_str());

                if(index != -1){
                    std::cout << "Object \"" << vPrism[index]->getID() << "\" was found @ index " << index << std::endl;
                    pRender::moveQueue(vPrism, index, vPrism.size()-1);
                    delete vPrism[vPrism.size()-1];
                    vPrism.pop_back();
                }
                
                if(v[i][j] != 0){
                    SDL_Color textColor;
					int textSize = 130;
                    switch(v[i][j]){
                        case 2: textColor = {255, 255, 255, 0}; break;
                        case 4: textColor = {255, 200, 175, 0}; break;
                        case 8: textColor = {100, 100, 100, 0}; break;
                        case 16: textColor = {255, 100, 100, 0}; break;
                        case 32: textColor = {255, 0, 0, 0}; break;
                        case 64: textColor = {255, 255, 0, 0}; break;
                        case 128: textColor = {200, 200, 200, 0}; break;
                        case 256: textColor = {0, 200, 175, 0}; break;
                        case 512: textColor = {0, 100, 175, 0}; break;
                        case 1024: textColor = {0, 100, 100, 0}; break;
                        case 2048: textColor = {0, 0, 255, 0}; break;
                    }
					if(v[i][j] > 512)
						textSize =  65;
					if(v[i][j] > 64)
						textSize = 95;
					
                    vPrism.push_back(new pTextObject(std::string(std::to_string(i+1) + "_" + std::to_string(j+1)).c_str(), std::to_string(v[i][j]).c_str(), "assets/fonts/helvetica_neue_65.ttf", textSize, textColor, 175*j, 175*i, false, false, rend));
                }
            }
    }
}