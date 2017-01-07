#include "InputHandler.h"

struct termios InputHandler::old;
struct termios InputHandler::newd;

void InputHandler::initTermios(int echo)
{
    tcgetattr(0, &old); //grab old terminal io settings
    newd = old; //make new settings same as old settings
    newd.c_lflag &= ~ICANON; //disable buffered io
    newd.c_lflag &= echo ? ECHO : ~ECHO; //set echo mode
    tcsetattr(0, TCSANOW, &newd); //use these terminal io settings now
}

void InputHandler::resetTermios()
{
    tcsetattr(0, TCSANOW, &old);
}

char InputHandler::getch_(int echo)
{
    char ch;
    initTermios(echo);
    ch = getchar();
    resetTermios();
    return ch;
}

char InputHandler::getch()
{
    return getch_(0);
}

//char InputHandler::getchech()
//{
    //return getch_(1);
//}

