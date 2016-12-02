#include <stdio.h>


int main()
{ // beginning of main
   float radius;
   float length;
   int choice;


   while(choice<=0 || choice>=4)
   {  // beginning of error check loop for user choice prompt
   puts("Area Calculation");
   puts("(1) Square");
   puts("(2) Cube");
   puts("(3) Circle");

   printf("Please make a selection: ");
   scanf("%d",&choice);

   if(choice<=0 ||  choice>=4)
        { // beginning of if statement for incorrect choice
            puts("Incorrect choice");
            puts("\n");
        } // end of if statement

   } // end of error check loop for choice prompt

    switch(choice)
    { //beginning of switch

    case 1:
        { // beginning of case 1
            printf("Enter a positive value: ");
            scanf("%f",&length);

            while(length<=0)
            {  // beginning of error check loop
                puts("Number can not be a negative value or zero");
                printf("Enter a positive number: ");
                scanf("%f",&length);
            }  // end of error check loop

            printf("The length of the side of the square is %.0f\n",length);
            printf("Area of the square is %.0f\n", length*length);
            break;
        } // end of case 1

    case 2:
        { // beginning of case 2
            printf("Enter a positive value: ");
            scanf("%f",&length);

            while(length<=0)
            {  // beginning of error check loop
             puts("Number can not be a negative value or zero");
             printf("Enter a positive number: ");
             scanf("%f",&length);
            }  // end of error check loop
          printf("The length of the side of the cube is %.0f\n",length);
          printf("The area of the cube is %.0f\n", 6*length*length);
          break;
        } // end of case 2

    case 3:
        { // beginning of case 3
            printf("Enter a positive value: ");
            scanf("%f",&radius);

            while(radius<=0)
            { // beginning of error check loop
                puts("Number can not be a negative value or zero");
                printf("Enter a positive number: ");
                scanf("%f",&radius);
            } // end of error check loop

            printf("The radius of the circle is %.0f\n",radius);
            printf("The area of the circle is %.2f\n", 3.14159*radius*radius);
            break;
        } // end of case 3

    } // end of switch //  printf("Please enter a choice(1-6): ");
 // scanf("%d",&choice);


/*   while(choice<0 || choice>=7)
            {   //beginning of while loop
                printf("Invalid option chosen please select a valid option and try again: ");
                scanf("%d",&choice);
            }   // end of while loop */





return 0;

} // end of main
