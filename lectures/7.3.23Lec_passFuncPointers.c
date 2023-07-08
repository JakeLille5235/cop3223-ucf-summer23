// Ex. Referencing functions and calling via. Pointers

#include <stdio.h>

// function name is starting address in memory for block of code
// a pointer to function contains address of function in memory
// pass pointer of function to another function, typically for MENU DRIVEN systems

int add(int num1, int num2);
int sub(int num1, int num2);
int math(int num1, int num2, int(*action)(int a, int b));


int main(void){
    int a = 8;
    int b = 5;
    int result = 0;
    int action = 0;

    printf("input value: 1 = add, 2 = sub: ");
    scanf("%d", &action);

    if(action == 1){
        result = math(a,b, add);


    } else if(action ==2){
      result =  math(a, b, sub);
    }

  printf("Result: %d", result);
}       

int math(int num1, int num2, int(*action)(int a, int b)){
  int result = 0;
  result = ((*action)(num1, num2)); //add num1 + num2
  return result;
}

int add(int num1, int num2){
    return num1+num2;
}

int sub(int num1, int num2){
    return num1-num2;
}