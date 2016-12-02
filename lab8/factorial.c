#include<stdio.h>


int errorCheck(int num)
{ // beginning of error check fxn
    if(num<1)
        return 0;
    else
        return 1;


} // end of error check fxn

int main()
{ // beginning of main fxn

int num, i;
int factorial = 1;

do { // beginning of dowhile loop
printf("Enter a positive interger: ");
scanf("%d", &num);
} // end of do while loop
while(errorCheck(num) !=1);

for(i = 1; i<=num; i++)
{ // beginning of for loop
factorial = factorial * i;
} // end of for loop

printf("\n%d! = %d\n", num, factorial);


return 0;



} // end of main fxn
