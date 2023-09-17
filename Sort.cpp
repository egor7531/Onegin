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
    {
        strRever[j] = str[i];
        j++;
    }

    strRever[j] = '\0';

    return strRever;
}

void swapString(char ** const a, char ** const b)
{
    assert(a != NULL);
    assert(b != NULL);

    char * const tmp = *a;
    *a = *b;
    *b = tmp;

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
                swapString(&text[i], &text[i+1]);

                beSwap = true;
            }

        }

        if(!beSwap)
            break;

    }

}

//Qsort

int compareStart(const char * str1, const char * str2)
{
    return strcmp(str1, str2);
}

int compareEnd(const char * str1, const char * str2)
{
    return strcmp(srtingReverse(str1), srtingReverse(str2));
}

/*int compareEnd(const char * str1, const char * str2)
{
    size_t i1 = strlen(str1);
    size_t i2 = strlen(str2);

    while(i1 >= 0 && i2 >= 0)
    {
        if(!isalpha(str1[i1]))
        {
            i1--;
            continue;
        }

        if(!isalpha(str2[i2]))
        {
            i2--;
            continue;
        }

        if(str1[i1] != str2[i2])
        {
            i1--;
            i2--;
            continue;
        }
        else
            return (int)str1[i1] - (int)str2[i2];
    }

}*/


int Partition(char ** const text, size_t left, size_t right, const size_t nLine, int (* compare)(const char *, const char *))
{

    assert(text != NULL);

    srand(time(NULL));

    int mid = left + rand() % (right - left + 1);

    while(left < right)
    {

        assert(right < nLine);
        assert(left < nLine);

        while(compare(text[left], text[mid]) < 0 && left != mid)
            left++;

        while(compare(text[right], text[mid]) >= 0 && mid != right)
            right--;

        if(mid == right)
            mid = left;

        else if(mid == left)
            mid = right;

        swapString(&text[left], &text[right]);

    }

    return mid;

}

void QSort(char ** const text, const size_t left,const size_t right, const size_t nLine, int (* compare)(const char *, const char *))
{

    assert(text != NULL);

    assert(right < nLine);
    assert(left < nLine);

    int mid = Partition(text, left, right, nLine, compare);

    if(mid - 1 > left)

        QSort(text, left, mid - 1, nLine, compare);


    if(mid + 1 < right)

        QSort(text, mid + 1, right, nLine, compare);

}

