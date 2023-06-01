/*
COP3223 Summer 2023 Assignment 1.1
Copyright 2023 Lille_Jake
*/

#include <stdio.h> //standard library to utilize common functions...

int main(void){ //main function...

    //declare variables... like to get it out of the way and do it first hand here
    int hoursWorked;
    float hourlyRate; //float so can be decimal
    float salary;

    // prompt user for input...
    printf("Enter # of hours worked (-1 to end): ");
    //scan for user input, %d for integer, storing in variable hoursWorked via. '&'
    scanf("%d", &hoursWorked);

    while(hoursWorked != -1){  //while loop will run as long as condition true, so when user enters -1 to quit (false), loop ends
        //already asked for first iteration, so we go straight to prompt for salary

        //prompt for rate input, scan for float and put & into hourlyRate
        printf("\nEnter hourly rate of the worker ($00.00): ");
        scanf("%f", &hourlyRate);

        //conditional statemment to adjust rate for straight pay and time and 1/2 pay
        if(hoursWorked <= 40){
            salary = hoursWorked * hourlyRate; // 40 and under, straight pay rate arithmetic
        } else if(hoursWorked > 40){ //else if to test if greater than 40, honestly else would work but like to be thorough just in case
            salary = 40*hourlyRate + ((hoursWorked-40)*hourlyRate*1.5); //we know at least 40, so 40 * straight pay, then extra hours (hours-40) multiplied by 1.5
        }

        //print salary (float)
        printf("\nSalary is %f\n", salary);

        //make sure to include this again for the loop, as initial statement is outside
        printf("Enter # of hours worked (-1 to end): ");
        scanf("%d", &hoursWorked);
    }

    return 0;
}