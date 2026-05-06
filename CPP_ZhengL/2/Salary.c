#include<stdio.h>
int main()
{
    double sales,salary;
    scanf("%lf",&sales);
    if(sales<=8)
    salary=62.5*sales;
    else
    salary=8*62.5+(sales-8)*62.5*1.5;
    printf("%.2lf",salary);
}