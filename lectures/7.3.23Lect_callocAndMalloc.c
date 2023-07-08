#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int a[5] = {0};
  //dynamic array will init var size at RUNTIME, size can be modified (expand/shrink)
  // use malloc for dynamic allocation for block of memory
  // ptr = (cast-type*)malloc(byte-size);    ** INCLUDE stdlib.h

  int *ptr;
  int size = 10; // can change, and will change size of ptr (allocation in memory)

  ptr =  (int*)malloc(size*sizeof(int)); // dynamically adjusts size, size currently 100, multiplies that by sizeof integer type so ie. 100 elements of integer in this array

  //will return NULL if address not returned to ptr variable

  //good practice to check for NULL
  if(ptr == NULL){
    printf("%s", "Return NULL! Memory not located. \n");
  } else{
    printf("%s", "Success! Memory allocated.\n");
  }
  
  for(int j = 0; j < size; j++){
    ptr[j] =j; // put values into array
  }

  for(int i = 0; i < size; i++){
    printf("%d", *(ptr+i));
  }

  //calloc: allocate specified # of blocks and init them to 0
  // ptr = (cast_type*)calloc(n, element-size);
  int *cptr;
  int size2 = 5;
  cptr = (int*)calloc(size2, sizeof(int));
  if(cptr == NULL){
    printf("%s", "Return NULL! Memory not located. \n");
  } else{
    printf("%s", "Success! Memory allocated.\n");



    // CALLOC v. MALLOC : malloc uses "trash data" to init, CALLOC inits all space to 0
  
  return 0;
}