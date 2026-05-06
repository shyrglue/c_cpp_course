#include<stdio.h>
struct A
{
    int n;
    double f;
} ser;
void Input()
{
    scanf("%d %lf",&(ser.n),&(ser.f));
}
void Output(struct A ser)
{
    printf("%d %.2lf",ser.n,ser.f);
}
int main()
{
    Input();
    Output(ser);
}