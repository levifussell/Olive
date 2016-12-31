#include "ScreenBuffer.h"

#include "_Colors.h"
#include "GameObjectManager.h"

#include<iostream>
#include<stdio.h>
#include<stdlib.h>

ScreenBuffer::ScreenBuffer(int width, int height, ColorType backgroundColor)
{
    this->width = width;
    this->height = height;
    this->backgroundColor = backgroundColor;
    this->objectBufferList = LinkedList<GameObject>();

    this->screen = new char*[this->height];
    this->screenOld = new char*[this->height];
    this->screenColor = new ColorType*[this->height];
    this->screenColorOld = new ColorType*[this->height];
    for(int r = 0; r < this->height; ++r)
    {
        this->screen[r] = new char[this->width];
        this->screenOld[r] = new char[this->width];
        this->screenColor[r] = new ColorType[this->width];
        this->screenColorOld[r] = new ColorType[this->width];
    }

    //clear the terminal at the start so we are
    // working with a blank canvas
    system("clear");
    this->clear(true);
    this->drawBorder();
}

ScreenBuffer::~ScreenBuffer()
{
    for(int r = 0; r < this->height; ++r)
    {
        delete[] this->screen[r];
        delete[] this->screenOld[r];
        delete[] this->screenColor[r];
        delete[] this->screenColorOld[r];
    }

    delete[] this->screen;
    delete[] this->screenOld;

    delete[] this->screenColor;
    delete[] this->screenColorOld;
}

void ScreenBuffer::drawBorder()
{
    for(int r = 0; r < this->height; ++r)
    {
        for(int c = 0; c < this->width; ++c)
        {

        }
    }
}

void ScreenBuffer::clear(bool allStates)
{
    for(int r = 0; r < this->height; ++r)
    {
        for(int c = 0; c < this->width; ++c)
        {
            this->screen[r][c] = ' ';
            this->screenColor[r][c] = this->backgroundColor;

            if(allStates)
            {
                this->screenOld[r][c] = ' ';
                this->screenColorOld[r][c] = BLUE; //we start the old screen on a random colour so that background colour is drawn at start
            }
        }
    }

}

void ScreenBuffer::addToBuffer(GameObject* object)
{
    //Add to buffer draw list in z descending order

    for(int i = 0; i <= this->objectBufferList.getLength(); ++i)
    {
        if(i == this->objectBufferList.getLength() || object->getZOrder() < this->objectBufferList.getAtIndex(i).getZOrder())
        {
            this->objectBufferList.insert(*object, i);
            //std::cout << "BUFFER ID: " << this->objectBufferList.getAtIndex(0).getId() << "\n";
            return;
        }
    }

}

void ScreenBuffer::addAllGameObjectsToBuffer()
{
    for(int i = 0; i < GameObjectManager::getNumObjects(); ++i)
    {
        this->addToBuffer((GameObjectManager::getObjectByIndex(i)));
    }
}

void ScreenBuffer::clearBuffer()
{
    this->objectBufferList.clear();
}

void ScreenBuffer::drawAtPoint(char pixel, int posX, int posY, char* colorForeground, char* colorBackground)
{
    //move cursor to the specifis position
    std::cout << "\033[" << posY <<";" << posX << "H";

    std::cout << colorForeground << colorBackground << pixel << RESET;
}


void ScreenBuffer::draw()
{
    this->clear(false);

    //write the buffer out in the zOrder with overlap
    for(int i = 0; i < this->objectBufferList.getLength(); ++i)
    {
        GameObject obj = this->objectBufferList.getAtIndex(i);
        int startX = obj.getPosX();
        int startY = obj.getPosY();
        //std::cout << startX << "," << startY << "\n";
        for(int r = 0; r < obj.getHeight(); ++r)
        {
            for(int c = 0; c < obj.getWidth(); ++c)
            {
                int addX = startX + c;
                int addY = startY + r;
                if(addX < this->width && addY < this->height && addX >= 0 && addY >= 0)
                {
                    char objPixel = obj.getPixel(r, c);
                    if(objPixel != ' ')
                    {
                        this->screen[addY][addX] = obj.getPixel(r, c);
                        this->screenColor[addY][addX] = obj.getColor();
                    }
                }
            }
        }
    }

    //draw all characters to the screen that are different between the new screen
    //and the old screen
    for(int r = -1; r < this->height + 1; ++r)
    {
        for(int c = -1; c < this->width + 1; ++c)
        {
            if(r == -1 || c == -1 || r == this->height || c == this->width)
            {
                //std::cout << "H";
            }
            else
            {
                //check that this character is a NEW character
                if(this->screen[r][c] != this->screenOld[r][c] ||
                        this->screenColor[r][c] != this->screenColorOld[r][c])
                {
                    char* colorToPrintForeground = _Colors::toStringForeground(this->screenColor[r][c]);
                    char* colorToPrintBackground = _Colors::toStringBackground(this->screenColor[r][c]);

                    this->drawAtPoint(this->screen[r][c], c + this->borderSize, r + this->borderSize, colorToPrintForeground, colorToPrintBackground);
                    //move cursor to the specifis position
                    //std::cout << "\033[" << r + this->borderSize <<";" << c + this->borderSize << "H";


                    //char letter[2] = {this->screen[r][c], '\0'};
                    //std::cout << colorToPrint << this->screen[r][c] << RESET;
                    //printf(colorToPrint "%c" RESET, this->screen[r][c]);
                    //std::cout << this->screen[r][c];
                }
            }
        }

        //printf("\n");
        //std::cout << '\n';
    }

    //save the current screen state as the old state so
    //that we can compare it next draw update
    for(int r = 0; r < this->height; ++r)
    {
        for(int c = 0; c < this->width; ++c)
        {
            this->screenOld[r][c] = this->screen[r][c];
            this->screenColorOld[r][c] = this->screenColor[r][c];
        }
    }
}

int ScreenBuffer::getScreenWidth() { return this->width; }
int ScreenBuffer::getScreenHeight() { return this->height; }
