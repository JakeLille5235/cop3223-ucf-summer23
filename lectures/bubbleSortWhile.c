#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//BUBBLE SORT

#define SIZE 10

int main(void){
    int a[SIZE] = {3,6,8,2,5,0,4,6,1,7};


// ALGORITHM 1
    int status = 1;
    while(1){
        for(size_t i = 0; i < SIZE-1; i++){
          if(a[i] > a[i+1]){
            int temp = a[i];
            a[i] = a[i+1];
            a[i+1] = temp;
            break;
          }
          if(i == SIZE-2){
            status = 0;
          }
        }

        if(status == 0){
            break;
        }
    }


    for(int j = 0; j < SIZE; j++){
        printf("%d ", a[j]);
    }
    return 0;

}