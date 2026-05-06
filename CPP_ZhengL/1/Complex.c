#include<stdio.h>
int main()
{
    double a,b,c,d;
    scanf("%lf%lfi %lf%lfi",&a,&b,&c,&d);
    if (b*c+a*d>=0)
    printf("%.3lf+%.3lfi",a*c-b*d,b*c+a*d);
    else
    printf("%.3lf%.3lfi",a*c-b*d,b*c+a*d);
}