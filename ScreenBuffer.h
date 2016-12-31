#ifndef SCREEN_BUFFER
#define SCREEN_BUFFER

#include<iostream>

#include "GameObject.h"
#include "LinkedList.h"
#include "colors.hpp"

class ScreenBuffer
{
private:
    const unsigned int borderSize = 4;
    int width;
    int height;
    ColorType backgroundColor;
    char** screen;
    char** screenOld;
    ColorType** screenColor;
    ColorType** screenColorOld;
    LinkedList<GameObject> objectBufferList;
public:
    ScreenBuffer(int width, int height, ColorType backgroundColor);
    ~ScreenBuffer();

    void drawBorder();
    void clear(bool allStates);
    void addToBuffer(GameObject* obj);
    void addAllGameObjectsToBuffer();
    void clearBuffer();
    void drawAtPoint(char pixel, int posX, int posY, char* colorForeground, char* colorBackground);
    void draw();

    int getScreenWidth();
    int getScreenHeight();
};

#endif
