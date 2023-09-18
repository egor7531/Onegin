#include <assert.h>
#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>

#include "File.h"

const char * ifileName = "Eugene Onegin.txt";
const char * ofileName = "SortedFile.txt";

size_t getfileSize(FILE * fp)
{
    struct stat st;

    fstat(fileno(fp), &st);

    return st.st_size;
}

void fileRead(char * buf, FILE * fin, const size_t fileSize)
{

    if(fread(buf, sizeof(char), fileSize, fin) != fileSize)
    {
        if(feof(fin))
            printf("Premature end of file\n");

        else
            printf("File read error\n");

    }

}

char * getFileContent(size_t * fileSize)
{
    FILE * fileInput = fopen(ifileName,"rb");

    assert(fileInput != NULL);

    *fileSize = getfileSize(fileInput);

    char * buf = (char *)calloc(*fileSize, sizeof(char));

    assert(buf != NULL);

    fileRead(buf, fileInput, *fileSize);

    fclose(fileInput);

    return buf;
}

size_t getCountLine(char * buf, const size_t fileSize)
{
    size_t nLine = 1;

    for(size_t i = 0; i < fileSize; i++)
    {

        if(buf[i] == '\n')
            nLine++;

    }

    return nLine;

}


char ** writeArrayPointers(char * buf, const size_t fileSize, const size_t nLine)
{
    char ** text = (char **)calloc(nLine, sizeof(char*));

    assert(text != NULL);

    size_t line = 1;

    text[0] = buf;

    for(size_t i = 0; i < fileSize; i++)
    {
        if(buf[i] == '\n')
        {
            buf[i] = '\0';
            text[line++] = &buf[i+1];
        }

    }

    return text;
}
void outputFile(char ** text, char * buf, const size_t nLine)
{
    FILE * fileOutput = fopen(ofileName, "wb");

    assert(fileOutput  != NULL);

    for(size_t i = 0; i < nLine; i++)
    {
        if((int)text[i][0] > '\r')
            fputs(text[i], fileOutput);
    }

    fclose(fileOutput);

    free(buf);
    free(text);

}
