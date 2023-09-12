#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <algorithm>

#include "Sort.h"


void swaps(char * a, char * b)
{
    char * tmp = a;
    a = b;
    b = tmp;

}

bool stringComparison(const char * str1, const char * str2)
{

    assert(str1 != NULL);
    assert(str2 != NULL);


    for(size_t i = 0; str1[i] != '\0' && str2[i] != '\0'; i++)
    {
        if(str1[i] - str2[i] < 0)
            return 1;

        else if(str1[i] - str2[i] > 0)
            return 2;

    }

    return 0;

}

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
                std::swap(text[i], text[i+1]);

                nSwaps = true;
            }

        }

        if(!nSwaps)
            break;

    }

}
