#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#include "Sort.h"

char * srtingReverse(const char * str)
{
    size_t strSize = strlen(str);
    char * strRever = (char *)calloc(strSize + 1, sizeof(char));

    size_t j = 0;

    for(int i = strSize - 1; i >= 0 ; i--)
        strRever[j++] = str[i];

    strRever[j] = '\0';

    return strRever;
}

void mySwap(void * a, void * b, const size_t sizeValue)
{
    void * tmp = malloc(sizeValue);

    memmove(tmp, a, sizeValue);
    memmove(a, b, sizeValue);
    memmove(b, tmp, sizeValue);

}

//Bubble Sort

void bubbleSort(char ** const text, const size_t nLine)
{

    assert(text != NULL);


    for(size_t nPass = 0; nPass < nLine - 1; nPass++)
    {

        bool beSwap = false;

        for(size_t i = 0; i < nLine - nPass - 1; i++)
        {

            assert(i <= nLine);
            assert(i + 1 <= nLine);

            if(strcmp(text[i], text[i+1]) > 0)
            {
                mySwap(&text[i], &text[i+1], sizeof(text[i]));

                beSwap = true;
            }

        }

        if(!beSwap)
            break;

    }

}

//Qsort

int compareStart(const void * str1, const void * str2)
{
    return strcmp((const char * )str1, (const char * )str2);
}

int compareEnd(const void * str1, const void * str2)
{
    return strcmp(srtingReverse((const char * )str1), srtingReverse((const char * )str2));

}


int Partition(void * text, size_t left, size_t right, const size_t nLine, const size_t sizeType, int (* compare)(const void *, const void *))
{

    assert(text != NULL);

    srand(time(NULL));

    int mid = left + rand() % (right - left + 1);

    while(left < right)
    {
        assert(0 <= mid && mid <= nLine);
        assert(right < nLine);
        assert(left < nLine);

        while(compare((char *)text + left, (char *)text + mid) < 0 && left != mid)
            left++;

        while(compare((char *)text + right, (char *)text + mid) >= 0 && mid != right)
            right--;

        if(mid == right)
            mid = left;

        else if(mid == left)
            mid = right;

        mySwap((char *)text + left, (char *)text + right, sizeType);

    }

    return mid;

}

void QSort(void * text, const size_t left,const size_t right, const size_t nLine, const size_t sizeType, int (* compare)(const void *, const void *))
{

    assert(text != NULL);

    assert(right < nLine);
    assert(left < nLine);

    int mid = Partition(text, left, right, nLine, sizeType, compare);

    if(mid - 1 > left)

        QSort(text, left, mid - 1, nLine, sizeType, compare);


    if(mid + 1 < right)

        QSort(text, mid + 1, right, nLine, sizeType, compare);

}

