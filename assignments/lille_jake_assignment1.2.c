/*
COP3223 Summer 2023 Assignment 1.2
Copyright 2023 Lille_Jake
*/

#include <stdio.h>

int main(void) {


  //declare variables - numberTest = user's input, then all digit variables to store individual digits.
  int numberTest;
  int digit1, digit2, digit3, digit4, digit5;

  //Prompt for input
  printf("Enter a 5 digit number to test: ");
  //%d for integer, & to assign to numberTest
  scanf("%d", &numberTest);

  /* same code as separating the numbers as last time, 
  assinging the different digits to remainder, then making sure to divide by 10 to eliminate the xth number
  as we work our way down the 5 digit integer
  */
  digit5 =(numberTest%10);
  numberTest /= 10;
  digit4 =(numberTest%10);
  numberTest /= 10;
  digit3 =(numberTest%10);
  numberTest /= 10;
  digit2 =(numberTest%10);
  numberTest /= 10;
  digit1 =(numberTest%10);
  numberTest /= 10;

  //a palindrome essentially means digit 1 = digit 5, and digit 2 = digit 4, so we test via. conditional operators

  if(digit1 == digit5 & digit2 == digit4){ //utilize & as both conditons need to be true for it to be a palindrome
    printf("Your integer is a Palindrome!");
  } else { //if not true, any other option is not a palindrome
    printf("Your integer is NOT a Palindrome.");
  }
  
  
  
  return 0;
}