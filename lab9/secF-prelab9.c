#include <stdio.h>
#include <stdlib.h>

int length(char *strPntr)
{ // beginning of length fxn
    int i;
    int count = 0;
    char *cPntr;
    cPntr = strPntr;
   for(i = 0; *(cPntr+i)!='\0'; i+=sizeof(char))
   {
        count++;
   }
   return count;
} // end of length fxn

char* copy(char *strPntr)
{ // beginning of fxn
    char *copyPntr;
    int i;
    copyPntr = malloc(sizeof(char)*25);

    for(i = 0; *(strPntr +i)!='\0'; i+=sizeof(char))
    { // beginning of for loop
        *(copyPntr + i) = *(strPntr +i);
    } // end of for loop

    return copyPntr;

} // end of fxn

void clear(char *strPntr)
{ // beginning of fxn
    free(strPntr);
    return;
} // end of fxn

char* reverse(char *strPntr)
{ // beginning of fxn
    int i = length(strPntr) - 1;
    int j = 0;
    char *verStrPntr = malloc(sizeof(char)*length(strPntr)+1);
    while(i>=0)
    { // beginning of while loop
        *(verStrPntr + j) = *(strPntr + i);
        j++;
        i--;
    } // end of while loop
    *(verStrPntr + j) = '\0';
    return verStrPntr;
} // end of fxn

int compare(char *strPntr, char *str2Pntr)
{ // beginning of fxn
    if(length(strPntr)>length(str2Pntr))
    {
        return 1;
    }
    if(length(strPntr)< length(strPntr))
    {
      return -1;
    }
    else
        return 0;

    
} // end of fxn

int replace(char *strPntr, int pos)
{ // beginning of fxn
    if(pos<0 || pos>length(strPntr))
        return 0;
    else
    {
        *(strPntr + pos) = '#';
        return 1;
    }
} // end of fxn




int main()
{
    char *strPntr, *copStrPntr, *revStrPntr, *str2Pntr;
    int result;
    int pos;




    strPntr = malloc(sizeof(char)*25);
    str2Pntr = malloc(sizeof(char)*25);


    printf("Enter a string: ");
    scanf("%s",strPntr);

    printf("Input string is %s\n", strPntr);
    printf("The length of the string is %d\n", length(strPntr));

    copStrPntr = copy(strPntr);
    printf("Copy of the string is %s\n", copStrPntr);

    revStrPntr = reverse(strPntr);
    printf("The reverse of %s is %s\n", strPntr, revStrPntr);

    printf("Enter a second string: ");
    scanf("%s", str2Pntr);

    result = compare(strPntr, str2Pntr);

    if(result == 1)
        printf("String one is longer\n");
    if(result == -1)
        printf("String two is longer\n");
    if(result == 0)
        printf("The strings are of equal length\n");

    printf("Enter place where you want to replace in string, 1 - %d: ",length(strPntr));
    scanf("%d",&pos);

    while(replace(strPntr,(pos-1)) !=1)
    { // beginning of loop
        puts("Invalid position");
        printf("Enter place to replace in string, 1 - %d: ", length(strPntr));
        scanf("%d",&pos);

    } // end of loop

    printf("The string after replacement is: %s\n",strPntr);


    return 0;
}
