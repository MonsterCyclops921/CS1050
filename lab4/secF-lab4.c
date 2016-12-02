
#include <stdio.h>
#include <stdlib.h>

int errorCheck(int);
int checkEven(int);
int checkOdd(int);
int checkPrime(int);
int addDigits(int);
int extremeDigits(int);
int smallestLargestSum(int);


int main () // the one fxn to rule them all
{ // begining of main

    int num;
    int sum;
    int extremeSum;
    int largeSmallSum;

    printf("Enter a positive number: ");
    scanf("%d", &num);
   
   if(errorCheck(num) == 0)
   { // beginning of if
     while(errorCheck(num) !=1)
         { // begining of loop
          printf("Error! Enter a positive number only: ");
          scanf("%d",&num);

         } // end of loop
     }// end of if


    if(checkEven(num) == 1)
    { // begining of if
        printf("%d is an Even number\n",num);
       
       if(num == 2)
        { // beginning of if
        printf("%d is a prime number\n",num);
        } // end of if

        else
        printf("%d is not a Prime number\n",num);
     
     } // end of if
    
    if (checkOdd(num) == 1)
    { // beginning of else if
        printf("%d is an Odd number\n",num);
        if( checkPrime(num) == 1)
        { // beginning of if
            printf("%d is a Prime number\n",num);
        } // end of if
        else
            printf("%d is not a Prime number\n",num);     
    } // end of  if

    sum = addDigits(num);
    extremeSum = extremeDigits(num);

    printf("Sum of all the digits of %d is %d\n", num, sum);
   printf("Sum of the product and sum of extreme digits of %d is %d\n", num, extremeSum);

   largeSmallSum = smallestLargestSum(num);

   printf("The sum of smallest and largest digit in %d is %d\n",num, largeSmallSum);
    

    return 0;
   
   } // end of main

    int errorCheck(int num) // checks user input for positive number.
    { // beginning of checkError fxn

         if(num==0 || num<0 )
         { // beginning of if
             return 0;
         } // end of if
    else
        return 1;

    } // end of checkError fxn

    int checkEven(int num) // fxn that checks whether num is even or not
    { // beginning of checkEven fxn

        if(num %2 == 0)
        { // beginning of if 
            return 1;
        } // end of if
        else 
            return 0;
    } // end of checkEven Fxn

    int checkOdd(int num) // fxn that checks if num is odd
    { // beginning of checkOdd
        if(num%2 == 1)
        { // beginning of if
            return 1;
        } // end of if
        else 
            return 0;
    } // end of checkOdd

    int checkPrime(int num) // a fxn that checks if num is prime or not
    { // beginning of checkPrime
       
       int i = 0;
       

      for(i=3 ; i< num / 2; i+=2)
      { // beginning of for loop
          if (num % i == 0)
              return 0;
      } // end of fooooooooooooooooooor loop
        return 1;
    } // end of checkPrime

    int addDigits(int num) // fxn that adds the digits together
     { // begining of addDigits fxn 

        int result = 0;
        
        while (num!= 0)
        { // beginning of loop

            result += num%10;
            num = num/10;

        } // end of loop

        return result;


     } // end of addDigits fxn

    int extremeDigits (int num) // fxn that adds the first and last digit.
    { // beginninf of extremeDigits fxn

    int firstDig = num ;
    int lastDig; 

    lastDig = num % 10;

    while (firstDig >=10)
    { // beginning of loop

        firstDig = firstDig/10;

    } // end of loop
    
    return ((firstDig * lastDig) + (firstDig + lastDig));

    } // end of extremeDigits fxn

    int smallestLargestSum (int num) // fnx that adds the smallest and largest digits
    { // begining of fxn

   int lDigit;
   int sDigit;
   int  large = 0;
   int  small;
   int n;
   
   n = num;
   
   while (n>0)
    { // begining of loop
        lDigit = n%10;

        if(lDigit > large)
        {// begin of if
            large = lDigit;
        } // end of if

        n = n / 10;
    } // end of loop
   
   n = num;
   
   while (n >0)
    {
    
    sDigit = n % 10;
    if (sDigit ==0)
    {
        small = 0;
    }
    if( sDigit <= small)
    {
        small = sDigit;
    }
    
    n = n / 10;
    }
    printf("small: %d large: %d\n ", small, large );
    return ( small + large);

    } // end of fxn

