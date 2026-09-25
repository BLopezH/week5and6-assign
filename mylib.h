#ifndef MYLIB_H
#define MYLIB_H

#include <stdio.h>

#define SIZE 5

Vector vectorNew(int size);
void vectorDelete(Vector vector);
void vectorPush(Vector *vector, int value);
int *vectorResize(Vector *vector,int addSize);
void vectorStatus(Vector vector);
int vectorPop(Vector vector);
int vectorGet(Vector vector,int index);
int vectorSet(Vector vector, int index, int value);
int vectorLen(Vector vector);

#endif