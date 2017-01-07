
#include "GameObject.h"
#include "FileReader.h"
#include "PageManager.h"
#include "GameObjectManager.h"
#include<string.h>

GameObject::GameObject()
{
    this->initialise();

    //GameObjectManager::addObject(this);
}

GameObject::GameObject(char* fileName)
{
    this->initialise();

    FileReader::readFileAsImage(fileName, &this->image, this->width, this->height, this->color);

    //std::cout << "COL:" << _Colors::toType("MAGENTA") << "\n";
    //std::cout << "STRRERERE: " << (bool)strcmp("MMMAGENTA", "MAGENTA") << "\n";

    //add the object to the current Page
    // TODO: make the page specifiable in a constructor
    Page* currentPage = PageManager::getCurrentPage();

    if(currentPage)
    {
        GameObjectManager* gameObjectManager = currentPage->getGameObjectManager();

        if(gameObjectManager)
        {
            gameObjectManager->addObject(this);
        }
    }

    //GameObjectManager::addObject(this);
}

GameObject::~GameObject()
{
    for(int r = 0; r < this->height; ++r)
    {
        delete[] this->image[r];
    }

    delete[] this->image;
}

GameObject::GameObject(const GameObject& other)
{
    this->id = other.id;
    this->width = other.width;
    this->height = other.height;
    this->posX = other.posX;
    this->posY = other.posY;
    this->zOrder = other.zOrder;
    this->color = other.color;

    //copy memory of the image file
    this->image = new char*[this->height];

    for(int r = 0; r < this->height; ++r)
    {
        this->image[r] = new char[this->width];
        for(int c = 0; c < this->width; ++c)
        {
            this->image[r][c] = other.image[r][c];
        }
    }
}

GameObject& GameObject::operator=(const GameObject& other)
{
    if(this != &other)
    {
        this->id = other.id;
        this->width = other.width;
        this->height = other.height;
        this->posX = other.posX;
        this->posY = other.posY;
        this->zOrder = other.zOrder;
        this->color = other.color;

        this->image = new char*[this->height];

        for(int r = 0; r < this->height; ++r)
        {
            this->image[r] = new char[this->width];
            for(int c = 0; c < this->width; ++c)
            {
                this->image[r][c] = other.image[r][c];
            }
        }
    }

    return *this;
}

int GameObject::idCount = 0;
int GameObject::getNextId()
{
    GameObject::idCount++;
    return GameObject::idCount;
}

void GameObject::initialise()
{
    this->id = GameObject::getNextId();
    this->width = 0;
    this->height = 0;
    this->posX = 0;
    this->posY = 0;
    this->image = 0;
    this->color = BLUE;
}

int GameObject::getWidth() { return this->width; }
int GameObject::getHeight() { return this->height; }
char** GameObject::getImage(){ return this->image; }
int GameObject::getPosX(){ return this->posX; }
int GameObject::getPosY(){ return this->posY; }
int GameObject::getId(){ return this->id; }
char GameObject::getPixel(int r, int c) { return this->image[r][c]; }
float GameObject::getZOrder(){ return this->zOrder; }
ColorType GameObject::getColor(){ return this->color; }
int GameObject::getLeft(){ return this->posX; }
int GameObject::getRight(){ return this->posX + this->width; }
int GameObject::getTop(){ return this->posY; }
int GameObject::getBottom(){ return this->posY + this->height; }

void GameObject::setPos(int x, int y)
{
    this->posX = x;
    this->posY = y;
}
void GameObject::setPosX(int x){ this->posX = x; }
void GameObject::setPosY(int y){ this->posY = y; }
void GameObject::setZOrder(float z){ this->zOrder = z; }
void GameObject::setColor(ColorType color){ this->color = color; }


