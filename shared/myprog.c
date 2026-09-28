#include <stdio.h>
#include "vector.h"

int main(){
    //make vector
    Vector newVector = vectorNew(10);

    if(newVector == NULL){
        printf("Failed to allocate memory. \n");
        return 1;
    }

    //check status
    vectorStatus(newVector);

    //check vector length
    printf("Vector length: %d\n", vectorLen(newVector));

    //Pushing a few values then checking
    vectorPush(&newVector, 3);
    vectorPush(&newVector, 6);
    vectorStatus(newVector);

    //Setting values
    if(vectorSet(newVector, 1, 8)){
        printf("Index 1 set to 8 \n");
    }else{
        printf("Failed to set index \n");
    }
    
    //Getting values
    printf("Element at index 2: %d\n", vectorGet(newVector, 2));
    printf("Element at index 0: %d\n", vectorGet(newVector, 0));
    
    //Resizing vector then checking status
    vectorResize(&newVector, 9);
    vectorStatus(newVector);

    //Popping values then checking status
    int valuePopped = vectorPop(newVector);
    printf("Popped Value: %d\n", valuePopped);
    vectorStatus(newVector);

    //Deleting vector
    vectorDelete(newVector);

    return 0;
}