
#include <stdio.h>
#include <stdlib.h>

#define MAX 50

int length( char string1[])
{ // beginning of length fxn
    int i;

     for( i = 0; string1[i] != '\0'; i++);
     return i;
} // end of length fxn

int replace(char string1[], int i)
{ // beginning of fxn
    if(i > length(string1) || i<0)
    { // beginning of if
        return 0;
    } // end of if
    else
    { // beginning of else
        string1[i] = '#';
        return 1;
    } // end of else
} // end of fxn

void copy(char string1[], char string2[])
{ // beginning of copy fxn
    int i;
     for( i = 0; string1[i] != '\0'; i++)
     { // beginning of for loop
                        string2[i] = string1[i];

     } // end of for loop

     string2[i] = '\0';


} // end of copy fxn

void join(char str1[], char str2[])
{ // beginning of fxn
 int i, j;

 for(i = 0; str1[i] != '\0'; i++);
 
 for(j = 0; str2[j] != '\0'; j++, i++)
 { // beginning of for loop
    str1[i] = str2[j];
 } // end of for loop

 str1[i] = '\0';

} // end of fxn

void sort(char string[])
{ // beginning of fxn
    char temp;
    int i, j, len;

    len = length(string);

    for(i = 0; i < len -1; i++)
    { // beginning of outer for loop
        for(j = i + 1; j<len; j++)
        { // beginning of inner for loop
           if(string[i] > string[j])
           { // beginning of if
            temp = string[i];
            string[i] = string[j];
            string[j] = temp;
            } // end of if
        } // end of inner for loop
        
    } // end of outer for loop
    
} // end of fxn



int main()
{ // beginnning of main

 char str1[MAX];
 char str2[MAX];
 char copyStr[MAX];
 int pos;

     printf("\nEnter the first string: ");
     scanf("%s", str1);

     printf("\nFirst string is %s\n",str1);
     printf("The length of the string is %d\n", length(str1));

     copy(str1, copyStr);

     printf("\nCopy of first string is %s\n", copyStr);
    
     printf("Enter a postion for the replacement operation between 1 - %d: ", length(str1));
     scanf("%d",&pos);

     while(replace(str1,(pos-1)) !=1)
     { // beginning of while loop
        puts("Invalid option");
        printf("Enter a position for the replacement operation between 1 - %d: ", length(str1));
        scanf("%d",&pos);
     } // end of while loop

     printf("\nString 1 after replacement operation is %s\n",str1);
     
     printf("\nEnter a second string: ");
     scanf("%s", str2);

     join(str1,str2);
     printf("The string 1 after concatenation with string 2 is : %s\n",str1);

     puts("String 1 before sorting");
     printf("%s\n",str1);
     puts("String 1 after sorting");
     sort(str1);
     printf("%s\n", str1);
    

    

     return 0;
} // end of main
