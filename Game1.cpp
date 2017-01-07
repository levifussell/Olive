#include "Game1.h"

#include "EventHandler.h"

GameObject* obj;
GameObject* block;
GameObject* block2;
int speedX = -1;
int speedY = 1;

Game1::Game1()
    : Page()
{

}

void Game1::initialise()
{
    //call base class to set to initialised
    Page::initialise();


    obj = new GameObject("imageFiles/test1.txt");
    obj->setZOrder(0);
    obj->setPos(10, 2);
    obj->setZOrder(0);

    block = new GameObject("imageFiles/block1.txt");
    block->setPos(5, 2);
    block->setZOrder(1);

    block2 = new GameObject("imageFiles/block1.txt");
    block2->setPos(8, 4);
}

void Game1::unInitialise()
{

}

void Game1::update()
{
    if(!this->initialised)
        return;

    if(obj->getRight() >= 140)
        speedX *= -1;
    if(obj->getLeft() <= 0)
        speedX *= -1;
    if(obj->getBottom() >= 40)
        speedY *= -1;
    if(obj->getTop() <= 0)
        speedY *= -1;

    Event* e = EventHandler::getNextEvent();
    if(e)
    {
        if(e->data == (int)'d')
        {
            speedX = 1;
        }
        else if(e->data == (int)'a')
        {
            speedX = -1;
        }
        else
        {
            speedX = 0;
        }

        if(e->data == (int)'w')
        {
            speedY = -1;
        }
        else if(e->data == (int)'s')
            speedY = 1;
        else
            speedY = 0;

        //std::cout << (char)e->data;
        delete e;
    }
    else
    {
        speedX = 0;
        speedY = 0;
    }

    obj->setPos(obj->getPosX() + speedX, obj->getPosY() + speedY);
}

void Game1::draw()
{

}
