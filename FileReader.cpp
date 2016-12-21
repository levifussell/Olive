#include "FileReader.h"
#include<stdlib.h>
#include<iostream>

void FileReader::readFileAsImage(char* fileName, char*** imageArray, int& imageWidth, int& imageHeight) {
    int c;
    unsigned int currentLine = 0;
    unsigned int currentColumn = 0;
    const unsigned int bufferLines = 2;
    FILE* file;
    file = fopen(fileName, "r");
    if(file)
    {
        while((c = getc(file)) != EOF)
        {
            std::cout << "LN: " << currentLine << " COL: " << currentColumn << " CH: " << (char)c << "\n";
            if(c != (int)'\n')
            {
                if(currentLine == 0)
                {
                    imageWidth = c - '0';
                    std::cout << "WIDTH: " << imageWidth << "\n";
                }
                else if(currentLine == 1)
                {
                    imageHeight = c - '0';
                    std::cout << "HEIGHT: " << imageHeight << "\n";
                    (*imageArray) = new char*[imageHeight];
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
                        (*imageArray)[currentLine - bufferLines][i] = '*';
                    }
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
