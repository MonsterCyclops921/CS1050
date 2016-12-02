// Selwyn Ralph
// sjrtrd
// 12448280
// Section F sydney bates
// bagels


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 100


int checkError(int);
void initializeArray(int [], int);
void printArray (int [], int);
int max(int[], int);
int min(int[], int);
float average(int[], int);
int countNumbers(int[], int, int);
int commonNumbers(int [], int [], int);


int main()
{ // beginnint of main

int myArr1 [SIZE] = {0};
int myArr2 [SIZE] = {0};
int input;
int num;


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

srand(time(NULL));
initializeArray(myArr1, input);

puts("The first input array");
printArray(myArr1, input);
printf("\nThe maximum number is present at the index location %d\n", max(myArr1, input));
printf("\nThe minimum number is present at the index location %d\n", min(myArr1, input));
printf("\nThe average of numbers in the first array is %.2f\n", average(myArr1,input));

printf("\n\n");




puts("Input array 2");

srand(rand()%10);
initializeArray(myArr2, input);
printArray(myArr2, input);
printf("\nThe maximum number is present at the index location %d\n", max(myArr2, input));
printf("\nThe minimum number is present at the index location %d\n", min(myArr2, input));
printf("\nThe average of number in the second array is %.2f\n", average(myArr2, input));

printf("Enter a number: ");
scanf("%d",&num);

printf("\nThe count of number %d in the first array is %d\n", num, countNumbers(myArr1, input, num));

printf("\nThe count of number %d in the second array is %d\n", num, countNumbers(myArr2, input, num));

printf("\nThe number of common numbers in the two arrays: %d\n", commonNumbers(myArr1, myArr2, input));






return 0;
} // end of main



int checkError(int input) // fxn that checks to see if number correct
{ // begining of checkError fxn
    if(input < 1 || input > 100)
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
   printf("\n");
} // end of printArray

int max(int myArr[], int input)
{ // beginning of max fxn
    int i;
    int mResult = 0;
    int mIndex;

         for(i = 0; i<input; i++)
          { // beginning of loop
             if(myArr[i] > mResult)
             { // beginning of if
                 mResult = myArr[i];
                 mIndex = i;
             } // end of if
          } // end of loop

          return mIndex;
} // end of max fxn


int min(int myArr[], int input)
{ // beginning of min function
   int i;
   int minRes;
   int minIndex;

   for(i = 0; i<input; i++)
   { // beginning of loop
     if (myArr[i] < minRes)
        { // beginning of if
          minRes = myArr[i];
          minIndex = i;
        } // end of if
   } // end of loop
   return minIndex;
} // end of min fxn


float average(int myArr[], int input)
{ // beginning of average fxn

    int i;
    float sum = 0;

     for (i = 0; i<input; i++)
     { // beginning of for loop
        sum = sum + myArr[i];
     } // end of loop

                                

   return (sum/input);
} // end of average fxn


int countNumbers(int myArr[], int input , int num)
{ // beginning of countNumbers fxn

    int i;
    int count = 0;
    
    for(i = 0; i<input; i++)
    { // beginning of for loop
        if(myArr[i] == num)
        { // beginning of if
            ++count;
        } // end of if

    } // end of for loop
    
    return count;
} // end of countNumbers fxn

int commonNumbers( int myArr1[], int myArr2[], int input)
{ // beginning of commonNumbers fxn
int i;
int count;
    
    for(i = 0; i<input; i++)
    { // beginning of for loop

        if(myArr1[i] == myArr2[i])
        { // beginning of if 
            count++;
        } // end of if

    } // end of for loop
    
    return count;
} // end of commonNumbers fxn

