#include "GameObjectManager.h"

GameObjectManager::GameObjectManager()
{
    this->initialise();
}
GameObjectManager::~GameObjectManager()
{
    this->deInitialise();
}

void GameObjectManager::initialise()
{
    //gameObjects = LinkedList<GameObject>();
}

void GameObjectManager::deInitialise()
{
    gameObjects.clear();
    //for(int i = 0; i < gameObjects.getLength(); ++i)
    //{
        //delete gameObjects.getAtIndex(i);
    //}
}

void GameObjectManager::addObject(GameObject* object)
{
    //if(!isInitiaslised)
        //throw new Exception("GameObjectManager must be initialised before use.");

    gameObjects.push_back(object);
}

GameObject* GameObjectManager::getObjectByIndex(unsigned int index)
{
    return (gameObjects.getAtIndex(index));
}

bool GameObjectManager::collision(const GameObject& objA, const GameObject& objB)
{
    return false;
}

int GameObjectManager::getNumObjects()
{
    return gameObjects.getLength();
}
