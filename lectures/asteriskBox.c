#include <stdio.h>

int main(void){
  //init variables
  int row = 0;
  int column = 0;
  int n = 0;

  //ask for input, store...
  printf("%s", "Enter value: ");
  scanf("%d", &n);

  //main while loop, row as container, columns finished per row
  while(row < n){
    //conditional for the border (all asterisks)
    if(row == 0 || row == n-1){
      //loop to go down column...
      while(column < n){
        printf("* ");
        column += 1;
      }
    } else { //if not border, have spaces
      while(column < n){
        //conditonal to check if border
        if(column == 0 || column == n-1){
          printf("%s", "* ");
        } else{
          printf("%s", "  ");
        }
        column += 1;
      }
    }
    row += 1;
    column = 0;
    puts(" ");
  }
}