#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>

#include "File.h"

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

void writeArrayPointers(char ** text, char * buf, const size_t fileSize)
{
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

}

void outputFile(FILE * fout, char ** text, char * buf, const size_t nLine)
{

    for(size_t i = 0; i < nLine; i++)
    {
        if((int)text[i][0] > '\r')
            fputs(text[i], fout);
    }

    free(buf);
    free(text);

}
