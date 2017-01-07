#include "_Colors.h"
#include<string.h>

ColorType _Colors::toType(char* text)
{
    if(strcmp(text, "RED") == 0)
        return RED;
    else if(strcmp(text, "GREEN") == 0)
        return GREEN;
    else if(strcmp(text, "YELLOW") == 0)
        return YELLOW;
    else if(strcmp(text, "BLUE") == 0)
        return BLUE;
    else if(strcmp(text, "MAGENTA") == 0)
        return MAGENTA;
    else if(strcmp(text, "CYAN") == 0)
        return CYAN;
    else if(strcmp(text, "WHITE") == 0)
        return WHITE;
    else
        return WHITE;

}

char* _Colors::toStringForeground(ColorType type)
{
    switch(type)
    {
        case RED:
            return F_RED;
        case GREEN:
            return F_GREEN;
        case YELLOW:
            return F_YELLOW;
        case BLUE:
            return F_BLUE;
        case MAGENTA:
            return F_MAGENTA;
        case CYAN:
            return F_CYAN;
        case WHITE:
        default:
            return F_WHITE;

    }
}

char* _Colors::toStringBackground(ColorType type)
{
    switch(type)
    {
        case RED:
            return B_RED;
        case GREEN:
            return B_GREEN;
        case YELLOW:
            return B_YELLOW;
        case BLUE:
            return B_BLUE;
        case MAGENTA:
            return B_MAGENTA;
        case CYAN:
            return B_CYAN;
        case WHITE:
        default:
            return B_WHITE;

    }
}
