#ifndef FILE_READER
#define FILE_READER

#include<iostream>
#include<fstream>

#include "../Screen/Colors/_Colors.h"
#include "../Screen/Colors/colors.hpp"

class FileReader
{
public:
    static void readFileAsImage(char* fileName, char*** imageArray, int& imageWidth, int& imageHeight, ColorType& colorType);
};

#endif
