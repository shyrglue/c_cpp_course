#include<stdio.h>
float a,b,c,d,e;
float f(float x);
float xpoint(float x1, float x2);
float root(float x1, float x2);
int main()
{
    float x1,x2;
    scanf("%f,%f,%f,%f,%f%f,%f",&a,&b,&c,&d,&e,&x1,&x2);
    printf("%.3f",root(x1,x2));
}
float f(float x)
{
    return x*x*x*x*x+a*x*x*x*x+b*x*x*x+c*x*x+d*x+e;
}
float xpoint(float x1, float x2)
{
    return (x2*f(x1)-x1*f(x2))/(f(x1)-f(x2));
}
float root(float x1, float x2)
{
    int i=1;
    float x,x0;
    while(i)
    {
    x0=xpoint(x1,x2);
    if (f(x0)*f(x1)>0)
    x1=x0;
    else
    x2=x0;
    x=xpoint(x1,x2);
    if (x-x0<0.000001&&x0-x<0.000001)
    i=0;
    }
    return x;
}