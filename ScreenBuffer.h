#ifndef SCREEN_BUFFER
#define SCREEN_BUFFER

#include<iostream>

#include "GameObject.h"
#include "LinkedList.h"
#include "colors.hpp"

class ScreenBuffer
{
private:
    int width;
    int height;
    char** screen;
    ColorType** screenColor;
    LinkedList<GameObject> objectBufferList;
public:
    ScreenBuffer(int width, int height);
    ~ScreenBuffer();

    void clear();
    void addToBuffer(GameObject obj);
    void draw();
};

#endif
