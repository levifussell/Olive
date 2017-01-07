#ifndef _PAGE
#define _PAGE

#include "GameObjectManager.h"

class Page
{
private:
    GameObjectManager* gameObjectManager;
protected:
    bool initialised;

public:
    Page();
    ~Page();

    virtual void initialise();
    virtual void unInitialise() = 0;
    virtual void update() = 0;
    virtual void draw() = 0;

    GameObjectManager* getGameObjectManager();
    bool isInitialised();
};

#endif
