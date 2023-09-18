#ifndef FILE_H_INCLUDED
#define FILE_H_INCLUDED

char * getFileContent(size_t * fileSize);

size_t getCountLine(char * buf, const size_t fileSize);

char ** writeArrayPointers(char * buf, const size_t fileSize, const size_t nLine);

void outputFile(char ** text, char * buf, const size_t nLine);

#endif // FILE_H_INCLUDED
