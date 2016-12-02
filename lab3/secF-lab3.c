// Selwyn Ralph
// sjrtrd
// 12448280
// Lab 3 - Section F
// Purple

#include <stdio.h>
#include <math.h>


int main()
{ // main begins

float amntCi;
float amnt;
int year;
float terEarn;
int choice;


while(choice<=0 || choice>=4)
{ // loop begins
    puts("Bank account Type");
    printf("\n");
    puts("(1) Checking");
    puts("(2) Saving");
    puts("(3) Fixed Deposit");

    printf("Please make a selection: ");
    scanf("%d",&choice);
    
    if(choice<=0 || choice>=4)
    { // if begins
        puts("Incorrect choice, please make a choice again");
        printf("\n");
    } // if ends
} // loop ends

switch(choice)

    { // switch begins 

    case 1:
    { // case 1 begins
    
    printf("Enter the amount: ");
    scanf("%f",&amnt);
    
    while(amnt<=0)
    { // loop begins
        printf("Incorrect value, enter the amount again: ");
        scanf("%f",&amnt);
    } // loop ends

    printf("Enter a year: ");
    scanf("%d",&year);

    while(year<=0 || year>=11)
     {  // loop begins
        printf("Incorrect value, year should be between 1-10\n");
        printf("Enter a year: ");
        scanf("%d",&year);
     } // loop ends
   

   amntCi = amnt * pow((1+0.01),year);
   terEarn = amntCi - amnt;

   printf("Total amount after %d years is %.2f\n",year,amntCi);
   printf("Total interest earned on the amount %.2f is %.2f\n",amnt,terEarn);

   break;
   
    
   } // case 1 ends

   case 2:
   { // case 2 begins

    printf("Enter the amount: ");
    scanf("%f",&amnt);
    
    while(amnt<=0)
    { // loop begins
        printf("Incorrect value, enter the amount again: ");
        scanf("%f",&amnt);
    } // loop ends

    printf("Enter a year: ");
    scanf("%d",&year);

    while(year<=0 || year>=11)
     {  // loop begins
        printf("Incorrect value, year should be between 1-10\n");
        printf("Enter a year: ");
        scanf("%d",&year);
     } // loop ends
   

   amntCi = amnt * pow((1+0.03),year);
   terEarn = amntCi - amnt;

   printf("Total amount after %d years is %.2f\n",year,amntCi);
   printf("Total interest earned on the amount %.2f is %.2f\n",amnt,terEarn);

   break;
   
   } // case 2 ends

    case 3:
    { // case 3 begins


    printf("Enter the amount: ");
    scanf("%f",&amnt);
    
    while(amnt<=0)
    { // loop begins
        printf("Incorrect value, enter the amount again: ");
        scanf("%f",&amnt);
    } // loop ends

    printf("Enter a year: ");
    scanf("%d",&year);

    while(year<=0 || year>=11)
     {  // loop begins
        printf("Incorrect value, year should be between 1-10\n");
        printf("Enter a year: ");
        scanf("%d",&year);
     } // loop ends
   

   amntCi = amnt * pow((1+0.07),year);
   terEarn = amntCi - amnt;

   printf("Total amount after %d years is %.2f\n",year,amntCi);
   printf("Total interest earned on the amount %.2f is %.2f\n",amnt,terEarn);

   break;

    } // case 3 ends



 } // switch ends












    return 0;
} // end of main
