#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <sys/stat.h>

size_t getFileSize(FILE * fp);

int main()
{

    FILE * fp = fopen("Eugene Onegin.txt","r");

    assert(fp != NULL);

    size_t fileSize = getFileSize(fp) + 1;

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

    size_t line = 1;

    char ** text = (char **)calloc(line*strlen(buf), sizeof(char*));

    text[0] = buf;

    for( size_t i = 0; i < fileSize; i++)
    {

        if(buf[i] == '\n')
        {
            buf[i] = '\0';
            text = (char **)realloc(text, line*sizeof(char*) + i*sizeof(char));
            text[line++] = &buf[i+1];
        }

    }

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
