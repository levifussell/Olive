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
    static void QueueEvent(Event e);
public:
    static void ThreadUpdate();
    static void Update();
    static void GetNextEvent();
};
