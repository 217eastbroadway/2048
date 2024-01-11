#pragma once
#include <iostream>
#include <vector>
#include <string>

#include <pRender.h>
#include <pText.h>

class pObject{
    protected:
        SDL_Texture* texture;
        SDL_Rect rect;

        std::string id;

        int anchorX, anchorY;
        bool isAnchored;
        bool isHovered;
        bool isMovable;
        bool isHoverable;

    public:
        pObject(const char* id, const char* textureDir, int w, int h, int posX, int posY, bool isMovable, bool isHoverable); //Base constructor
        pObject(); //Default constructor

        pObject(const pObject& copy); //Copy constructor
        
        ~pObject(); //Destructor

        SDL_Rect getRect();
        const char* getID();
        void getAnchor(int& anchorX, int& anchorY);
        bool getIsAnchored();
        bool getIsHovered();
        bool getIsMovable();
        bool getIsHoverable();

        void setAnchor(int anchorX, int anchorY);
        void setIsAnchored(bool isAnchored);
        void setIsHovered(bool isHovered);
        void setIsMovable(bool isMovable);
        void setIsHoverable(bool isHoverable);
        void setTexture(const char* textureDir);
        void setPos(int newx, int newy);

        void update();

        static void updateRenderer(std::vector<pObject*> &vPrism);
};

class pTextObject : public pObject{
    private:
        std::string text;
        std::string fontDir;
        int fontSize;
        SDL_Color textColor;

    public:
        pTextObject(const char* id, const char* text, const char* fontDir, int fontSize, SDL_Color textColor, int posX, int posY, bool isMovable, bool isHoverable);
        pTextObject(const pTextObject &copy);
        ~pTextObject();

        const char* getText();
        const char* getFontDir();
        int getFontSize();
        SDL_Color getTextColor();

        void setText(const char* text);
        void setFont(const char* fontDir);
        void setFontSize(int fontSize);
        void setTextColor(SDL_Color textColor);
};