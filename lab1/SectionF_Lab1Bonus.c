//Selwyn Ralph
//sjrtrd
//12448280
//Lab 1 Bonus
//Section F Sydney
#include <stdio.h>

int main (void)// Main Function

{
	float miles;
	float dist; 
	float speed;
	float newSp;
	float  time;

	printf("Bonus Part\n");

	printf("\nEnter the distance:  ");
	scanf("%f",&miles);

	if(miles<=0) {
		printf("Distance should be a positive number\n");
		printf("Enter the distance again: ");
		scanf("%f",&miles);
		}

	printf("Enter the speed: ");
	scanf("%f",&speed);

	if(speed<=0) {
		printf("Speed should be a positive number\n");
		printf("Enter the speed again: ");
		scanf("%f",&speed);
	}


	dist = miles/1600;

	

	time = (dist/speed)*3600;

	printf("Flight time of the plane is %f seconds\n", time);



	return 0;
}

