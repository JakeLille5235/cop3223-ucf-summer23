#include <stdio.h>
#include <math.h>

int main(void){
  double initialInvestment = 0.0;
  double interestRate = 0.0;
  int years = 0;

  double interest = 0.0;
  double total = 0.0;

  printf("%s", "Initial Investment: ");
  scanf("%lf", &initialInvestment);

  printf("%s", "\nInterest Rate: ");
  scanf("%lf", &interestRate);

  printf("%s", "\nYears: ");
  scanf("%d", &years);

  printf("%4s%21s\n", "Year", "Amount on Deposit");
  for(int y = 0; y <= years; y++){
    interest = initialInvestment * pow((1+interestRate), y);
    printf("%-4d %21.2f\n", y, interest); //%21 for spacing to match the 21 characters spacing in the header, .2f for rounding to two decimals
  } 



}
