/*
COP3223 Summer 2023 Lab4B
Copyright 2023 Lille_Jake
*/

#include <stdio.h>
#include <math.h> // need this for sqrt() and pow()

double distance(double x1, double x2, double y1, double y2); // function prototype, all vars to doubles


//main function to prompt user for points and call distance function
int main(void) {
  //need to declare variables in main as they are local in distance function
  double x1, x2, y1, y2;

  //prompt user for each set of points, assign via. scanf. %lf for double type
  printf("%s", "Enter set 1 x and y-values: ");
  scanf("%lf %lf", &x1, &y1);

  printf("%s", "Enter set 2 x and y-values: ");
  scanf("%lf %lf", &x2, &y2);

  //create a double variable for result to easily print
  double result = distance(x1,x2,y1,y2); // this is where we CALL the function, add to stack
  printf("%lf", result); // print result
  
  return 0; // return 0, successful termination of program and back to operating system stack
}

//function definition
double distance(double x1, double x2, double y1, double y2){
  return sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2)); //utilize the distance between two points formulas
  //make sure to have order of operations correct; utilize the pow() function for exponents, sqrt for square root
}