#include <stdio.h>

//THIS IS PASS BY REFERENCE!! ALLOWS CHANGE OF VALUE, DIRECT CHANGE TO VALUE STORED IN ADDRESS


int plusOne(int n);
void plusOne_ref(int* nPtr);

int main(void){
  int number =5 ;
  number = plusOne(number); //pass by VALUE
  printf("number is %d\n", number);

  plusOne_ref(&number); //PASS BY REFERENCE; pass address, to where it is de-referenced in function to add
  
  printf("number is %d", number);
  
}

int plusOne(int n){
  return n+1;
}
//actually modify number in the main
void plusOne_ref(int* nPtr){
  *nPtr += 1; //de-reference pointer, change value by +1

  //no return needed (void), changes value in memory
}