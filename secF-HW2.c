

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


//GLOBAL CONSTANTS

#define ROW 6										//Number of Rows of seats
#define COL 4										//Number of Columns of seats
#define MAX 25										//Maximum characters in strings
//GLOBAL VARIABLES

//A global 2-D array which holds the cost.
int costMatrix[ROW][COL]={{500,200,200,500},	
			  			  {500,200,200,500}, 
			  			  {500,200,200,500},
			  			  {500,200,200,500},
			 			  {500,200,200,500},
			 			  {500,200,200,500}};

void displayMenu();
int loginMatch(int passcode, int adminPasscode);
void initialSeats(char flight[][COL],int count);
void printFlightMap(char flight[][COL]);
void flightMenu();
int getTotalRevenue(char flight1[][COL],char flight2[][COL], char flight3[][COL]);
void seatReservation(char flight[][COL]);


int errorCheck( int opt) // fxn that error checks the options for the switch statement. 
{ // beginning of error check fxn
    if(opt<1 || opt>3)
        return 0;
    else
        return 1;

} // end of error check fxn

int fErrorCheck(int fNum) // fxn that error checks the flight number the customer is picking.
{ // beginning of fErrorCheck
    if(fNum<1 || fNum>3)
        return 0;
    else
        return 1;
} // end of fErrorCheck

int main(void)
{ // beginning of main fxn
    char flight1[ROW][COL];
    char flight2[ROW][COL];
    char flight3[ROW][COL];
    char name[MAX];
    int adminPasscode = 105016;
    int passWord = 0;
    int opt = 0;
    int seats = 0;
    int fNum = 0;

    printf("\n");
    puts("*********WELCOME TO JOE'S AIRLINE BOOKING SYSTEM*********");
    printf("\n");

    srand(time(NULL));
    seats = rand()%5 +1;


    initialSeats(flight1,seats);
    initialSeats(flight2, seats);
    initialSeats(flight3, seats);
   
   do { // beginning of do portion of the do while loop
    displayMenu();
    printf("\nChoose an option: ");
    scanf("%d", &opt);

    while(errorCheck(opt)!=1)
    { // beginning of while loop
      printf("\nWRONG OPTION!! CHOOSE A RIGHT OPTION!!!!!: ");
      scanf("%d", &opt);
    } // end of while loop

    switch (opt)
        { // beginning of switch statement
            case 1:
                { // beginning of case 1
                    printf("\nEnter the passcode to log in as admin: ");
                    scanf("%d",&passWord);

                    while(loginMatch(passWord, adminPasscode) !=1)
                    { // beginning of loop
                        printf("\nInvalid Passcode combination: ");
                        scanf("%d", &passWord);

                    } // end of loop

                    printf("\n");

                    puts("Printing the Flight Map of flight COU to MIA");
                    printFlightMap(flight1);
                    puts("\n");

                    puts("Printing the Flight Map of flight COU to BNA");
                    printFlightMap(flight2);
                    puts("\n");

                    puts("Printing the Flight map of flight COU to LAS");
                    printFlightMap(flight3);
                    puts("\n");

                    printf("The total revenue is %d\n", getTotalRevenue(flight1, flight2, flight3));
                    puts("You are now logged out\n");

                    break;
                } // end of case 1

            case 2:
                { // beginning of case 2
                    flightMenu();
                    printf("\nChoose a flight: ");
                    scanf("%d", &fNum);

                    while(fErrorCheck(fNum)!=1)
                    { // beginning of error check loop
                        printf("\nChoose a flight: ");
                        scanf("%d", &fNum);
                    } // end of error check loop

                    
                    printf("Enter Your first name: "); // dont understand
                    scanf("%s", name); // dont understand



                    if(fNum == 1)
                    { // beginning of first if

                       seatReservation(flight1);
                       char  flightNumber1[MAX] = "MIA1050";
                       printf("\nCongrats %s, your flight %s  is booked,   enjoy your trip.\n", name,flightNumber1);

                     //  printMessage(name, flightNumber1);

                    } // end of first if
                    
                    if(fNum == 2)
                    { // beginning of second if
                       seatReservation(flight2);
                       char flightNumber2[MAX] = "BNA1050";
                       printf("\nCongrats %s, your flight %s is booked, enjoy your trip.\n", name, flightNumber2);
                    } // end of second if

                    if(fNum == 3)
                    { // beginning of third if
                        seatReservation(flight3);
                        char flightNumber3[MAX] = "LAS1050";
                        printf("\nCongrats %s, your flight %s is booked, enjoy your trip.\n", name, flightNumber3);
                    } // end of third if

                    break;
                } // end of case 2

            default:
                { // beginning of default
                    printf("Terminating the Program\n");
                    printf("Thank you for using Joe's On_the_line Airline Booking System\n");
                    exit(0);
                    break;
                } // end of default

        } // end of switch statement

    } // end of the do portion of the do while loop
    while(opt != 3);    
        return 0;

} // end of main fxn


void initialSeats(char flight[][COL],int count) // fxn that initializes the seats to 'O' then randomly fills an 'X'
{ // beginning of initialSeats fxn
    int i;
    int j;
    int k = 0;
    int row = rand() % ROW;
    int col = rand() % COL;


        for(i=0; i<ROW; i++)
        { // beginning of outer for loop
            for(j=0; j<COL; j++)
            { // beginning of inner for loop
                flight[i][j] = 'O';
            } // end of inner for loop
        } // end of outer for loop

        while(k < count)
        { // beginning of outer while loop
            while(flight[row][col] == 'O')
           { // beginning of while loop
        
             flight[row][col] = 'X';
             k = k + 1;
            } // end of inner while loop
         
          row = rand() & ROW;
          col = rand() % COL;
         } // end of outer while loop

} // end of initialSeats fxn

void printFlightMap(char flight[][COL]) // fxn that prints the seat chart
{ // beginning of printFlightMap fxn
    int i;
    int j;

    for(i = 0; i<ROW; i++)
    { // beginning of outer for loop
        for(j = 0; j<COL; j++)
        { // beginning of inner of loop
            printf("%c ",flight[i][j]);
        } // end of inner loop
        printf("\n");
    } // end of outer for loop

} // end of printFlightMap fxn

void displayMenu() // fxn that displays menua options
{ // beginning of display fxn
    puts("1.) Admin mode");
    puts("2.) Reserve a seat");
    puts("3.) Exit");

    printf("\n");

} // end of display fxn

int loginMatch(int passcode, int adminPasscode) // a fxn that checks to see if the correct password is entered
{ // beginning of loginmatch fxn
    if(passcode == adminPasscode)
        return 1;
    else
        return 0;

} // end of loginmatch fxn


int getTotalRevenue(char flight1[ROW][COL], char flight2[ROW][COL], char flight3[ROW][COL]) // fxn that addds up all the reserved seats 
{ // beginning of totalRevenue
    int i;
    int j;
    int total = 0;
    for(i = 0; i<ROW; i++)
    { // beginning of outer for loop
        for( j = 0; j<COL; j++)
        { // beginning of inner for loop
        if(flight1[i][j] == 'X')
            total += costMatrix[i][j];
        } // end of outer for loop
    } // end of  outer for loop

     for(i = 0; i<ROW; i++)
    { // beginning of outer for loop
        for( j = 0; j<COL; j++)
        { // beginning of inner for loop
        if(flight2[i][j] == 'X')
            total += costMatrix[i][j];
        } // end of outer for loop
    } // end of  outer for loop

    for(i = 0; i<ROW; i++)
    { // beginning of outer for loop
        for( j = 0; j<COL; j++)
        { // beginning of inner for loop
        if(flight3[i][j] == 'X')
            total += costMatrix[i][j];
        } // end of outer for loop
    } // end of  outer for loop

    return total;
} // beginning of totalRevenue

void flightMenu() // fxn that prints out the flight options
{ // beginning of fxn
     puts("1.) COU-------------------->MIA");
     puts("2.) COU-------------------->BNA");
     puts("3.) COU-------------------->LAS");
} // end of fxn

void seatReservation(char flight[ROW][COL]) // fxn that reserves the seat
{ // beginning of seatReservation fxn
    int rho = 0;
    int cul = 0;
    int flag = 0;

    printFlightMap(flight);




    while(flag == 0)
    { // beginning of while lop
    printf("\nWhich seat row do you want?: ");
    scanf("%d", &rho);

    printf("\nWhich seat column do you want?: ");
    scanf("%d", &cul);
        if(rho>0 || rho<ROW)
        { // beginning of outer if
            if(cul>0 || cul<COL)
            { // beginning of first inner if
                if(flight[rho][cul] == 'O')
                { // beginning of inner most if
                    flight[rho][cul] = 'X';
                    printf("\nYour request has been reserved\n");
                    flag = 1;

                } // end of inner most if
                else
                {
                    printf("\nSorry!! someone has reserved that seat. Please try again.\n");
                }
            } // end of first inner if
        } // end of outer if

    } // end of while loop
    printFlightMap(flight);

} // end of seatReservation fxn
