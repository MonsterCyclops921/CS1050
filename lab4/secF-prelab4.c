#include <stdio.h>
#include <stdlib.h>

int checkError(int);
int checkEven(int);
int checkOdd(int);
int addDigits(int);

int main()
{ // begin of main

int num;
int sum;

printf("Enter a positive number: ");
scanf("%d",&num);

num = checkError(num); // call check error

printf("%d\n",num);

checkEven(num); // call checkEven

checkOdd(num); // call checkOdd

sum = addDigits(num); // call addDigits

printf("Sum of all the digits is %d\n",sum);

return 0;

} // end of main


int checkError (int num)
{ // begin of checkError

  while(num<0)
  { // begin of loop
      printf("Error! Enter a positive number only: ");
      scanf("%d", &num);

  } // end of loop

  return num;
}

int checkEven(int num)
{ // begin of checkEven
    if(num%2 == 0)
    { // begin of if
        printf("%d is an Even Number\n",num);
    } // end of if1

     return 0;
} 

int checkOdd (int num)
{ // begin of checkOdd
    if (num%2 == 1)
    { // begin of if
        printf("%d is an Odd Number\n", num);
    } // end of if
    return 0;
} 

int addDigits(int num)
{ // begin of addDigits
   int result = 0;
    while(num != 0)
    { // begin of loop
        result += num%10;
        num = num/10;
    } // end of loop

    return result;
} // end of addDigits


