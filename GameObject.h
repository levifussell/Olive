#ifndef GAME_OBJECT
#define GAME_OBJECT

#include "colors.hpp"

class GameObject
{
private:
    static int idCount;

    int id;
    char** image;

    int posX;
    int posY;
    int width;
    int height;

    float zOrder;
    ColorType color;

public:
    GameObject();
    GameObject(char* fileName);
    ~GameObject();
    GameObject(const GameObject& other);
    GameObject& operator=(const GameObject& other);

    static int getNextId();

    void setPos(int x, int y);
    void setPosX(int x);
    void setPosY(int y);
    void setZOrder(float z);
    void setColor(ColorType color);

    int getId();
    int getWidth();
    int getHeight();
    int getPosX();
    int getPosY();
    char** getImage();
    char getPixel(int r, int c);
    float getZOrder();
    ColorType getColor();

    void initialise();
    void update();
    void draw();
};

#endif
