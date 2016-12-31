#ifndef INPUT_HANDLER
#define INPUT_HANDLER

#include<termios.h>
#include<stdio.h>

class InputHandler
{
private:
    static struct termios old, newd;
    static void initTermios(int echo);
    static void resetTermios();
    static char getch_(int echo);
public:
    static char getch();
    //static char getchech():
};

#endif
