#include <stdio.h>

int main() {

  //initialize variables, setting to 0. 
  int count = 0;
  int sum = 0;

  while(count <= 1000){ //simple while loop, increment count each iteration to avoid infinite loop...
    if(count % 2 == 0 && count % 3 == 0){ // conditional statement, utilize && to make sure BOTH conditions are met in order to add sum
    // again, instructions stated looking for even numbers (count % 2 == 0), and those divisible by 3 (count % 3 == 0). BOTH have to be true
      sum = count + sum;
    } //no need for else or any of that, iteration will just increment count, then loop back again to check conditions

    count++;
  }

  printf("%d", sum);
    return 0;
}
