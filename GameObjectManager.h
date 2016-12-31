#ifndef GAME_OBJECT_MANAGER
#define GAME_OBJECT_MANAGER

#include "LinkedList.h"
#include "GameObject.h"

//class GameObject;

class GameObjectManager
{
private:
    static bool isInitialised;
    static LinkedList<GameObject*> gameObjects;

public:
    static void initialise();
    static void deInitialise();
    static void addObject(GameObject* object);
    static GameObject* getObjectByIndex(unsigned int index);
    static bool collision(const GameObject& objA, const GameObject& objB);

    static int getNumObjects();
};

#endif
