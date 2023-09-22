#ifndef SORT_H_INCLUDED
#define SORT_H_INCLUDED

int compareStart(const void * str1, const void * str2);

int compareEnd(const void * str1, const void * str2);

void bubbleSort(void * text, const size_t nLine, const size_t sizeValue, int (* compare)(const void *, const void *));

void QSort(void * const text, const size_t left,const size_t right, const size_t nLine, const size_t sizeType, int (* compare)(const void *, const void *));

#endif // SORT_H_INCLUDED
