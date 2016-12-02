#include <stdio.h>
#include <stdlib.h>


void displayFun ();
int getNum();
int areaSquare (int b);

int main()
{

     int choice;
     int length;
     float radius;

     displayFun();

     printf("Please make a selection (1-3): ");
     scanf("%d", &choice);

     while(choice <=0 || choice >=4)
     {
         puts("Invalid selection");
         printf("Please make a selection between 1 and 3: ");
         scanf("%d", &choice);
     }


     if(choice == 1)
     {
         length = getNum();
         printf("%d\n",length);
         printf("The area is %d\n", areaSquare(length));
     }



return 0;

}

void displayFun ()
{
    puts("Area Calculation");
    puts("(1) Square");
    puts("(2) Cube");
    puts("(3) Circle");


}

int getNum( )
{
    int num1;
    printf("Enter a positive integer: ");
    scanf("%d",&num1);
    if(num1<0)
    {
        while(num1<0)
        {
            puts("Incorrect value");
            printf("Enter positive values only: ");
            scanf("%d", &num1);
        }
    }

    return num1;
}


int areaSquare (int x)
{
    return x*x;
}
