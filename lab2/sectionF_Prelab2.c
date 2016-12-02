//Selwyn Ralph
//sjrtrd
//12448280
//Section F Sydney Bates

#include<stdio.h>

int main(void)

{

int num1;
int num2;
int sum;
int multi;

	printf("Enter the first number: ");
	scanf("%d",&num1);

	if(num1<=0) {

		printf("Enter a nonnegative number\n");
		printf("Enter the first number again: ");
		scanf("%d",&num1);
	}

	printf("Enter the second number: ");
	scanf("%d",&num2);

	if(num2<=0) {
		printf("Enter a nonnegative number\n");
		printf("Enter the second number again: ");
		scanf("%d",&num2);
	}
		
puts("Addition");

sum = num1 + num2;

printf("The sum of %d and %d is %d\n",num1,num2,sum);

puts("Multiplication");

multi = num1*num2;

printf("The product of %d and %d is %d\n", num1, num2, multi);

   return 0;



}
