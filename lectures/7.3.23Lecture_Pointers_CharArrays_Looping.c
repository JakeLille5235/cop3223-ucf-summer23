#include <stdio.h>

int main(void){
    // use char 2d array to store string
    // Row = # of strings
    // Column = max # of chars per string (can be empty, just not less)
    char mood[3][10] = {"Happy", "Friday", "Rest"};


    printf("%s\n", mood[1]);
    printf("size of mood array is: %zu", sizeof(mood));

    // Arrays w. Pointers to store & access strings...
    char *cPtr[3] = {"Happy", "Friday", "Rest"};
    printf("\n%s", cPtr[2]);
    printf("\nsize of ptr array is: %zu", sizeof(cPtr)); //size of pointer * 3
/*
    for(int i = 0; i < 3; i++){
        printf("\n%c", cPtr[i]);

        int size = sizeof(cPtr[i]);
        for(int j = 0; cPtr[i][j] != '\0'; j++){
            printf("%c ", cPtr[i][j]);
        }
        puts("");
    }   
    */
   printf("\n%s", *cPtr); // OFFSET = +i if using dereference and not index
   for(int i = 0; i < 3; i++){
        printf("String is: %s\n", *(cPtr + i));
        puts("---");
        for(int j = 0; (*(cPtr+i))[j] != '\0'; j++){
            printf("%c ", (*(cPtr+i))[j] ); // Get address first + i to point to row. Then, j dictates which element in that row to point to
            // ie 1st iteration of i loop (0) -> points to 1st string address, then dereferences; j increments, going down row of elements (characters)
        

            // MORE SIMPLE way to do the same thing...
            // *(cPtr[i] + j) <- sets row element (ex. 100) address, then add j (column value to get address of row + column), then dereference for value
        }
   }
}