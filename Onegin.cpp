#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "File.h"
#include "Sort.h"


int main()
{
    size_t fileSize = 0;

    char * buf = getFileContent(&fileSize);

    size_t nLine = getCountLine(buf, fileSize);

    char ** text = writeArrayPointers(buf, fileSize, nLine);

    QSort(text, 0, nLine - 1, nLine, compareStart);

    outputFile(text, buf, nLine);

    return 0;
}





