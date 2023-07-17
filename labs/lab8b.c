/*
COP3223 Summer 2023 Lab8B
Copyright 2023 Lille_Jake
*/

#include <stdio.h>
#include <stdlib.h>

// Function Prototypes (Global)
int getNum(int input);  // Get user input
void expandSize(int** ptr, int size); // Double array size
void bubbleSort(int* const array, int size); // Bubble sort (min to max integer)
int binarySearch(int* const array, int high, int low, int key);
int linearSearch(int* const array, int size, int key);

int main(void){
  int userInput = 0;
  int counter = 0;
  int* aPtr = (int*)malloc(4* sizeof(int));  // init dynamic array, 4 elements to 0
  int numElements = 4; // can't use sizeof to find element # with pointers, need to keep track
  
  // User enter -1, end program  
  while(userInput != -1){
    userInput = getNum(userInput);
    
    if(userInput != -1){
      counter++;

      //if we reach max array size elements, double the allocated memory
      if(counter == numElements){
        numElements *= 2;
        expandSize(&aPtr, numElements);
      }
      // set user input to right index
      aPtr[counter-1] = userInput;

      
    }
    
  }
  // After user done with inputting array values, sort 
  //bubbleSort(aPtr, numElements);

  puts("");


  //print out array
  for(int i = numElements-counter; i < numElements; i++){
    printf("%d ", aPtr[i]);
  }

  printf("%s", "Search (1 yes/other no): ");
  int userAnswer = 0;
  scanf("%d", &userAnswer);

  if(userAnswer == 1){
    printf("%s", "Enter Number: ");
    int userNumber;
    scanf("%d", &userNumber);

    int result = linearSearch(aPtr, numElements, userNumber);//binarySearch(aPtr, numElements, 1, userNumber);

    if(result != -1 ){
      printf("Found at %d", result);
    } else{
      printf("Not found.");
    }
  } else{
    return 0;
  }
  

}

// Function definitions
int getNum(int input){
  printf("%s", "\nEnter: ");
  scanf("%d", &input);
  
  return input;
}

void expandSize(int** ptr, int size){ //need to use ** pointer of pointer
  *ptr = realloc(*ptr, size*sizeof(int));
}

void bubbleSort(int* const array, int size){
  // Least Priviledge principle - only use swap in here, function prototype here
  void swap(int *element1Ptr, int *element2Ptr);

  for(int pass = 0; pass < size - 1; pass++){
    for(size_t i = 0; i < size-1; i++){
      if(array[i] > array[i+1]){
        swap(&array[i], &array[i+1]); //call swap to swap numbers
      }
    }
  }
}
void swap(int *element1Ptr, int *element2Ptr){
  int temp = *element1Ptr;
  *element1Ptr = *element2Ptr;
  *element2Ptr = temp;
}

int linearSearch(int* const array, int size, int key){
  for(int i = 0; i < size; i++){
    if(array[i] == key){
      return i+1; 
    } 
  }
  return -1;
}

/*
int binarySearch(int* const array, int high, int low, int key){
  int middle = (high+low)/2;
  while(low <= high){
    if(key == array[middle]){
      return middle; 
    } else if(key < array[middle]){
      high = middle-1;
    } else{
      low = middle-1;
    }
  }
  return 0;
}
*/