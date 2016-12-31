#include "_Colors.h"
#include<string.h>

ColorType _Colors::toType(char* text)
{
    if(strcmp(text, "RED"))
        return RED;
    else if(strcmp(text, "GREEN"))
        return GREEN;
    else if(strcmp(text, "YELLOW"))
        return YELLOW;
    else if(strcmp(text, "BLUE"))
        return BLUE;
    else if(strcmp(text, "MAGENTA"))
        return MAGENTA;
    else if(strcmp(text, "CYAN"))
        return CYAN;
    else if(strcmp(text, "WHITE"))
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
