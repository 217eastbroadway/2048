#include <Prism.h>
#include <string>
#include "../misc/prismFinder.h"

namespace gameRender{
    void updateGraphic(std::vector<pObject*> &vPrism, int vNew[4][4], int vOld[4][4], int width, int height, SDL_Renderer* rend);
}