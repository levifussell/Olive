#include "FileReader.h"
#include<stdlib.h>
#include<iostream>


void FileReader::readFileAsImage(char* fileName, char*** imageArray, int& imageWidth, int& imageHeight, ColorType& colorType) {
    int c;
    unsigned int currentLine = 0;
    unsigned int currentColumn = 0;
    char* colourC = new char[10];
    const unsigned int bufferLines = 3;
    FILE* file;
    file = fopen(fileName, "r");
    if(file)
    {
        while((c = getc(file)) != EOF)
        {
            //std::cout << "LN: " << currentLine << " COL: " << currentColumn << " CH: " << (char)c << "\n";
            if(c != (int)'\n')
            {
                if(currentLine == 0)
                {
                    imageWidth = c - '0';
                    //std::cout << "WIDTH: " << imageWidth << "\n";
                }
                else if(currentLine == 1)
                {
                    imageHeight = c - '0';
                    //std::cout << "HEIGHT: " << imageHeight << "\n";
                    (*imageArray) = new char*[imageHeight];
                }
                else if(currentLine == 2)
                {
                    colourC[currentColumn] = (char)c;
                }
                else
                {
                    unsigned index = currentLine - bufferLines;

                    (*imageArray)[index][currentColumn] = (char)c;
                }

                currentColumn++;
            }
            else if(c == (int)'\n')
            {
                if(currentLine > bufferLines)
                {
                    //add any empty columns at the end of the image
                    for(int i = currentColumn; i < imageWidth; ++i)
                    {
                        (*imageArray)[currentLine - bufferLines][i] = ' ';
                    }
                }

                //create colour type if moving off colour line
                if(currentLine == 2)
                {
                    colourC[currentColumn + 1] = '\0';
                    colorType = _Colors::toType(colourC);
                    //std::cout << colourC << colorType << "\n";
                }

                currentLine++;
                currentColumn = 0;


                if(currentLine >= bufferLines && currentLine - bufferLines < imageHeight)
                {
                    (*imageArray)[currentLine - bufferLines] = new char[imageWidth];
                }
            }
            else
                currentColumn++;
        }

        fclose(file);
    }

    /*delete file;*/
}
