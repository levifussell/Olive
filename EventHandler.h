#include "LinkedList.h"

enum EventType
{
    KEY
};

struct Event
{
    int data;
    EventType type;
};

class EventHandler
{
private:
    static LinkedList<Event*> eventList;
    static void queueEvent(Event* e);
public:
    static void initialise();
    static void deInitialise();
    static void* threadUpdate(void*);
    static Event* getNextEvent();
    static void printEventList();

    static int getNumEvents();

};
