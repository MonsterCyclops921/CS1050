
#include <stdio.h>
#include <stdlib.h>
int checkError(int);
void initializeArray(int [], int);
void printArray (int [], int);

int main()
{ // begining of main

int myArr1 [100] = {0};
int myArr2 [100] = {0};
int input;


printf("Enter the size of the input: ");
scanf("%d",&input);


if(checkError(input) == 0)
{ // begining of if
    while(checkError(input) !=1)
    { // begining of while loop
        printf("Invalid input enter the size of the input again: ");
        scanf("%d",&input);
    } // end of loop
} // end of if

initializeArray(myArr1, input);

puts("Input Array 1");
printArray(myArr1, input);
printf("\n\n");

puts("Input array 2");
initializeArray(myArr2, input);
printArray(myArr2, input);


printf("\n");
return 0;

 } // end of main

int checkError(int input) // fxn that checks to see if number correct
{ // begining of checkError fxn
    if(input <= 1 || input >= 100)
    { // begining of if
        return 0;
    } // end of if
    
    else 
        return 1;
} // end of checkError fxn. 

void initializeArray(int myArr[], int input) // fxn that puts the input elements into the array. 
{ // begining of array fxn.
   int i;
   for(i = 0; i<input; i++)
   { // beginning of loop
    myArr[i] = rand() % 10;
   } // end of loop

} // end of array fxn

void printArray(int myArr[], int input) // prints the array
{ // begining of printArray
    int i;

   
   for(i = 0; i <input; i++)
    { // begining of inner for loop
        printf("%2d", myArr[i]);
    } // end of inner for loop




} // end of printArray



