#include <stdio.h>

/*
int main(void){
    int a[5][5] = {0}; //2D array, 5x5 = 25

    for(int i = 0; i<5; i++){
        for(int j = 0; j <5; j++){
            printf("%4d", a[i][j]);
        }
        puts(""); // new line
    }

    return 0;
}

*/

// 9x9 2d array, multiplication table

int main(void) {
  int a[9][9] = {0};

  // initialize rows to 9
  for(int row = 1; row < 9; row++){
      a[row][0] = row+1;
  } 
  // initialize columns to 9
  for (int col = 0; col < 9; col++) {
    a[0][col] = col + 1;
  }

  // print array
  printf("%s", "Original Array: \n");
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      printf("%4d", a[i][j]);
    }
    puts("");
  }
  puts("");

  for(int col = 1; col < 9; col++){
    for(int row = 1; row <9; row++){
        a[row][col] = (row+1)*(col+1);
    }
    puts("");
  }
    printf("%s", "New Array: \n");
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      printf("%4d", a[i][j]);
    }
    puts("");
  }

  return 0;
}