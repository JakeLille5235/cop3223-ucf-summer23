#include <stdio.h>
// Pointers Continued...

#define SIZE 5



// Passing Variables by Reference via. Pointers and Arrays
void printArray(int a[SIZE]);
void bubbleSort(int *arrayPtr);
void swap(int *x, int *y);

int main(void){
    int a[SIZE] = {3,6,8,2,5};
    int *aPtr = a;
    puts("data in original order: ");

    printArray(a);

/*
    for(int pass = 0; pass < SIZE; pass++){
        for(int i = 0; i < SIZE - 1; i++){
            if(a[i] > a[i+1]){
                int temp = a[i];
                a[i] = a[i+1];
                a[i+1] = temp;
            }
        }
    }
*/

    bubbleSort(aPtr);
    puts("\nnew array: ");
    printArray(a);
}

void printArray(int a[SIZE]){
    for(int i = 0; i < SIZE; i++){
        printf("%4d", a[i]);
    }
}

void bubbleSort(int *arrayPtr){
    for(int pass = 0; pass < SIZE; pass++){
        for(int i = 0; i < SIZE - 1; i++){
            if(arrayPtr[i] > arrayPtr[i+1]){
                // switching values
                swap(&arrayPtr[i], &arrayPtr[i+1]);
            }
        }
    }
}

void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}