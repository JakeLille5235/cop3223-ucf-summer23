/*
COP3223 Summer 2023 Lab 9B
Copyright 2023 Lille_Jake
*/

#include <stdio.h>
#include <stdlib.h>


// Function Prototypes
int power2(int number, int power);

void convertToBits(int n);

int main(void){

  //declare vars
  int userNumber;
  int userPower;
  
  //prompt for input
  printf("%s", "Enter number: ");
  scanf("%d", &userNumber);
  printf("%s", "Enter power: ");
  scanf("%d", &userPower);

  //num to convert to bits from returned value in power2
  int numToBits = power2(userNumber, userPower);

  //call convertToBits and pass var for conversion
  convertToBits(numToBits);
  
}

// Function definitions...

int power2(int number, int power){
  int result = number << power; //left shift bit 
  printf("\n%d", result);
  return result;
}

void convertToBits(int n){
    int binaryNum[32];
    int revBinaryNum[32]; //need to return array reversed
  
    // counter for binary array
    int i = 0;
    while (n > 0) {
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }
    puts("");

    // reverse array, store reversed values properly in revBinaryNum, print
    for(int j = i-1; j >= 0; j--){
      int count = 0;
      revBinaryNum[count] = binaryNum[j];
        
      printf("%d", revBinaryNum[count]);
      count++;
    }
  ;
}