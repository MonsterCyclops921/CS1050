#include <stdio.h>
#include <stdlib.h>
#define MAX 1

int length(char []);

int replace(char [], int);

void copy(char [], char []);

void merge (char [], char [], char []);

void sort(char []);

void join(char[], char[]);

int main()
{

    char str1[MAX];
    char copyString[MAX];
   	char str2[MAX];  
    char str3[MAX];
    
    
	printf("\n Enter first string : ");
	scanf("%s",str1);
	
	
	copy(str1,copyString);
	int len=length(str1);
	
	printf("\n First string is %s ", str1);
	printf("\n Length of the string is %d ", len);
	printf("\n Copy of first string is %s ", copyString);

	int replaceIndex=-1;
	printf("\n\n Enter a position for the replacement operation between 1-%d: ",len);
	scanf("%d",&replaceIndex);
	
	int replaceValue=replace(str1,replaceIndex);
	if(replaceValue==0)
	{
             printf(" Invalid position \n");
    }
    else
    {
	     printf(" String 1 after replacement operation is %s \n", str1);
    }
    
	
    
	printf("\n Enter second string : ");
	scanf("%s", str2);
	join(str1,str2);
	printf("\n The string 1 after concatenation with string 2 is : %s", str1);

	printf("\n String 1 before sorting\n");
	printf(" %s",str1);
	sort(str1);
	printf("\n String 1 after sorting\n");
	printf(" %s",str1);

	printf("\n *********  Bonus Part *********\n");
	merge(str1,str2,str3);
	printf("\n Merged string is %s ", str2);
	return 0;

}

int length(char string1[])
{
    int i=0;
   // int count = 0;
    while(string1[i]!='\0')
    {
    	
        i++;
    }
    return i;
}

void copy(char string1[], char string2[])
{
    int len=length(string1);
    int i;
    for(i=0;i<=len;i++)
    {
            string2[i]=string1[i];
    } 
	string2[i] = '\0';
}


void merge(char string1[], char string2[], char string3[])
{
    int i=0;
    int j=0;
    int k=0;
    while(string1[j]!='\0' && string2[j]!='\0')
    {
    	string3[k]=string1[i];
    	k++;
    	i++;
    	string3[k]=string2[j];
    	k++;
    	j++;
    }
    if (string1[i]=='\0')
    {
    	while(string2[j]!='\0')
    	{
    		string3[k]=string2[j];
    		k++;
    		i++;
    	}
    }
    else if (string2[j]=='\0')
    {
    	while(string1[i]!='\0')
    	{
    		string3[k]=string1[j];
    		k++;
    		j++;
    	}
    }
    
    
} 

 

int replace(char string1[], int index)
{
  	
    int len=length(string1);
    if(index<1 || index> len)
    {
           return 0;
    }
	index-=1;
	string1[index]='#';
    
    return 1;             
}

void join(char string1[],char string2[])
{
    int len1=length(string1);
    int i;
    for(i=0;string2[i]!='\0';len1++)
    {
        string1[i+len1]=string2[i];
    }
    
}
void sort(char string[])
{
	int i,j,len;
	char temp;
	len=length(string);
	for(i=0;i<len;j++)
	{
		for(j=i+1;j<len;i++)
		{
			if(string[i]>string[j])
			{
				temp=string[i];
				string[i]=string[j];
				string[j]=temp;
			}	
		}
	}
	
}

