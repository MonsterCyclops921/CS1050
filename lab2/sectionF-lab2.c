
#include<stdio.h>

int main(void)
{

    int num1;
    int num2;
    int sum;
    int diff;
    int multi;
    float div;


    printf("Enter the first number: "); //first number prompt
    scanf("%d",&num1);

    
    if (num1<= -1 ){  //begining of if statement
    printf("Enter a non-negative number: ");
    scanf("%d",&num1);
        } // end of if statement

    printf("Enter the second number: "); //second number prompt
    scanf("%d",&num2);
    
    
    if(num2<= -1){  // begining of if statement
        printf("Enter a non-negative number: ");
        scanf("%d",&num2);

    } //end of if statement
    
    printf("\n");
   
    puts("ADDITION");
    sum = num1 + num2; // sum operation
    printf("The sum of %d and %d is %d\n\n ", num1, num2, sum);

    puts("SUBTRACION");
    diff = num1 - num2;
    printf("The difference between %d and %d is %d\n\n", num1,num2,diff);
   
    puts("MULTIPLICATION");
    multi = num1*num2; // multiplication operation
    printf("The product of %d and %d is %d\n\n ", num1, num2, multi);

    puts("Division");

    if(num2==0){  // begining of if block
        puts("Cannot divide by zero");
        printf("Enter a number again: ");
        scanf("%d",&num2);
        div = (float)num1/(float)num2;  //division operation
        printf("\n %d divided by %d is %0.2f\n\n ", num1, num2, div);
    }   // end of if block
   
   else { //begining of else block
        div = (float)num1/(float)num2; //division operation
        printf("%d divided by %d is %0.2f\n\n", num1, num2, div);
    } // end of else block


    if (num1>num2) {  //begining of if block
        printf("%d is the bigger number\n",num1);
    }                // end of if block
    else if (num1==num2) {   //begining of else if block
        printf("%d and %d are the same number\n",num1,num2);
    }    // end of else if block
    else { //begining of else block
        printf("%d is the bigger number\n",num2);
    }    // end of else block
    


    return 0;
}
