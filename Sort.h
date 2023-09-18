#ifndef SORT_H_INCLUDED
#define SORT_H_INCLUDED

int compareStart(const void * str1, const void * str2);

int compareEnd(const void * str1, const void * str2);

void bubbleSort(const char ** text, const size_t nLine);

void QSort(char ** const text, const size_t left,const size_t right, const size_t nLine, int (* compare)(const void *, const void *));

#endif // SORT_H_INCLUDED
