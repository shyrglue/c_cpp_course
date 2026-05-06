#include<stdio.h>
int main()
{
    int a,b,c,d,e,f,A,B,C,x,y,z;
    scanf("%d:%d:%d",&a,&b,&c);
    scanf("%d:%d:%d",&d,&e,&f);
    A=3600*a+60*b+c;
    B=3600*d+60*e+f;
    if (B>A)
    {
    C=A;
    A=B;
    B=C;
    }
    C=A-B;
    x=C/3600;
    y=(C-3600*x)/60;
    z=C-3600*x-60*y;
    printf("%02d:%02d:%02d",x,y,z);
}