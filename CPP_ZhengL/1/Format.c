#include<stdio.h>
double f(double a)
{
    a=1000*a;
    a=(int)a;
    a=a/1000;
    return a;
}
int main()
{
    double a[12];
    for(int i=0;i<12;i++)
        scanf("%lf",&a[i]);
    for(int i=0;i<6;i++)
        a[i]=f(a[i]);
    printf("%-6.3lf %-6.3lf\n%-6.3lf %-6.3lf\n%-6.3lf %-6.3lf\n%6.2lf %6.2lf %6.2lf\n%6.2lf %6.2lf %6.2lf",a[0],a[1],a[2],a[3],a[4],a[5],a[6],a[7],a[8],a[9],a[10],a[11]);
}