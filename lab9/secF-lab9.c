// Selwyn Ralph
// sjrtrd
// 12448280
// Sydney Bates Section F
// Nibbler

#include <stdio.h>
#include <stdlib.h>

int length(char *sPntr)
{ // beginning of length fxn
    int i;
    int count = 0;
    char *lenPntr;
    
    lenPntr = sPntr;
    for(i = 0; *(lenPntr+i) != '\0'; i++)
    { // beginning of for loop
        count++;
    } // end of for loop
    return count;
} // end of length fxn

char* copy(char *sPntr)
{ // beginning of copy fxn
    char *copyPntr;
    int i;

    copyPntr = malloc(sizeof(char)*length(sPntr+1));
    
    for(i = 0; *(sPntr + i) !='\0'; i++)
    { // beginning of for loop
        *(copyPntr + i) = *(sPntr + i);
    } // end of for loop
    *(copyPntr + i) = '\0';

    return copyPntr;
} // end of copy fxn

char* reverse(char *sPntr)
{ // beginning of reverse fxn
    int i = length(sPntr) - 1;
    int j = 0;
    char *verStPntr = malloc(sizeof(char)*length(sPntr+1));
    while(i>=0)
    { // beginning of while loop
        *(verStPntr + j) = *(sPntr + i);
        j++;
        i--;
    } // end of while loop
    *(verStPntr + j) = '\0';
    return verStPntr;
} // end of reverse fxn

int compare(char *sPntr, char *s2Pntr)
{ // beginning of compare fxn
    int i;
    for(i = 0; *(sPntr + i) == *(s2Pntr + i); i++)
    {
        if(*(sPntr + i) == '\0')
            return 0;
    }

    return *(sPntr + i) - *(s2Pntr + i);
} // end of compare fxn

int palindrome(char *sPntr)
{ // beginning of palindrome fxn
    return compare(sPntr, reverse(sPntr));
} // end of palindrome fxn


int main()
{ // beginning of main
    char *firStPntr, *copPntr,*revStPntr, *comStPntr, *palPntr;
    int result;

    firStPntr = malloc(sizeof(char)*20);
    comStPntr = malloc(sizeof(char)*20);
    palPntr = malloc(sizeof(char)*20);

    printf("Enter the first string: ");
    scanf("%s", firStPntr);

    printf("\nInput string is %s\n", firStPntr);
    printf("Length of the string is %d\n", length(firStPntr));
    
    copPntr = copy(firStPntr);
    printf("Copy of the first string is %s\n", copPntr);

    revStPntr = reverse(firStPntr);
    printf("The reverse of the string %s is %s\n", firStPntr, revStPntr);

    printf("\nEnter a string for compare operation: ");
    scanf("%s", comStPntr);

    if(compare(firStPntr, comStPntr)>0)
        printf("The string %s is bigger than %s\n", firStPntr, comStPntr);
    if(compare(firStPntr, comStPntr)<0)
        printf("The string %s is bigger than %s\n", comStPntr, firStPntr);
    else
        printf("The string %s and %s are the same\n", firStPntr, comStPntr);

   printf("\nEnter a string to check for palindrome: ");
   scanf("%s", palPntr);

   result = palindrome(palPntr);
   if(result == 0) 
    printf("The string is a palindrome\n");
    else
        printf("The string is not a palindrome\n");



    return 0;
} // end of main
