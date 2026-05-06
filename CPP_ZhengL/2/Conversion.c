#include<stdio.h>
int main()
{
    int n,a,m,w;
    m=0;
    w=1;
    scanf("%d%d",&n,&a);
    while(n>0)
    {
        m=m+n%a*w;
        w=w*10;
        n=n/a;
    }
    printf("%d",m);
}