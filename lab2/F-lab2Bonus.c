#include<stdio.h>

int main(void)

{

    int num1;
    int num2;
    int sum;
    int diff;
    int multi;
    float div;

   printf("Enter the first number: "); // first prompt for number
   scanf("%d",&num1);
   
   if(num1<=-1) { // begining of if block
        while(num1<=-1){ // beginging of loop block
            printf("Enter a non-negative number: ");
            scanf("%d",&num1);
        }  // end of loop
     } // end of if block
   
   printf("Enter the second number: ");
    scanf("%d",&num2);

   if(num1<=-1) { // begining of if block
       while(num2<=-1) { // begining of loop
           printf("Enter a non-negative number: ");
           scanf("%d",&num2);
       } // end of loop
   }  // end of if block
    printf("\n");

    puts("ADDITION");
    sum = num1 + num2; // sum operation
    printf("The sum of %d and %d is %d\n\n",num1,num2,sum);

    puts("SUBTRACTION");
    diff = num1 - num2; // difference operation
    printf("The difference between %d and %d is %d\n\n",num1,num2,diff);

    puts("MULTIPLICATION");
    multi = num1*num2; // multiplication operation
    printf("The product of %d and %d is %d\n\n",num1,num2,multi);

    puts("DIVISION");
    if(num2==0) { // begining of if block
        while (num2==0){ // begining of loop
            puts("Cannot divide by zero");
            printf("Enter a number again: ");
            scanf("%d",&num2);
        } // end of loop
            div = (float)num1/(float)num2;
            printf("\n %d divided by %d is %0.2f\n\n",num1,num2,div);
   } // end of if block
    else {
        div = (float)num1/(float)num2;
        printf("%d divided by %d is %0.2f\n\n",num1,num2,div);
    }


    if (num1>num2) {
        printf("%d is the bigger number\n",num1);
    }
    else if (num1==num2) {
        printf("%d and %d are the same number\n",num1, num2);
    }
    else {
        printf("%d is the bigger number\n",num2);
    }

        






















































    return 0;
} 
