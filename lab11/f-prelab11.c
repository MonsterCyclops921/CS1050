// Selwuyn Ralph
// 12448280
// sjrtrd
// Sydeny Bates Section F   

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int loadData(char *input, char **useName, char **pasWrd, int size)
{ // beginning of fxn
    FILE *fPntr;
    int i;
    
    fPntr = fopen(input, "r");

    if(fPntr == NULL)
    { // beginning of if
        return 0;
    } // end of if

    for(i = 0; i<size; i++)
    { // beginning of for loop
        fscanf(fPntr, "%s %s\n", *(useName + i), *(pasWrd + i));
    } // end of loop

    fclose(fPntr);
    return 1;
} // end of fxn

void printData(char **useName, char **pasWrd, int size)
{ // beginning of print fxn
    int i;
   
   printf("%-s %12s\n","USERNAME", "PASSWORD");
    
   for(i=0; i<size; i++)
   { // beginning of for loop
    
    printf("%-12s %-30s\n", *(useName + i), *(pasWrd + i));
   } // end of for loop

} // end of print fxn

void writeData(char *output, char **useName, char **pasWrd, int size)
{ // beginning of fxn
    FILE *fPntr;
    int i;

    fPntr = fopen(output,"w");
    fprintf(fPntr,"USERNAME\t\tPassword\n");
    for(i=0; i<size; i++)
    { // beginning of for loop
        fprintf(fPntr,"%-12s %-30s\n",*(useName+i), *(pasWrd+i));
    } // end of loop
    
} // end of fxn



int main(int argc, char **argv)
{ // beginning of main
    
    int size = atoi(*(argv + 2));
    char **useName;
    char **pasWrd;
    int i,j;
    int loDat = -1;

    useName = malloc(sizeof(char)*size*20);
    pasWrd = malloc(sizeof(char)*size*20);

    for(i = 0; i<size; i++)
    { // beginning of for loop
        *(useName + i) = malloc(sizeof(char)*size*20);
    } // end of loop

    for(j = 0; j<size; j++)
    { // beginning of for loop
        *(pasWrd + j) = malloc(sizeof(char)*size*20);
    } // end of loop

    if(argc != 4)
        puts("Insufficient command line arguments, please check again!");

    loDat = loadData(*(argv + 1), useName, pasWrd, size);

    if(loDat == 0)
    { // beginning of if
        puts("Unable to open the file, please check the file location/filename");
        puts("Exititng the program");
    } // end of if
    
    printData(useName, pasWrd, size);
    writeData(*(argv+3), useName, pasWrd, size);
    return 0;
} // end of main
