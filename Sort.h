#ifndef SORT_H_INCLUDED
#define SORT_H_INCLUDED

char * srtingReverse(const char * str);

int compareStart(const char * str1, const char * str2);

int compareEnd(const char * str1, const char * str2);

void bubbleSort(const char ** text, const size_t nLine);

void QSort(char ** const text, const size_t left,const size_t right, const size_t nLine, int (* compare)(const char *, const char *));

#endif // SORT_H_INCLUDED
