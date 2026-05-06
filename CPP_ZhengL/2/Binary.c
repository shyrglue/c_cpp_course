#include<stdio.h>
int main()
{
    int a,num;
    num=1;
    scanf("%d",&a);
    while(a>1)
    {
        if(a%2==1)
        {
        num++;
        a=a/2;
        }
        else
        a=a/2;
    }
    printf("%d",num);
}