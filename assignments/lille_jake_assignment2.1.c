/*
COP3223 Summer 2023 Assignment 2.1
Copyright 2023 Lille_Jake
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

enum difficulty {EASY, MEDIUM, HARD}; //use enum for selecting difficulty level; could've used a basic if/else but want to start utilizing enum to develop the habit


//main function; opted to just keep all code here rather than 'divide and conquer' for something this simple
int main(void) {
  enum difficulty level; //init into 'object' level so we can see difficulty
  srand(time(NULL)); // feed the seed system time so it's true random, not psuedorandom

  //initialize vars for userGuess (user's number guess) and the random integer
  int randomInteger = 0;
  int userGuess = 0;
  
  for(int i = 1; i != -1; i++){ //for loop to continue playing game until user ends
    printf("Let's play Guess the Number! Round %d...\n", i); //opening message, round number = loop counter

    //do, need to have this run ONCE first to determine difficulty and make sure user enters correct value
    do{
    printf("%s", "Enter difficulty (0 = EASY), (1 = MEDIUM), (2 = HARD): ");
    scanf("%d", &level); //this sets the level of difficulty by directly selecting it and storing in var
    } while (level != 0 && level != 1 && level != 2); //do while loop to test for correct input; do so that         way it runs once to set variable


    //conditionals to test for difficulty and supply random number in appropriate range (1-10; 1-100; 1-1000)
    if(level == 0){
      randomInteger = 1 + (rand() % 10);
      //printf("%d", randomInteger); this was to make sure numbers were in range and program works
    } else if(level == 1){
      randomInteger = 1 + (rand() % 100);
      //printf("%d", randomInteger);
    } else {
      randomInteger = 1 + (rand() % 1000);
      //printf("%d", randomInteger);
    }

    for(int j = 0; j < 8; j++){ //for loop to max out 8 guesses on number
      printf("%s", "Enter Guess: ");
      scanf("%d", &userGuess);

      //conditional to test if guess is equal to randomInteger
      if(userGuess == randomInteger){
        printf("%s", "You got the number! ");
        break;
      } else if (userGuess != randomInteger){ //not equal to the right value...
          if(j != 7){ //nested if/else to see if attempts are left or not, change print message
            if(userGuess > randomInteger){ //nested if to tell if higher or lower
              printf("Your answer is too HIGH! %d tries left. ", 7-j); //7-j because we start at 0
            } else if(userGuess < randomInteger){
              printf("Your answer is too LOW! %d tries left. ", 7-j);
            }
          }
          else{
            printf("Tries exhausted! Number was %d. ", randomInteger);
        
        }
      } else {
        return 0;
      }
    
    }
      int continueGame = 0; //continueGame var to ask user and store + test value
      printf("%s", "Round Over! Continue (0 no, any other number yes)");
      scanf("%d", &continueGame); //store variable...
      if(continueGame == 0){ //if 0, end game (ie. return 0)
        return 0;
      }
  
    }
  
  return 0;
}