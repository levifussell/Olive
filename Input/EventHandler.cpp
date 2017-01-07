#include "EventHandler.h"
#include "InputHandler.h"
#include<stdio.h>
//#include<conio.h>

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

LinkedList<Event*> EventHandler::eventList;

void EventHandler::initialise()
{
    //eventList = LinkedList<Event*>();
}

void EventHandler::deInitialise()
{
    eventList.clear();
}

void EventHandler::queueEvent(Event* e)
{
    eventList.push_back(e);
}

void* EventHandler::threadUpdate(void*)
{
    while(true)
    {
        //get the latest input from the keyboard
        char c = InputHandler::getch();

        Event* eKey = new Event();
        eKey->data = c;
        eKey->type = KEY;
        queueEvent(eKey);
        //std::cout << "got event: " << c << "\n";
    }
}

Event* EventHandler::getNextEvent()
{
    if(eventList.getLength() > 0)
        return eventList.pop_head();
    else
        return 0;
}

void EventHandler::printEventList()
{
    std::cout << "EVENT LIST:";
    for(int i = 0; i < eventList.getLength(); ++i)
    {
        std::cout << (char)eventList.getAtIndex(i)->data;
    }
}

int EventHandler::getNumEvents()
{
    return eventList.getLength();
}
