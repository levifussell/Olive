#ifndef GAME_OBJECT_MANAGER
#define GAME_OBJECT_MANAGER

#include "../DataStructures/LinkedList.h"
#include "../Objects/GameObject.h"

//class GameObject;

class GameObjectManager
{
private:
    LinkedList<GameObject*> gameObjects;

    void initialise();
    void deInitialise();

public:
    GameObjectManager();
    ~GameObjectManager();
    void addObject(GameObject* object);
    GameObject* getObjectByIndex(unsigned int index);
    bool collision(const GameObject& objA, const GameObject& objB);

    int getNumObjects();
};

#endif
