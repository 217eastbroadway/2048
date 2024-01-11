#include <pRender.h>
#include <pText.h>

namespace pWindow{
    void createWindow(int width, int height, int posX, int posY, const char* winName);

    void getWindowPos(int &posX, int &posY);
    void getWindowSize(int &width, int &height);
}