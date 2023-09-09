#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <sys/stat.h>

size_t getFileSize(FILE * fp);

int main()
{

    FILE * fp = fopen("Onegin.txt","r");

    assert(fp != NULL);

    size_t fileSize = getFileSize(fp) + 1;

    printf("%d\n",fileSize);

    char * buf = (char *)calloc(fileSize, sizeof(char));

    assert(buf != NULL);

    if(fread(buf, sizeof(char), fileSize, fp) != fileSize)
    {
        if(feof(fp))
            printf("Premature end of file\n");

        else
            printf("File read error\n");

    }

    fclose(fp);

    puts(buf);

    char * text[10000] = {};

    text[0] = buf;

    size_t line = 1;

    for( size_t i = 0; i < fileSize; i++)
    {
        if(buf[i] == '\n')
        {
            printf("\n");
            buf[i] = '\0';
            text[line++] = &buf[i+1];
        }

    }

    printf("<%d>\n", line);

    for(size_t i = 0; i < line; i++)
        printf("%p\n",text[i]);



    return 0;
}


size_t getFileSize(FILE * fp)
{
    struct stat st;

    fstat(fileno(fp), &st);

    return st.st_size;
}
