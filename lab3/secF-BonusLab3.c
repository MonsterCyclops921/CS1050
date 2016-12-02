// Selwyn Ralph
// sjrtrd
// 12448280
// section F Sydney Bates
// Purple


#include <stdio.h>

int powFun (float, int);

int main()

{
float num;
int exp;

printf("Enter a number: ");
scanf("%f",&num);

printf("\n");

printf("Enter an exponent: ");
scanf("%d",&exp);

printf("%f\n",powFun(num,exp));



return 0;
}


int powFun(float x, int n)
{
    if(n==0)
    {
        return 1;
    }
    else
        return x*powFun(x,n-1);

}

