/*
COP3223 Summer 2023 Assignment 2.3
Copyright 2023 Lille_Jake
*/

#include <stdio.h>
//#include <stdlib.h>


enum classSelect {ECONOMY, FIRST}; 

//for while loop later, max seats to be assigned are 6
#define MAX_SEAT 6



//loop starts here, max capacity of 6 seats, so after 6 filled, print a message to say all booked
//print to prompt user for selection, scan, and set enum for that iteration of program to whatever class


//main function; in hindsight, divie and conquer would've been better (multiple functions)
int main(void) {
  int seatChart[6] = {0,0,0,0,0,0}; // array for seat chart 0-5, init all vals as 0 or empty
  int fairSelect = 0; //1 = first, 2 = econ
  int count = 1; // for while loop
  enum classSelect seat;
  int ecoFull = 0; //1 = full, 0 not full
  int firstFull = 0; // 1 full, 0 not full, used with ecoFull, if both == 1, flight leaves in 3 hours plane full
  int countForBookEcon = 0; 

  
  //welcome message
  printf("%s", "Welcome to Lille Airlines!\n");

  //while loop, while count <= max seats OR if user does not select NO (0)
  while(count <= MAX_SEAT || fairSelect != 0){
    printf("%s", "Type '1' for 'FIRST CLASS'\nType '2' for ECONOMY: "); //prompt user
    scanf("%d", &fairSelect); //store var

    //switch statement, not the most efficient way I came to find 
    switch(fairSelect) {
      case 1 : // first
        seat = FIRST; //set enum status to first
        int countForBook = 0; // init var for 0, once it hits val = full for loop
        int userFeed = 2; //var for user choice; 1 = other class if full, 0 = end program
        
        //for loop to sort through array
        for(size_t i = 0; i <= 2; i++){
          countForBook = i; // count follows loop to know when full
          //nested if for checking array for full or not
          if(seatChart[i] == 0){
            
            seatChart[i] = 1; //modify array value to now full
            printf("First class booked at seat %d!\n",     (int)i+1);
            i = 5; // cancels this for loop as we've assigned value
            
           // printf("count: %d\n", countForBook);   used this to make sure count was in right scope

            //count starts 0, once it's 2 (or maxed seat), section is full
          } else if(countForBook == 2) {
            printf("%s", "Sorry! First class is booked. Type '1' for Economy, '0' to end: ");
            scanf("%d", &userFeed); //get user's answer
            if(userFeed == 0){
              printf("%s", "Next flight in 3 hours.\n");
              return 0; //end
            } //else if(userFeed==1){
              //tried running a new loop but issues with writing over array, so just goes back to menu prompt
           // }
            i = 5; //end loop
            firstFull = 1; //set first class to full variable
            //check if first and eco full to print message, also in other statemnt
              if(ecoFull == 1 && firstFull ==1){
                printf("%s", "\nSorry, plane full! \nNext flight in 3 hours. ");
                return 0;
              }
            count--; //decrement so a failed attempt doesn't add to the overall count of program, make user select different option or else will always just keep spitting "first class booked"
          }
        }
        break;
      
      //basically same as other, just vice versa
      case 2 :
        seat = ECONOMY;
        int countForBookEcon = 0;
        userFeed = 2; //var for user choice; 1 = other class if full, 0 = end program (re-init to avoid answer)
        for(size_t j = 3; j <= 5; j++){ //make sure to assign for correct seat positons
          countForBookEcon = j;
          if(seatChart[j] == 0){
            
            seatChart[j] = 1;
            printf("Economy class booked at seat %d!\n",     (int)j+1);
            j = 10;
            
            //printf("count: %d\n", countForBookEcon);
          } else if(countForBookEcon == 5) {
            printf("%s", "Sorry! Economy class is booked. Type '1' for First Class, '0' to end: ");
            scanf("%d", &userFeed);
            if(userFeed == 0){
              printf("%s", "Next flight in 3 hours.\n");
              return 0;
            } //else if(userFeed==1){
              //fairSelect = 1;
            //}
            j = 10;
            ecoFull = 1;
              if(ecoFull == 1 && firstFull ==1){
                printf("%s", "\nSorry, plane full! Next flight in 3 hours. ");
                return 0;
              }
            count--;
        break;
            
    }

    
  }
//      case space0 == BOOKED && space1 == BOOKED1 :
        
count++; //count incrementer
 }

}
    printf("%s", "\nEverything booked. Sorry! ");  
  
  return 0; // success, terminate
}
  

