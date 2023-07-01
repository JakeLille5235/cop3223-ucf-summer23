/*
COP3223 Summer 2023 Lab4B
Copyright 2023 Lille_Jake
*/


#include <stdio.h>


//floor size = row and column #
#define floorSide 50
// #define commands 7


//print array function prototype, takes argument of a 2D Array
void printArray(const int b[50][50]);


//main function where all the conditionals and initilizations will occur...
int main(void){
  int floor[50][50];
  //int commandsList[commands] = {1,2,3,4,5,6,9}; this ended up being useless/redundant
  int turtlePosX = 24; //turtle pos basically x, y coordinates, set to middle (24,24)
  int turtlePosY = 24;
  int userCommand = 0;
  int status = 0; //status for pen up or down; while 0, pen is UP so 0 by default
  int direction = 0; //0 right, 1 down, 2 left, 3 up

  //% direction counter so that it automatically results when it does a 360
  
  //init 2D array all to 0s
  for(size_t i = 0; i < floorSide; i++){
    for(size_t j = 0; j < floorSide; j++){
      floor[i][j] = 0;
    }
  }
  //welcome message w/ commands
  printf("%s", "Welcome to the Lille Turtle Game! \nCommands:\n");
  printf("%s", "1: Pen Up\n2: Pen Down\n3: Turn Right\n4: Turn Left\n5: Move forward X spaces...\n6: Print Picture\n9: End program (delete picture)");
  
  //while loop, for when user enters 9 to end game
  while(userCommand != 9){
    printf("%s", "\nEnter: ");
    scanf("%d", &userCommand); //store user's command value for conditonals....

    //check for pen up or down, set status accordingly for eventual loop check when moving
    if(userCommand == 1){
      status = 0;
    } else if(userCommand == 2){
      status = 1; // drawing enabled
    } else if(userCommand == 3){ //change direction right
      direction++;
      if(direction % 4 == 0){
        printf("%s", "Facing right!\n");
      } else if(direction % 4 == 3){
        printf("%s", "Facing down!\n");
      } else if(direction % 4 == 2){
        printf("%s", "Facing left!\n");
      } else if(direction % 4 == 1){
        printf("%s", "Facing up!\n");
      }
    } else if(userCommand == 4){ //change direction left
      direction = direction + 3;
      if(direction % 4 == 0){
        printf("%s", "Facing right!\n");
      } else if(direction % 4 == 3){
        printf("%s", "Facing down!\n");
      } else if(direction % 4 == 2){
        printf("%s", "Facing left!\n");
      } else if(direction % 4 == 1){
        printf("%s", "Facing up!\n");
      }
    } else if(userCommand == 5){ //set to move mode, then ask about how many spaces to move
      int spaceNumber = 0;
      printf("%s", "Enter # of spaces: ");
      scanf("%d", &spaceNumber);

      //condtionals for what direction to move, check if pen is up or down
      if(direction % 4 == 0 && status == 1){ //right movement
        //for loop in order to sift through array
        for(size_t i = 0; i < spaceNumber; i++){
          floor[turtlePosY][turtlePosX] = 1;
          turtlePosX++; //make sure to add to position
        } //else if statement for when pen is NOT down, so not drawing, no loop needed...
        } else if(direction % 4 == 0 && status == 0){
            turtlePosX = turtlePosX + spaceNumber; //outright just set updated coordinates
      }
      if(direction % 4 == 3 && status == 1){ //down movement
        for(size_t i = 0; i < spaceNumber; i++){
          floor[turtlePosY][turtlePosX] = 1;
          turtlePosY++;
        } 
        } else if(direction % 4 == 3 && status == 0){
            turtlePosY = turtlePosY + spaceNumber;
      }
      if(direction % 4 == 2 && status == 1){
        for(size_t i = 0; i < spaceNumber; i++){
          floor[turtlePosY][turtlePosX] = 1;
          turtlePosX--;
        }
      } else if(direction % 4 == 2 && status == 0){
          turtlePosX = turtlePosX - spaceNumber;
        }
      if(direction % 4 == 1 && status == 1){
        for(size_t i = 0; i < spaceNumber; i++){
          floor[turtlePosY][turtlePosX] = 1;
          turtlePosY--;
      }
    } else if(direction % 4 == 1 && status == 0){
        turtlePosY = turtlePosY - spaceNumber;
      }
      
    } //print array using function
    else if(userCommand == 6){
      printArray(floor);
    }
  }


    //use direction %to find value ie if direction % 4 = 0 = right, direction % 4 = 2 = left
    //direction % 4 = 1 = down; direction % 4 = 3 = up
  
    /*
    if(direction == 4 && userCommand == 3){
      direction = 0;
      printf("%d\n", direction);
    } else if(direction == 0 && userCommand == 4){
      direction = 3;
      printf("%d\n", direction);
    }
    //printf("%d\n", direction);
  }
  */
  printf("%s", "END OF GAME! HERE IS YOUR PICTURE: \n");
  printArray(floor);
  
  return 0;

}

//print array function definition
void printArray(const int b[50][50]){
  //standard nested for loop to print each column in row i, go down until i < floor size (size - 1 for index)
  for(size_t i = 0; i < floorSide; i++){
    for(size_t j = 0; j < floorSide; j++){
      if(b[i][j] == 0){
        printf(" ");
      } else{
        printf("* ");
      }
    }
    puts(""); //print new line after each row complete
  }
}