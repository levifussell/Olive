#include "Page.h"

Page::Page()
{
    this->initialised = false;
    this->gameObjectManager = new GameObjectManager();
}

Page::~Page()
{
    delete this->gameObjectManager;
}

void Page::initialise()
{
    this->initialised = true;
}

GameObjectManager* Page::getGameObjectManager() { return this->gameObjectManager; }
bool Page::isInitialised() { return this->initialised; }
