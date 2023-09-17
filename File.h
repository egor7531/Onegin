#ifndef WORKINGWITHFILE_H_INCLUDED
#define WORKINGWITHFILE_H_INCLUDED

size_t getfileSize(FILE * fin);

void fileRead(char * buf, FILE * fin, const size_t fileSize);

size_t getCountLine(char * buf, const size_t fileSize);

void writeArrayPointers(char ** text, char * buf, const size_t fileSize);

void outputFile(FILE * fout, char ** text, char * buf, const size_t nLine);

#endif // WORKINGWITHFILE_H_INCLUDED
