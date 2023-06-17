/*
COP3223 Summer 2023 Assignment 2.2
Copyright 2023 Lille_Jake
*/

#include <stdio.h>

int gcd(int x, int y); // function prototype

int main(void) { // main function for getting x and y to find GCD
  int x, y; // need to declare to bring local vars into scope
  scanf("%d %d", &x, &y); //store vars

  printf("%d", gcd(x,y)); //call function, print the result
  
  return 0; // success
}


//function definition for gcd
int gcd(int x, int y){
  if(y != 0){ //if y = 0, then our GCD is just x; if not, we continue using recursion
    return gcd(y, x % y); //flip y and x, so it continues until x % y = 0, returning y which is now 'x' as the GCD
  } else {
    return x; //upon end will return 'x', which is y as it was flipped
  }
}