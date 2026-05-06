#include<stdio.h>
int main()
{
    int num;
    double price,dis,pay;
    scanf("%d %lf",&num,&price);
    dis=num*(int)price/100;
    pay=num*price-20*dis;
    printf("%.2lf %.2lf",20*dis,pay);
}