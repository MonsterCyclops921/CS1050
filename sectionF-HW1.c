// Selwyn Ralph
// sjrtrd
// 12448280
// SectionF Sydney Bates


#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define PI 3.14159


int main()
{
  /*Declare variables*/
 /*----------------------------------------------*/

   float area;
   float base1;
   float height;
   float radius;
   int choice;
   float breadth;
   float base2;
   int opt;



/*printing options*/
/*----------------------------------------------------*/



   puts("GEOMETRY CALCULATOR");

   puts("1.) Calculate the area of a Circle");
   puts("2.) Calculate the area of a Rectangle");
   puts("3.) Calculate the area of a Triangle");
   puts("4.) Calculate the area of a Trapezoid");
   puts("5.) Calculate the area of a Sphere");
   puts("6.) Exit");


   /*asking for choice*/
   /*-------------------------------------------------*/



do
 { // beginning of do while loop

    printf("Please enter a choice(1-6): ");
    scanf("%d",&choice);

    while(choice<0 || choice >=7)
    {
        printf("Invalid option. Please choose a valid option: ");
        scanf("%d",&choice);
    }

   switch(choice)

   { // beginning of switch


    case 1:
      {     //beginning of case 1

        puts("The area of a circle");
        printf("Enter the radius of the circle: ");
        scanf("%f",&radius);
        while(radius<0)
        {  //beginning of while loop
            printf("Invalid value. Enter a positive value only: ");
            scanf("%f",&radius);
        }   //end of while loop

        area = PI * pow(radius, 2);
        printf("The area is %0.2f units\n", area);
        break;

      }   //end of case 1


    case 2:
        {  // beginning of case 2
            puts("The area of a rectangle");
            printf("Enter the breadth and height: ");
            scanf("%f %f", &breadth, &height);

            if(breadth<0)
            { //beginning of if error check
                while(breadth<0)
                { //beginning of loop
                    printf("Enter a positive value for breadth: ");
                    scanf("%f", &breadth);
                }  //end of loop
            } // end of breadth if error check

            if(height<0)
            { //beginning of height error check
                while(height<0)
                { // beginning of loop
                    printf("Enter a positive value for height: ");
                    scanf("%f",&height);
                } // end of loop
            } //end of if error check

            area = breadth*height;
            printf("The area is %0.2f units\n",area);
            break;
        }  // end of case 2

    case 3:
        { //beginning of case 3
            puts("The area of a triangle");
            printf("Please enter the base and height: ");
            scanf("%f %f",&base1, &height);

            if( base1<0)
            { // beginning of error check for base1
                while(base1<0)
                { // beginning of loop error check
                    printf("Enter a positive value for the base: ");
                    scanf("%f",&base1);
                } // end of loop error check
            } // end of error check for base1

            if(height<0)
            { // beginning of if error check for height
                while(height<0)
                { // beginning of loop error check
                    printf("Enter a positive value for height: ");
                    scanf("%f",&height);
                } // end of loop error check for height
            } // end of if error check for height

            area = (base1*height)/2;
            printf("The area is %0.2f units\n", area);
            break;
        }  // end of case 3
    case 4:
        { //beginning of case 4
            puts("The area of a trapezoid");
            printf("Enter base 1, base 2, and the height: ");
            scanf("%f %f %f",&base1, &base2, &height);

            if(base1<0)
            { //beginning of error check for base1
                while(base1<0)
                { // beginning of loop
                    printf("Enter a positive value for base 1: ");
                    scanf("%f",&base1);
                } // end of loop
            } // end of error check for base1

            if(base2<0)
            { // beginning of base2 error check
                while(base2<0)
                { //beginning of loop
                    printf("Enter a positive value for base 2: ");
                    scanf("%f",&base2);
                } // end of loop
            } // end of base2 error check

            if(height<0)
            { // beginning of error check for height
                while(height<0)
                { // beginning of loop
                    printf("Enter a positive value for the height: ");
                    scanf("%f",&height);
                } // end of loop
            } // end of error check for height

            area = ((base1+base2)/2)*height;
            printf(" The area is %0.2f units\n", area);
            break;
        } //end of case 4
    case 5:
        { //beginning of case 5
            puts("The area of a sphere");
            printf("Enter the radius of the sphere: ");
            scanf("%f",&radius);
            while(radius<0)
            { // beginning of loop
                printf("Invalid value. Enter positive values only: ");
                scanf("%f",&radius);
            } // end of loop
            area = 4*PI * pow(radius, 2);
            printf("The area is %0.2f units\n", area);
            break;
        }  //end of case 5

        default:
        { //beginning of default
          puts("Exit\n");
          exit(0);
          break;
        } // end of default
} //end of switch

printf("Do you want to run this program again 1 for yes 0 for no: ");
scanf("%d",&opt);


} //end of do portion of loop
       while(opt !=0);

   return 0;

}



