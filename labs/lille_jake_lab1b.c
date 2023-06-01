#include <stdio.h>

int main(void) {

  //init. variables...
  int number; 
  int digit1, digit2, digit3, digit4, digit5;

  //prompt user...
  printf("Enter a five-digit number: ");
  /*get user input... instructions did not ask to test user input if = 5 digits
  or not, so user theorhetically could mess up input and program will print 
  last 5 digits if more than 5 entered, or supplement 0s for lacking digits
  */
  scanf("%d", &number);

  // with iterative integer division and remainder operation, we need to work backwards
  
  //starting w/ last digit, % by 10 gives us last value, so we init. digit5 var to that
  digit5 = number % 10;
  // dividing the number by 10 and init. it, we eliminate that digit as integers cannot have decimals
  number /= 10;
  //repeat until last digit (digit1)
  digit4 = number % 10;
  number /= 10;
  digit3 = number % 10;
  number /= 10;
  digit2 = number % 10;
  number /= 10;
  digit1 = number % 10;

  //print out results and point properly to correct integer variables; "%d" spaced by 3 spaces as instructed...
  printf("%d   %d   %d   %d   %d\n", digit1, digit2, digit3, digit4, digit5);

  // return 0 to tell compiler we successfully ran our main() function!
  return 0;
}

/*
COP3223 Summer 2023 Lab1B
Copyright 2023 Lille_Jake
*/