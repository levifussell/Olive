
#include<iostream>

#include "GameObject.h"
/*#include "LinkedList.h"*/
#include "ScreenBuffer.h"

const int screenWidth = 40;
const int screenHeight = 20;

char screenBuffer[screenHeight][screenWidth];

ScreenBuffer screen = ScreenBuffer(screenWidth, screenHeight);

void clearScreen();
void addToBuffer(GameObject);
void draw();

int main()
{
    /*clearScreen();*/
    /*//draw();*/
    /*std::cout << "HELLO\n";*/
    GameObject obj = GameObject("imageFiles/test1.txt");
    obj.setZOrder(0);
    obj.setPos(5, 5);

    GameObject block = GameObject("imageFiles/block1.txt");
    block.setPos(6, 6);
    block.setZOrder(1);

    screen.addToBuffer(obj);
    screen.addToBuffer(block);

    screen.draw();

    /*char** imgData = obj.getImage();*/

    std::cout << obj.getWidth() << "\n" << obj.getHeight() << "\n";
    /*std::cout << sizeof(imgData) / sizeof(char) << "\n";*/
    std::cout << "DT:" << obj.getId() << "\n";
    /*if(!imgData)*/
        /*std::cout << "NULLL\n";*/
    /*for(int r = 0; r < obj.getHeight(); ++r)*/
    /*{*/
        /*for(int c = 0; c < obj.getWidth(); ++c)*/
        /*{*/
            /*std::cout << imgData[r][c];*/
        /*}*/
        /*std::cout << "\n";*/
    /*}*/

    /*addToBuffer(obj);*/
    /*draw();*/

    /*LinkedList<int> l = LinkedList<int>();*/
    /*l.insert(5000, 0);*/
    /*l.push_back(10);*/
    /*l.push_back(20);*/
    /*[>l.print();<]*/
    /*l.insert(12, 2);*/
    /*[>int val = l.pop_head();<]*/
    /*[>l.pop_head();<]*/
    /*l.print();*/
    /*[>std::cout << l.getAtIndex(1) << "\n";<]*/
    /*[>l.pop_head();<]*/
    /*l.print();*/

    return 0;
}

void clearScreen()
{
    for(int r = 0; r < screenHeight; ++r)
    {
        for(int c = 0; c < screenWidth; ++c)
        {
            screenBuffer[r][c] = '#';
        }
    }
}

void addToBuffer(GameObject obj)
{
    int startX = obj.getPosX();
    int startY = obj.getPosY();
    std::cout << startX << "," << startY << "\n";
    for(int r = 0; r < obj.getHeight(); ++r)
    {
        for(int c = 0; c < obj.getWidth(); ++c)
        {
            int addX = startX + c;
            int addY = startY + r;
            if(addX < screenWidth && addY < screenHeight && addX >= 0 && addY >= 0)
            {
                char objPixel = obj.getPixel(r, c);
                if(objPixel != ' ')
                    screenBuffer[startY + r][startX + c] = obj.getPixel(r, c);
            }
        }
    }
}

void draw()
{
    for(int r = 0; r < screenHeight; ++r)
    {
        for(int c = 0; c < screenWidth; ++c)
        {
            std::cout << screenBuffer[r][c];
        }

        std::cout << '\n';
    }
}
