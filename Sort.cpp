#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include <time.h>

#include "Sort.h"

void swaps(char ** a, char ** b);


int Partition(char ** text, int left, int right, const int dataSize);


void swaps(char **a, char **b)
{
    assert(a != NULL);
    assert(b != NULL);

    char * tmp = *a;
    *a = *b;
    *b = tmp;

}

//Bubble Sort

void bubbleSort(char ** text, const size_t nLine)
{

    assert(text != NULL);


    for(size_t nPass = 0; nPass < nLine - 1; nPass++)
    {

        bool nSwaps = false;

        for(size_t i = 0; i < nLine - nPass - 1; i++)
        {

            assert(i <= nLine);
            assert(i + 1 <= nLine);

            if(strcmp(text[i], text[i+1]) > 0)
            {
                swaps(&text[i], &text[i+1]);

                nSwaps = true;
            }

        }

        if(!nSwaps)
            break;

    }

}

//Qsort

void QSort(char ** text, int left, int right, const int nLine)
{

    assert(text != NULL);

    assert(0 <= right && right < nLine);
    assert(0 <= left && left < nLine);

    int mid = Partition(text, left, right, nLine);

    if(mid - 1 > left)

        QSort(text, left, mid - 1, nLine);


    if(mid + 1 < right)

        QSort(text, mid + 1, right, nLine);

}


int Partition(char ** text, int left, int right, const int nLine)
{

    assert(text != NULL);

    srand(time(NULL));

    int mid = left + rand() % (right - left + 1);

    while(left < right)
    {

        assert(0 <= right && right < nLine);
        assert(0 <= left && left < nLine);

        while(strcmp(text[left], text[mid]) < 0 && left != mid)
            left++;

        while(strcmp(text[right], text[mid]) >= 0 && mid != right)
            right--;

        if(mid == right)
            mid = left;

        else if(mid == left)
            mid = right;

        swaps(&text[left], &text[right]);


    }

    return mid;

}
