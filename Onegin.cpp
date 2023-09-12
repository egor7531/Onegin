#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <sys/stat.h>

size_t getFileSize(FILE * fp);

void fileReadCheckAndWrite(char * buf, FILE * fp, const size_t fileSize);

size_t getCountOfLine(char * buf, const size_t fileSize);

void fillingArrayOfPointers(char ** text, char * buf, const size_t fileSize);

int main()
{

    FILE * fp = fopen("Eugene Onegin.txt","rb");

    assert(fp != NULL);

    size_t fileSize = getFileSize(fp);

    char * buf = (char *)calloc(fileSize, sizeof(char));

    assert(buf != NULL);

    fileReadCheckAndWrite(buf, fp, fileSize);

    size_t nLine = getCountOfLine(buf, fileSize);

    char ** text = (char **)calloc(nLine, sizeof(char*));

    assert(text != NULL);

    fillingArrayOfPointers(text, buf, fileSize);


    for(size_t i = 0; i < nLine; i++)
        printf("%s\n", text[i]);


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

void fileReadCheckAndWrite(char * buf, FILE * fp, const size_t fileSize)
{

    if(fread(buf, sizeof(char), fileSize, fp) != fileSize)
    {
        if(feof(fp))
            printf("Premature end of file\n");

        else
            printf("File read error\n");

    }

    fclose(fp);

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
