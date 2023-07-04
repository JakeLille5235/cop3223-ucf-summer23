#include <stdio.h>

#define SIZE 20

void sortArray(int b[]);
int binarySearch(const int b[], int key, int low, int high);
void printArray(const int b[]); // not modifying array, not returning just printing;

int main(void){
  int a[SIZE] = {4, 5, 6, 7, 1, 5, 7, 8, 9, 5, 3, 4, 1, 5,3,6,7,9,3,1};

  int key;

  sortArray(a);
  printf("%s", "SORTED ARRAY: \n");
  puts("===========");  
  printArray(a);
  puts("===========\n");  

  printf("Enter key: ");
  scanf("%d", &key);

  int result = binarySearch(a, key, 0, SIZE-1);
  if(result == -1){
    printf("NOT FOUND!");
  } else {
    printf("\nResult found: %d", result);
  }
  
}

void sortArray(int b[]){
    for(int pass = 1; pass < SIZE; ++pass){
      for(size_t i = 0; i < SIZE-1; ++i){
        if(b[i] > b[i+1]){
          int hold = b[i];
          b[i] = b[i+1];
          b[i+1] = hold; 
        }
      }
    }
  }


int binarySearch(const int b[], int key, int low, int high){
  while(low <= high){
    size_t middle = (low + high) / 2;

    if(key == b[middle]){
      return middle;
    } else if(key < b[middle]){
      high = middle -1;
    } else{
      low = middle + 1;
    }
  }
  return -1;
}

void printArray(const int b[]){
  for(int i = 0; i < SIZE; i++){
    printf("%d ", b[i]);
    if((i+1)%5 == 0 && i){
      puts("");
    }
  }
}