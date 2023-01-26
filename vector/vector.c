#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

// initializing the vector
void init(Vector *vector, int memorySize){
    // returns the Vector struct with set parameters
    vector = malloc(sizeof(memorySize));
    (*vector).memorySize =  memorySize;
    (*vector).size = 0;
}

// printing out the contents of the vectors
void print(Vector *vector){
    for(int i = 0; i < (*vector).size; i++){
        printf("%i\n", (*vector).array[i]);
    }
}

// resizing the vector's array
void resize(Vector *vector){
    Vector *new;
    init(new, 2 * (*vector).memorySize);
    for(int i = 0; i <= (*vector).size; i++){
        (*new).array[i] = (*vector).array[i];
    }
    free(vector);
    vector = new;
}

// inserting the value at the specific location
int insert(Vector *vector, int location, int value){
    // conditions for invalid location
    if ((location > (*vector).size) || (location < 0)) {
        return 0;
    }
    // else if we can actually insert it
    else {
        // check if we need to resize
        if ((*vector).memorySize == (*vector).size){
            resize(vector);
        }
        // update the size variable
        (*vector).size++;
        // move all elements up by 1 position
        for(int i = (*vector).size; i > location; i--){
            (*vector).array[i] =  (*vector).array[i - 1];
        }
        // and insert the element
        (*vector).array[location] = value;
        return 1;
    }
}


//Obtains value at location inside the Vector
int get(Vector *vector, int location, int *value){
    if ((location > (*vector).size) || (location < 0)) {
        return 0;
    }
    else{
        (*value) = (*vector).array[location];
        return 1;
    }
}

// Removes the array associated with the Vector.
void cleanup(Vector *vector){
    free(vector);
}

int main(){
    return 0;
}