/*
COP3223 Summer 2023 Lab2B
Copyright 2023 Lille_Jake
*/

#include <stdio.h>

int main(void){

    //print out column headers, then start a for loop to go column by column for each iteration, then new line
    printf("N\t10*N\t100*N\t1000*N\n");
    
        for(int i = 1; i < 11; i++){ //increments after as ++ is after i variable, so must init at 1
            //declare variables to conduct arithmetic
            int tenTimes = i*10;
            int hundredTimes = i*100;
            int thousandTimes = i*1000;

            //go about by each column first, then separate printf statement for new line
            printf("%d\t", i);
            printf("%d\t", tenTimes);
            printf("%d\t", hundredTimes);
            printf("%d\t", thousandTimes);
            printf("\n");
        }

    return 0; // good practice, even though we passed 'void' into the main function, want to get in habit
              // of returning 0


}