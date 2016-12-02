#include <stdio.h>
#include <stdlib.h>

int length( char string1[])
{ // beginning of length fxn
    int i;

    for( i = 0; string1[i] != '\0'; i++);
    return i;
} // end of length fxn

void copy(char string1[], char string2[])
{ // beginning of copy fxn
    int i;
    for( i = 0; string1[i] != '\0'; i++)
    { // beginning of for loop
        string2[i] = string1[i];

    } // end of for loop

    string2[i] = '\0';


} // end of copy fxn



int main()
{ // beginnning of main

    char str1[1000];
    char copyStr[1000];

    printf("\nEnter the first string: ");
    scanf("%s", str1);

    printf("\nFirst string is %s\n",str1);
    printf("\nThe length of the string is %d\n", length(str1));

    copy(str1, copyStr);

    printf("\nCopy of first string is %s\n", copyStr);

    return 0;
} // end of main
