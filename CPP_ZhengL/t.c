#include<stdio.h>
int main()
{
    int x;
	for(x=100;x<1000;x++)
    {
        int a3=x/100;
        int a2=(x-100*a3)/10;
        int a1=x-100*a3-10*a2;
        if(a1*a1*a1+a2*a2*a2+a3*a3*a3==x)
        printf("%d\n",x);
    }
}