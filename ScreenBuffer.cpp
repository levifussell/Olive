#include "ScreenBuffer.h"

#include "_Colors.h"

#include<iostream>
#include<stdio.h>

ScreenBuffer::ScreenBuffer(int width, int height)
{
    this->width = width;
    this->height = height;

    this->screen = new char*[this->height];
    this->screenColor = new ColorType*[this->height];
    for(int r = 0; r < this->height; ++r)
    {
        this->screen[r] = new char[this->width];
        this->screenColor[r] = new ColorType[this->width];
    }

    this->clear();
}

ScreenBuffer::~ScreenBuffer()
{
    for(int r = 0; r < this->height; ++r)
    {
        delete[] this->screen[r];
        delete[] this->screenColor[r];
    }

    delete[] this->screen;

    delete[] this->screenColor;
}

void ScreenBuffer::clear()
{
    for(int r = 0; r < this->height; ++r)
    {
        for(int c = 0; c < this->width; ++c)
        {
            this->screen[r][c] = '#';
            this->screenColor[r][c] = WHITE;
        }
    }
}

void ScreenBuffer::addToBuffer(GameObject object)
{
    //Add to buffer draw list in z descending order

    for(int i = 0; i <= this->objectBufferList.getLength(); ++i)
    {
        if(i == this->objectBufferList.getLength() || object.getZOrder() < this->objectBufferList.getAtIndex(i).getZOrder())
        {
            this->objectBufferList.insert(object, i);
            std::cout << "BUFFER ID: " << this->objectBufferList.getAtIndex(0).getId() << "\n";
            return;
        }
    }

}

void ScreenBuffer::draw()
{
    //write the buffer out in the zOrder with overlap
    for(int i = 0; i < this->objectBufferList.getLength(); ++i)
    {
        GameObject obj = this->objectBufferList.getAtIndex(i);
        int startX = obj.getPosX();
        int startY = obj.getPosY();
        std::cout << startX << "," << startY << "\n";
        for(int r = 0; r < obj.getHeight(); ++r)
        {
            for(int c = 0; c < obj.getWidth(); ++c)
            {
                int addX = startX + c;
                int addY = startY + r;
                if(addX < this->width && addY < this->width && addX >= 0 && addY >= 0)
                {
                    char objPixel = obj.getPixel(r, c);
                    if(objPixel != ' ')
                    {
                        this->screen[startY + r][startX + c] = obj.getPixel(r, c);
                        this->screenColor[startY + r][startX + c] = obj.getColor();
                    }
                }
            }
        }
    }

    //draw the buffer to the screen
    for(int r = 0; r < this->height; ++r)
    {
        for(int c = 0; c < this->width; ++c)
        {
            char* colorToPrint = _Colors::toString(this->screenColor[r][c]);
            //char letter[2] = {this->screen[r][c], '\0'};
            std::cout << colorToPrint << this->screen[r][c] << RESET;
            //printf(colorToPrint "%c" RESET, this->screen[r][c]);
            //std::cout << this->screen[r][c];
        }

        printf("\n");
        //std::cout << '\n';
    }
}
