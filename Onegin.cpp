#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "File.h"
#include "Sort.h"

const char * ifileName = "Eugene Onegin.txt";
const char * ofileName = "SortedFile.txt";

int main()
{
    printf("%d", compareEnd("", "fasdfadf"));

    FILE * fileInput = fopen(ifileName,"rb");

    assert(fileInput != NULL);

    size_t fileSize = getfileSize(fileInput);

    char * buf = (char *)calloc(fileSize, sizeof(char));

    assert(buf != NULL);

    fileRead(buf, fileInput, fileSize);

    fclose(fileInput);

    size_t nLine = getCountLine(buf, fileSize);

    char ** text = (char **)calloc(nLine, sizeof(char*));

    assert(text != NULL);

    writeArrayPointers(text, buf, fileSize);

    FILE * fileOutput = fopen(ofileName, "wb");

    QSort(text, 0, nLine - 1, nLine, compareStart);

    outputFile(fileOutput, text, buf, nLine);

    fclose(fileOutput);

    return 0;
}





