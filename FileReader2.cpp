#include "FileReader.h"
#include<stdlib.h>

void FileReader::readFileAsImage(char* fileName, char** imageArray, int& imageWidth, int& imageHeight) { char c; unsigned int currentLine = 0; unsigned int currentColumn = 0; const unsigned int bufferLines = 2; FILE* file; file = fopen(fileName, "r");
    if(file)
    {
        while((c = getc(file)) != '\0')
        {
            if(currentLine == 0)
                imageWidth = (int)c;
            else if(currentLine == 1)
                imageHeight = (int)c;
            else
            {
                unsigned index = currentLine - bufferLines;

                imageArray[index][currentColumn] = c;
            }

            if(c == '\n')
            {
                currentLine++;
                currentColumn = 0;
            }
            else
                currentColumn++;
        }

        fclose(file);
    }

    delete file;
}
