#include<stdio.h>
int GCD2(int a,int b)
{
    while(a!=b)
    {
        if (a>b)
        a-=b;
        else
        b-=a;
    }
    return a;
}
int GCD3(int a,int b,int c)
{
    a=GCD2(a,b);
    a=GCD2(a,c);
    return a;
}
int main()
{
    int GCD[1000],i,j,t=0;
    for (i=0;i<1000;i++)
    {
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        if (a<0||b<0||c<0)
        {
            printf("error\n");
            i--;
            continue;
        }
        else if (a==0||b==0||c==0)
        break;
        else
        {
            GCD[i]=GCD3(a,b,c);
        }
    }
    for (j=0;j<i;j++)
    {
        if(GCD[j]<=GCD[j+1])
        GCD[i]=GCD[j+1];
    }
    for (j=0;j<i;j++)
    {
        if(GCD[j]==GCD[i])
        t++;
    }
    printf("%d %d",GCD[i],t);
}