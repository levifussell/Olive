#ifndef _COLORS
#define _COLORS

#include "colors.hpp"

//FOREGROUND
#define RESET "\x1B[0m"
#define F_RED "\x1B[31m"
#define F_GREEN "\x1B[32m"
#define F_YELLOW "\x1B[33m"
#define F_BLUE "\x1B[34m"
#define F_MAGENTA "\x1B[35m"
#define F_CYAN "\x1B[36m"
#define F_WHITE "\x1B[37m"


class _Colors
{
public:
    static ColorType toType(char* text);
    static char* toString(ColorType type);

};

#endif
