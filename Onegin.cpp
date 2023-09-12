#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <sys/stat.h>

#include "Sort.h"

size_t getFileSize(FILE * fin);

void fileReadCheckAndWrite(char * buf, FILE * fin, const size_t fileSize);

size_t getCountOfLine(char * buf, const size_t fileSize);

void fillingArrayOfPointers(char ** text, char * buf, const size_t fileSize);

int main()
{

    FILE * fin = fopen("Eugene Onegin.txt","rb");   // ������ ������ ��������� ����� ����� ��� .txt ?

    assert(fin != NULL);

    size_t fileSize = getFileSize(fin);

    char * buf = (char *)calloc(fileSize, sizeof(char));

    assert(buf != NULL);

    fileReadCheckAndWrite(buf, fin, fileSize);

    size_t nLine = getCountOfLine(buf, fileSize);

    char ** text = (char **)calloc(nLine, sizeof(char*));

    assert(text != NULL);

    fillingArrayOfPointers(text, buf, fileSize);


    FILE * fout = fopen("SortedFile.txt", "wb");

    for(size_t i = 0; i < nLine; i++)
        //fputs(text[i], fout);

    bubbleSort(text, nLine);

    for(size_t i = 0; i < nLine; i++)
       fputs(text[i], fout);

    fclose(fout);

    free(buf);
    free(text);

    return 0;
}


size_t getFileSize(FILE * fp)
{
    struct stat st;

    fstat(fileno(fp), &st);

    return st.st_size;
}

void fileReadCheckAndWrite(char * buf, FILE * fin, const size_t fileSize)
{

    if(fread(buf, sizeof(char), fileSize, fin) != fileSize)
    {
        if(feof(fin))
            printf("Premature end of file\n");

        else
            printf("File read error\n");

    }

    fclose(fin);

}

size_t  getCountOfLine(char * buf, const size_t fileSize)
{
    size_t nLine = 1;

    for(size_t i = 0; i < fileSize; i++)
    {

        if(buf[i] == '\n')
            nLine++;

    }

    return nLine;

}

void fillingArrayOfPointers(char ** text, char * buf, const size_t fileSize)
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
