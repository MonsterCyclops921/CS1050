// Selwyn Ralph
// sjrtrd
// 12448280
// Sydeny Bates Section F
// Election #2016

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int checkSize(int size) // fxn that error checks the size provided by the user
{ // beginning of error check
    if(size>100 || size<=0)
     return 0;
     else
         return 1;
} // end of error check

void initializeArray(int *iPntr, int size) // fxn that puts the input elements into the array.
{ // begining of initialize fxn.
   int i;

      for(i = 0; i<size; i++)
         { // beginning of loop
             *(iPntr + i) = (rand() % 5) + 1;
         } // end of loop

} // end of intitialize fxn

void printArray(int *iPntr, int size) // prints the array
{ // begining of printArray
    int i;
    int count = 0;

    for(i = 0; i <size; i++)
    { // begining of inner for loop
         if(count==10)
         { // beginning of
             printf("\n");
             count = 0;
         } // end of if
     printf("%2d", *(iPntr + i));
     count++;
  } // end of inner for loop
  printf("\n");

} // end of printArray

void sortArray(int *iPntr, int size) // fxn that sorts the array pntr
{ // beginning of sort fxn
    int i, j;
    int temp = 0;

    for(i = 0; i<size; i++)
    { // beginning of outer for loop
        for(j = i + 1; j<size; j++)
        { // beginning of inner for loop
            if(*(iPntr+i)>*(iPntr + j))
            { // beginning of if statement
                temp = *(iPntr+i);
                *(iPntr+i) = *(iPntr+j);
                *(iPntr+j) = temp;
            } // end of if statement
        } // end of inner loop
    } // end of outer loop
} // end of sort fxn

float median(int *iPntr, int size)
{ // beginning of fxn
    int hold = 0; 
    float mid = 0;
    
    sortArray(iPntr, size);
    if(size%2!=0)
    { // beginning of first if
        hold = size/2;
        mid = *(iPntr+hold);
    } // end of first if

    if(size%2==0)
    { // beginning of second if statement
        hold = size/2;
        mid = (*(iPntr + hold) + *(iPntr + hold -1));
        mid = mid/2;
    } // end of second if statement
    return mid;
} // end of fxn


int main()
{ // beginning of main
    int *iPntr;
    int size;
    float mitjana;

    printf("Enter the size of the input: ");
    scanf("%d", &size);

     while(checkSize(size)!=1)
     { // beginning of while loop
         printf("Invalid input enter the size of the array between 1 - 100: ");
         scanf("%d", &size);
     } // end of while loop

     iPntr = malloc(sizeof(int)*size);
     srand(time(NULL));

     initializeArray(iPntr,size);
    
     printf("\nInput Array\n");
     printArray(iPntr, size);
    
    mitjana = median(iPntr, size);

     printf("\nSorted Array\n");
     printArray(iPntr, size);

    printf("\nThe Median of the array is %.2f\n", mitjana);

    



     return 0;
} // end of main

