/*
COP3223 Summer 2023 Assignment 3.1
Copyright 2023 Lille_Jake
*/


//including all from chapter 7 & 8 to be safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define INIT_SIZE 4 //init array value
#define MAX_NAME_SIZE 100 //max # of elements in char array for string of name

// Function Prototypes

void expandArray(char*** array, int* size); //use *** as pointer to pointer to array, allows us to modify via. pass by reference (** = a 2D array, so to modify this 2D array we add another ptr; also take int* ptr to size to change size in function)

void printList(char** array, int size);

int findName(char** array, int size, char* name);

void removeName(char*** array, int* size, char* name); //this will modify array and size, thus need to pass by reference via. pointers (3*** for array, *for size)


int main (void){
    //init dynamic array here...
    
    int size = INIT_SIZE;
    //dynamic array is essentially a 2D array, need pointer to a pointer (singular char* points to one char/start of string)
    char** dynamicArray = (char**)malloc(size*sizeof(char*)); //use malloc to allocate space for sizeof element 1 char

    if(dynamicArray == NULL){
        printf("%s", "Memory allocation failed!\n");
    }
    else{
        printf("%s", "Success! Memory allocated.\n");
    }

    //init variables outside while scope
    int count = 0;
    char name[MAX_NAME_SIZE];

    //welcome message, let user know to enter "done"
    printf("%s", "Welcome! Enter names, type \"done\" when finished.");

  //while true... (non-zero int)
    while(1){
        printf("%s", "\nEnter name: ");
        fgets(name, MAX_NAME_SIZE, stdin); //use fgets to scan for string input in stdin stream, max size 100 and store in name variable
        
        name[strcspn(name, "\n")] = '\0'; //strcspn finds index where paramter 2 first occurs, in this case newline char that always happens and will create issues; so we find that index, set it to NULL to avoid fgets infinite loop

        //conditional to compare string; compare name to "done", will return 0 if match, if so break the while(1) always true loop
        if(strcmp(name, "done") == 0){
            break;
        }
         //counter to keep track so we allocate size approprietly
        if(count == size){
          expandArray(&dynamicArray, &size); //address as paramaters as it takes pointers to 2D string array and ptr to size so we can change in function (pass by reference)
        }
      dynamicArray[count] = strdup(name); //set index of d. array count to a copy of name using strdup to copy string
      count++; //increment count (to track size and index for assignment)
      
    }

  //puts for spacing
  puts("");
  puts("=== PRINT of ARRAY ===");
  printList(dynamicArray, count); //call to print array

  //prompt for search name
  printf("%s", "\nEnter name to search: ");
  fgets(name, MAX_NAME_SIZE, stdin); //store in name char established above
  name[strcspn(name, "\n")] = '\0'; //again, get rid of space/new line char

  //store result of findName (-1 or index of name)
  int resultFind = findName(dynamicArray, count, name);

  //if result is basically not -1 (not found)
  if(resultFind >= 0) {
    printf("Name %s found at index [%d]", name, resultFind);
  } else {
    printf("%s","\nName not found.");
  }

  //prompt for name removal
  printf("%s", "\nEnter name to remove: ");
  fgets(name, MAX_NAME_SIZE, stdin); //store in name char established above
  name[strcspn(name, "\n")] = '\0'; //again, get rid of space/new line char in stdin stream

  //removeName call, pass addresses of the array and count so we can modify in function
  removeName(&dynamicArray, &count, name);
  
  //print out new array
  puts("");
  puts("=== NEW ARRAY ===");
  printList(dynamicArray, count);

  

}


// FUNCTION DEFINITIONS
void expandArray(char*** array, int* size){
  *array = (char**)realloc(*array, (*size * 2) * sizeof(char*)); //realloc function to double memory *ptr to size to change value, times by two

  if(array == NULL){
    printf("%s", "\nMemory Re-allocation failed.");
  }
}

void printList(char** array, int size){
  for(int i = 0; i < size; i++){
    printf("\n[%d]: %s", i, array[i]);
  }
}

int findName(char** array, int size, char* name){
  for(int i = 0; i < size; i++){ //loop through array
    if(strcmp(array[i], name) == 0){ //compare
      return i; //return index
      break;
    }
  } return -1; //if not found return -1
}

void removeName(char*** array, int* size, char* name){
  //utilize findName function to check if name exists

  int index = findName(*array, *size, name); //store return of findName as index
  
  if(index != -1){
    free((*array)[index]); //free memory at said index, "removing" from array

    //shift elements down
    for(int i = index; i < (*size-1); i++){
      (*array)[i] = (*array)[i+1];
    }

    //adjust size to accomodate removed item
    (*size)--; //paranthesis needed for Order of Operations (pointer dereferenced is getting decremented, not size decrement then ptr)

    //resize array to new size, save memory
    *array = (char**)realloc(*array, (*size) * sizeof(char*));
    
  } else{
    printf("\n%s does not exist!", name);
  }
}