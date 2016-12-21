#include<iostream>
#include<fstream>

class FileReader
{
public:
    static void readFileAsImage(char* fileName, char*** imageArray, int& imageWidth, int& imageHeight);
};
