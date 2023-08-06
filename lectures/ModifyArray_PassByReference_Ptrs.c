#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void plusOneArray(int array[]);
void printArray(int array[]);

int main(void){
    int a[5] = {10,20,30,40,50};
    plusOneArray(a);
    printArray(a);

}

void plusOneArray(int array[]){
    int *arrayPointer = array;
    for(int i = 0; i < 5; i++){
        *arrayPointer += 1;
        arrayPointer += 1;
    }
}
void printArray(int array[]){
    int *arrayPointer = array;
    for(int i = 0; i < 5; i++){
        printf("Address: %p\n", arrayPointer);
        printf("%d ", *(arrayPointer + i));
    }
}