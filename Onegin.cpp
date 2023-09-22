#include <stdio.h>

#include "File.h"
#include "Sort.h"


int main()
{
    size_t fileSize = 0;

    char * buf = getFileContent(&fileSize);

    size_t nLine = getCountLine(buf, fileSize);

    char ** text = writeArrayPointers(buf, fileSize, nLine);

    //bubbleSort(text, nLine, sizeof(text[0]), compareStart);

    QSort(text, 0, nLine - 1, nLine, sizeof(text[0]), compareEnd);

    outputFile(text, buf, nLine);

    return 0;
}





