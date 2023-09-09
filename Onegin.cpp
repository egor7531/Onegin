#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <sys/stat.h>

size_t getFileSize(FILE * fp);

void fileReadCheckAndWrite(char * buf, FILE * fp, const size_t fileSize);

size_t fillingArrayOfPointers(char ** text, char * buf, const size_t fileSize);

int main()
{

    FILE * fp = fopen("Eugene Onegin.txt","r");

    assert(fp != NULL);

    size_t fileSize = getFileSize(fp) + 1;

    char * buf = (char *)calloc(fileSize, sizeof(char));

    assert(buf != NULL);

    fileReadCheckAndWrite(buf, fp, fileSize);

    fclose(fp);

    char ** text = (char **)calloc(sizeof(char), sizeof(char*));

    assert(text != NULL);

    size_t line = fillingArrayOfPointers(text, buf, fileSize);

    printf("<%d>",line);

    free(buf);

    printf("%s\n",text[0]);

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

}

size_t fillingArrayOfPointers(char ** text, char * buf, const size_t fileSize)
{
    size_t line = 1;

    text[0] = buf;

    for( size_t i = 0; i < fileSize; i++)
    {
        if(buf[i] == '\n')
        {
            buf[i] = '\0';
            text = (char **)realloc(text, line*sizeof(char*)+ i*sizeof(char));
            text[line++] = &buf[i+1];
        }
    }

    for(size_t i = 0; i < line; i++)
        printf("%s\n",text[i]);

    return line;

}
