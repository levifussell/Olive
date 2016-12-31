#include "EventHandler.h"
#include "InputHandler.h"
#include<stdio.h>
//#include<conio.h>

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

void EventHandler::QueueEvent(Event e)
{

}

void EventHandler::Update()
{
    //get the latest input from the keyboard
    char c = InputHandler::getch();

    //Event e;

    //switch((c = std::getch()))
    //{
        //case KEY_UP:
            //e.data = c;
            //e.type = KEY;
    //}
}

void EventHandler::GetNextEvent()
{

}
