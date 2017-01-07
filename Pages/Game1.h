#ifndef GAME_1
#define GAME_1

#include "../Pages/Page.h"

class Game1 : public Page
{
private:
public:
    Game1();
    void initialise();
    void unInitialise();
    void update();
    void draw();
};

#endif
