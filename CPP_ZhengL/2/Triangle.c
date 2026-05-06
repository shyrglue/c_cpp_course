#include<stdio.h>
#include<math.h>
int main()
{
    int a,b,c;
    double L,S,p;
    scanf("%d%d%d",&a,&b,&c);
    if (a+b>c&&b+c>a&&a+c>b)
    {
        L=a+b+c;
        p=L/2;
        S=sqrt(p*(p-a)*(p-b)*(p-c));
        printf("%.2lf %.2lf",L,S);
    }
    else
    printf("Error");
}