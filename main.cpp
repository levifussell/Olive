
#include<iostream>
#include<stdio.h>
#include<sys/time.h>
//#include<thread>
#include<pthread.h>

#include "Objects/GameObject.h"
/*#include "LinkedList.h"*/
#include "Screen/ScreenBuffer.h"
//#include "GameObjectManager.h"
#include "Pages/Page.h"
#include "Pages/Game1.h"
#include "Managers/PageManager.h"
#include "Input/InputHandler.h"
#include "Input/EventHandler.h"

const int screenWidth = 140;
const int screenHeight = 40;

char screenBuffer[screenHeight][screenWidth];

ScreenBuffer screen = ScreenBuffer(screenWidth, screenHeight, RED);

//GameObject* obj;
//GameObject* block;
//GameObject* block2;

void Initialise();
void Update();
void DeInitialise();
float timedifference_msec(struct timeval t0, struct timeval t1);
void* getInput(void*);

float timedifference_msec(struct timeval t0, struct timeval t1)
{
    return (t1.tv_sec - t0.tv_sec) * 1000.0f + (t1.tv_usec - t0.tv_usec) / 1000.0f;
}

void* getInput(void*) //param is a dummy pointer
{
    while(true)
    {
        char c = InputHandler::getch();
        std::cout << "got input: " << c << "\n";
    }
}

int main()
{

    Initialise();

    //start event handling thread
    pthread_t tEvent;
    pthread_create(&tEvent, 0, &EventHandler::threadUpdate, 0);

    double fps = 60/1;
    struct timeval lastUpdateTime, currentTime;
    gettimeofday(&lastUpdateTime, 0);

    while(true)
    {
        gettimeofday(&currentTime, 0);
        float elapsedMs = timedifference_msec(lastUpdateTime, currentTime);

        if(elapsedMs > 1000.0f * (1/fps))
        {
            gettimeofday(&lastUpdateTime, 0);
            Update();
        }
    }

    return 0;
}

void Initialise()
{
    EventHandler::initialise();
    //GameObjectManager::initialise();
    PageManager::initialise();
    Game1* game1 = new Game1();
    PageManager::addPage(game1);
    PageManager::changePage(0);

    //obj = new GameObject("imageFiles/test1.txt");
    //obj->setZOrder(0);
    //obj->setPos(5, 2);
    //obj->setZOrder(0);

    //block = new GameObject("imageFiles/block1.txt");
    //block->setPos(5, 2);
    //block->setZOrder(1);

    //block2 = new GameObject("imageFiles/block1.txt");
    //block2->setPos(8, 4);
}
//int speedX = -1;
//int speedY = 1;

void Update()
{
    screen.clearBuffer();
    //obj.setPos(obj.getPosX() + 1, obj.getPosY());
    //
    //
    //
    //if(obj->getRight() >= screen.getScreenWidth())
        //speedX *= -1;
    //if(obj->getLeft() <= 0)
        //speedX *= -1;
    //if(obj->getBottom() >= screen.getScreenHeight())
        //speedY *= -1;
    //if(obj->getTop() <= 0)
        //speedY *= -1;

    PageManager::updateCurrentPage();

    //screen.addToBuffer(block);
    //screen.addToBuffer(obj);
    //screen.addToBuffer(block2);
    screen.addAllGameObjectsToBuffer();
    //std::cout << GameObjectManager::getNumObjects();
    //EventHandler::printEventList();
    //Event* e = EventHandler::getNextEvent();
    //if(e)
    //{
        //if(e->data == (int)'d')
        //{
            //speedX = 1;
        //}
        //else if(e->data == (int)'a')
        //{
            //speedX = -1;
        //}
        //else
        //{
            //speedX = 0;
        //}

        //if(e->data == (int)'w')
        //{
            //speedY = -1;
        //}
        //else if(e->data == (int)'s')
            //speedY = 1;
        //else
            //speedY = 0;

        ////std::cout << (char)e->data;
        //delete e;
    //}
    //else
    //{
        //speedX = 0;
        //speedY = 0;
    //}
    //char c = InputHandler::getch();
    //std::cout << c;

    //obj->setPos(obj->getPosX() + speedX, obj->getPosY() + speedY);

    screen.draw();

    if(screen.getChangeInBuffer())
        std::cout << "\n";
}
