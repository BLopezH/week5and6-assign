#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

struct vector{
    int *data;
    int size;
    int capacity;
};

Vector vectorNew(int size){
    Vector vec = (Vector)malloc(sizeof(struct vector));
    if(vec == NULL){
        return NULL;
    }

    vec->size = 0;
    
    if(size > 0){
        vec->capacity = size;
    }else{
        vec->capacity = 4;
    }

    vec->data = (int *)malloc(vec->capacity * sizeof(int));

    if(vec->data == NULL){
        free(vec);
        return NULL;
    }

    return vec;

}

void vectorDelete(Vector vector){
    if(vector->data != NULL){
        free(vector->data);
    }

    free(vector);

}

void vectorPush(Vector *vector, int value){
    Vector vec = *vector;

    if(vec->size >= vec->capacity){
        int increase;
        if(vec->capacity > 0){
            increase = vec->capacity;
        }else{
            increase = 4;
        }
    }

    vec->data[vec->size] = value;
    vec->size++;

}

int *vectorResize(Vector *vector,int addSize){
    if(vector == NULL || *vector == NULL){
        return NULL;
    }

    Vector vec = *vector;

    int newCap = vec->capacity + addSize;
    int *newData = (int *)malloc(newCap * sizeof(int));

    if(newData == NULL){
        return NULL;
    }

    for(int i = 0; i < vec->size; i++){
        newData[i] = vec->data[i];
    }

    free(vec->data);

    vec->data = newData;

    vec->capacity = newCap;

    return vec->data;

}

void vectorStatus(Vector vector){
    if(vector == NULL){
        return;
    }

    printf("Vector Handle Address: %p\n", (void*)vector);
    printf("Data Array Base Adress: %p\n", (void*)vector->data);
    printf("Vector Size: %d\n", vector->size);
    printf("Vector Capacity: %d\n", vector->capacity);

    if(vector->size == 0){
        printf("Vector is empty \n");
    }else{
        for(int i = 0; i < vector->size; i++){
            printf("[%d} Adress: %p, Value: %d\n", i, (void*)(vector->data + i), vector->data[i]);
        }
    }


}

int vectorPop(Vector vector){
    if(vector == NULL || vector->size == 0){
        return 0;
    }

    vector->size--;

    return vector->data[vector->size];
}

int vectorGet(Vector vector,int index){
    if(vector == NULL || index < 0 || index >= vector->size){
        return 0;
    }

    return vector->data[index];
}

int vectorSet(Vector vector, int index, int value){
    if(vector == NULL || index < 0 || index >= vector->size){
        return 0;
    }

    vector->data[index] = value;

    return 1;
}

int vectorLen(Vector vector){
    if(vector == NULL){
        return 0;
    }

    return vector->size;
}