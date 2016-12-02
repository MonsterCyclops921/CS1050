



#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int loadData(char *input, char **name, int *aNum, float *amnt,  int size) // fxn that gets the data from the file
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
    fscanf(fPntr,"%s %d %f\n", *(name+i), (aNum+i), (amnt+i));
   } // end of for loop
   fclose(fPntr);
   return 1;
} // end of fxn

void printData(char **name, int *aNum, float *amnt, int size) // fxn that prints the data from the file
{ // beginning of fxn
    int i;
    printf("\nName\t\tNumber\tAmount\n");

    for(i = 0; i < size; i++)
    { // beginning of for loop
        printf("%s\t\t%d\t%.2f\n",*(name+i ), *(aNum+i), *(amnt+i));
    } // end of for loop
} // end of fxn

int highestAmount (float *amnt, int size) // fxn that finds which account has the most money
{ // beginning of fxn
    float high = 0;
    int i;
    int index = 0;
    high = *(amnt);

    for(i=0; i<size; i++)
    { // beginning of for loop
        if(*(amnt+i)>high)
        { // beginning of if
            high=*(amnt+i);
            index=i;
        } // end of if
    } // end of for loop

    return index;    
} // end of fxn

int lowestAmount(float *amnt, int size) // fxn that finds which account has the lowest amount
{ // beginning of fxn
    float low = 0;
    int i;
    int index = 0;
    low = *(amnt);

    for(i = 0; i<size; i++)
    { // beginning of fxn
        if(*(amnt+i)<low)
        { // beginning of if
            low = *(amnt+i);
            index = i;
        } // end of if
    } // end of fxn
    return index;
} // end of fxn

float averageAmount(float *amnt, int size) // fxn that averages the accounts.
{ // beginning of fxn
    int i;
    float total = 0;

    for(i = 0; i<size; i++)
    { // beginning of loop
        total += *(amnt + i);
    } // end of loop

    return total/size;
} // end of fxn

int checkAccount(char **aName, int *aNum, char *pers,int acnt, int aSize) // fxn that looks through accounts names provided by the user
{ // beginning of fxn
    int i;
    int flag = -1;
    
    for(i=0; i<aSize; i++)
    { // beginning of for loop
       if( strcmp(*(aName +i),pers) == 0 && *(aNum+i)==acnt)
           flag = i;
    } // end of for loop
return flag;
 
} // end of fxn

void modAccount(float *amnt, float diff,  int op) // fxn that changes the balance of the fxn
{ // beginning of fxn
    if(op==1)
    { // beginning of if
      *amnt = *amnt - diff;
    } // end of if
    if(op==2)
        *amnt = *amnt + diff;
} // end of fxn
void sortData(char **name, int *aNum, float *aAmnt, int aSize) // fxn that sorts the accounts by name
{ // beginning of fxn
    int i, j;
    char *tName = malloc(sizeof(char)*20);
    int tNum;
    float tAmnt;
    
    for(i=0; i<aSize; i++)
    { // outer for loop
        for(j=0; j<aSize-i-1; j++)
        { // benginning of inner for loop
            if(strcmp(*(name+j),*(name+j+1))>0)
            { // beginning of if
      //     printf("comparing %s with %s and ready to swap", *(name+j),*(name+j+1));
           tName = *(name+j+1);
            tNum = *(aNum+j+1);
            tAmnt = *(aAmnt+j+1);

            *(name+j+1) = *(name+j);
            *(aNum+j+1) = *(aNum+j);
            *(aAmnt+j+1) = *(aAmnt+j);

            *(name+j) = tName;
            *(aNum+j) = tNum;
            *(aAmnt+j) = tAmnt;
            } // end of if

        } // end of for loop
    } // end of outer for loop

    
} // end of fxn

void writeData(char *output, char **name, int *acnt, float *amnt, int aSize) // fxn that writes thew info to a file.
{ // beginning of fxn
    FILE *fPntr;
    int i;
    int indexH;
    int indexL;

    fPntr = fopen(output,"w");
   fprintf(fPntr,"Name\t\t\tAccount No.\tAmmount\n" ); 
   for(i=0; i<aSize; i++)
    { // beginning of loop
        fprintf(fPntr,"%s\t\t\t%d\t\t%.2f\n",*(name+i), *(acnt+i), *(amnt+i));
    } // end of for loop

    indexH = highestAmount(amnt,aSize);
    fprintf(fPntr,"%s has the highest amount %.2f in the account number %d\n",*(name+indexH), *(amnt+indexH), *(acnt+indexH));

    indexL = lowestAmount(amnt,aSize);
    fprintf(fPntr,"%s has the lowest amount %.2f in the account number %d\n",*(name+indexL), *(amnt+indexL), *(acnt+indexL));

    fprintf(fPntr, "The average amount is %.2f\n", averageAmount(amnt,aSize));
    
    fclose(fPntr);
} // end of fxn

int main(int argc, char **argv)
{ // beginning of main

char **aName; // character double pointer to deal with file
int *aNum; // pointer for the file accounts
float *aAmnt;
int aSize = atoi(*(argv+2)); // number of accounts user will request
int indexHigh = 0; // variable to deal with highest amount 
int indexLow = 0; // variable to deal with lowest amount account
int temp; // just a temp variable to hold loadData return
int k; // variable to use if for loop
char *pers; // pointer for the users account name request
int acnt; // variable to deal with user account number request
int dummie = -1;
int index;
float balDif=0;
int opt;

    pers = malloc(sizeof(char)*20);
    aName = malloc(sizeof(char)*aSize*20);

    for(k = 0; k<aSize; k++)
    { // beginning of if
     *(aName+k) = malloc(sizeof(char)*aSize*20);
    } // end of if


    aNum = malloc(sizeof(int)*aSize);
    aAmnt = malloc(sizeof(float)*aSize);



    if(argc!=4)
    { // beginning of if
        printf("Insufficient arguments\n");
        return 1;
    } // end of if

  
    temp = loadData(*(argv+1), aName, aNum, aAmnt, aSize);
    if(temp == 0)
     {
         printf("File could not be opened. Check your filename or file location\n");
         printf("Exiting Program\n");
         return 0;
     }
    
    
     printData(aName, aNum, aAmnt, aSize);
  
    indexHigh = highestAmount(aAmnt, aSize);

    printf("\n%s has the highest amount %.2f in the account number %d\n",*(aName+indexHigh), *(aAmnt+indexHigh), *(aNum+indexHigh));

    indexLow = lowestAmount(aAmnt, aSize);
    printf("\n%s has the lowest amount %.2f in the acoount number %d\n",*(aName+indexLow), *(aAmnt+indexLow), *(aNum+indexLow));
    
    printf("\nThe average amount is %.2f\n", averageAmount(aAmnt, aSize));

    do{ // beginning of do while loop
        printf("\nEnter a name: ");
        scanf("%s", pers);
        printf("Enter an account number: ");
        scanf("%d", &acnt);

        if(checkAccount(aName,aNum,pers,acnt,aSize)==-1)
        { // beginning of if
            printf("No bank account with that name/number combination exists\n");
        } // end of if
        else
        { // beginning of else
            index = checkAccount(aName, aNum,pers,acnt,aSize);
            printf("Do yo want to (1) withdraw or (2) deposit: ");
            scanf("%d", &opt);
            printf("Enter an ammount: ");
            scanf("%f",&balDif);
            modAccount(aAmnt+index,balDif,opt);
        } // end of else 
        printf("Do you want to update another account? Press 1 if yes 0 if no: ");
        scanf("%d", &dummie);
    }while(dummie!=0); // end of the doWhile loop

    sortData(aName, aNum, aAmnt, aSize);

    writeData(*(argv+3), aName, aNum, aAmnt, aSize);
    printf("Thank you for using Mizzou Banking Sustem.\n");
    printf("Happy holidays break!!\n");
    
    
    free(aName);
    free(aNum);
    free(aAmnt);
    free(pers);


     return 0;

} // end of main
