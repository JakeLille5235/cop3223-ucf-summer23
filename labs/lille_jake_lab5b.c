/*
COP3223 Summer 2023 Assignment 2.3
Copyright 2023 Lille_Jake
*/

#include <stdio.h>

#define ARRAY_SIZE 20 //define ARRAY_SIZE to be 20

int main() {
    int numbers[ARRAY_SIZE]; //initialize array that is ARRAY_SIZE (20)
    int count = 0; //init count var for duplicate counter to display at end (additional feature)
    int i, j; // init for loop variables; do this out of practice to make accessible outside loop scope
    int duplicate; // duplicate init - acts as boolean basically: 0 = not duplicate, 1 = duplicate
  
    printf("Enter 20 numbers between 10 and 100:\n"); //prompt user to enter input

    //loop to retrieve 20 vars; < ARRAY_SIZE (20), start @ 0 so full 20
    for (i = 0; i < ARRAY_SIZE; i++) {
        scanf("%d", &numbers[i]); //store input into appripriate array index (separated by space)
    
        // Check for duplicates
        duplicate = 0; //duplicates set to 0
        for (j = 0; j < i; j++) { //nested for loop, j less than i iteration searches through already inputed values
            if (numbers[i] == numbers[j]) { //if conditional to compare current numbers[i] to previous numbers[j]
                duplicate = 1; //duplicate set to 1 if duplicate
                break; 
            }
        }
    
        // Print the number if it's not a duplicate
        if (!duplicate) { //if NOT duplicate (non-zero truthy, zero falsey; prints truthy)
            printf("%d\n", numbers[i]);
            count++; //increment count for last message
        }
    }
  
    printf("Total unique numbers entered: %d\n", count); //print count of duplicate values
  
    return 0;
}
