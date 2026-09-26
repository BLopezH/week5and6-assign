#include <stdio.h>
#include "mylib.h"

struct vector{
    int *data;
    int size;
    int capacity;
}

typedef struct vector *Vector;

Vector vectorNew(int size){
    
}

void vectorDelete(Vector vector){
    if((*vector).data != NULL){
        free((*vector).data);
    }

    free(vector);
}

void vectorPush(Vector *vector, int value){
    Vector vec = *vector;

    if((*vec).size >= (*vec).capacity){
        
    }
}

int *vectorResize(Vector *vector,int addSize){

}

void vectorStatus(Vector vector){

}

int vectorPop(Vector vector){

}

int vectorGet(Vector vector,int index){

}

int vectorSet(Vector vector, int index, int value){

}

int vectorLen(Vector vector){
    
}