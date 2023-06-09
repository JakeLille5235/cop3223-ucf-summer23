/*
COP3223 Summer 2023 Assignment 1.3
Copyright 2023 Lille_Jake
*/


#include <stdio.h>

int main() {
    int rows; // for # of rows...
    int i; // counting variable for for loop 1 (spaces for upper and lower halves)
    int j; // counting variable for for loop 2 (asterisk for upper and lower)
    int space; // used to calculate how much space to fill


    //prompt user for input, assign integer to rows variable
    printf("Enter an odd number between 1 and 19: ");
    scanf("%d", &rows);

    //legitimacy test to see if number is even or NOT between 1-19, if not return 0 and terminate program!
    if (rows < 1 || rows > 19 || rows % 2 == 0) {
        printf("Invalid input. Please enter an odd number between 1 and 19.\n");
        return 0;
    }

    int midpoint = rows / 2 + 1; // find mid point to separate upper and lower halves to form diamond
                                 // calculated by rows(input)/2 , gives us a value that is ALWAYS rounded down cause
                                 // integer, then +1 to correct that. ie. 7 rows, midpoint is 4. (3.5 -> 3) + 1 = 4



    // executes line by line; spaces print UNTIL asterisks kick in, then after asterisks complete, new row commence
    // Upper half of the diamond
    for (i = 1; i <= midpoint; i++) {
        //while space is <= midpoint -1, print a space character
        for (space = 1; space <= midpoint - i; space++) {
            printf(" ");
        } // this works because after, the asterisks take over and spaces no longer needed for that line
      
        //this for loop kicks in as soon as we hit our needed spaces, then asterisks take over 
        for (j = 1; j <= 2 * i - 1; j++) { // does not execute if 
            printf("*");
        }
        // after the above for loops are satisfied, we print a new line to continue the sequence
        printf("\n");
    }

    // Lower half of the diamond
    // virtually the same exact thing as above, except i starts at midpoint, and we decrement back down i since it's symmetrical
    for (i = midpoint - 1; i >= 1; i--) {
        for (space = 1; space <= midpoint - i; space++) {
            printf(" ");
        }
        for (j = 1; j <= 2 * i - 1; j++) { // literally exact same setup for the asterisk for loop
            printf("*");
        }
        printf("\n");
    }

    return 0;
}
