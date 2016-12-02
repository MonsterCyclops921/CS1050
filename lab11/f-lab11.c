// Selwuyn Ralph
// 12448280
// sjrtrd
// Sydeny Bates Section F   

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

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

int vpr(char *pass, int size) // the verify password requirements fucntion
{ // beginning of fxn
    bool hasUpper = false;
    bool hasDigit = false;
    bool hasLower = false;
    bool hasSpecial = false;
    bool hasLength = false;
    int i;

    
    if(size>9 || size <11)
    { // beginning of if
        hasLength = true;
    } // end of if
    for(i=0; i<size; i++)
    {
         if(isupper(*(pass+i)))
             hasUpper = true;
         if(isdigit(*(pass+i)))
             hasDigit = true;
         if(islower(*(pass+i)))
             hasLower = true;
         if(ispunct(*(pass+i)))
             hasSpecial = true;
    }
    
    if(hasLength && hasUpper && hasDigit && hasLower && hasSpecial)
        return 1;
    else
        return 0;


} // end of fxn

int vai(char **useName, char **pasWrd, char **valUseName, char **valPass, int size) // verify account info fxn
{ // beginning of fxn
    int i;
    int k = 0;
    
    for(i=0; i<size; i++)
    { // beginning of loop
        if(strlen(*(useName+i)) == 6 && vpr(*(pasWrd+i),strlen(*(pasWrd+i)))==1)
        { // beginning of if
            *(valUseName+k) = *(useName+i);
            *(valPass+k) = *(pasWrd+i);
            k++;
        } // end if
    } // end of loop

    return k;
} // end of fxn






int main(int argc, char **argv)
{ // beginning of main
    
    int size = atoi(*(argv + 2));
    char **useName;
    char **pasWrd;
    char **valUseName;
    char **valPass;
    int i,j,k,l;
    int loDat = -1;
    int count = 0;

    useName = malloc(sizeof(char)*size*20);
    pasWrd = malloc(sizeof(char)*size*20);
    valUseName = malloc(sizeof(char)*size*20);
    valPass = malloc(sizeof(char)*size*20);

    for(i = 0; i<size; i++)
    { // beginning of for loop
        *(useName + i) = malloc(sizeof(char)*size*20);
    } // end of loop

    for(j = 0; j<size; j++)
    { // beginning of for loop
        *(pasWrd + j) = malloc(sizeof(char)*size*20);
    } // end of loop

    for(k=0; k<size; k++)
    { // beginning of loop
        *(valUseName+k) = malloc(sizeof(char)*size*20);
    } // end of loop

    for(l=0; l<size; l++)
    { // beginning of loop
        *(valPass+l) = malloc(sizeof(char)*size*20);
    } // end of loop

    if(argc != 4)
        puts("Insufficient command line arguments, please check again!");

    loDat = loadData(*(argv + 1), useName, pasWrd, size);

    if(loDat == 0)
    { // beginning of if
        puts("Unable to open the file, please check the file location/filename");
        puts("Exititng the program");
        exit(0);
    } // end of if
    
    printData(useName, pasWrd, size);
    count =  vai(useName, pasWrd, valUseName, valPass, size); 
    printf("\nThe number of valid accounts is %d\n", count);
    printf("\n");
    printData(valUseName, valPass,size);
    writeData(*(argv+3), valUseName, valPass, size);

    free(useName);
    free(pasWrd);
    free(valUseName);
    free(valPass);
    return 0;
} // end of main
