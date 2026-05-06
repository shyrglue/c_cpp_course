#include<stdio.h>
#include<string.h>
#define max 100
int main()
{
    char a[max],b[max];
    int e[max],f[max],sum[max];
    int i,t,m;
    
    scanf("%s%s",a,b);
    m=strlen(a)>=strlen(b)?strlen(a):strlen(b);
    for(i=0;i<max;i++)
    {
        e[i]=0;
        f[i]=0;
    }
    for (i=0;i<strlen(a);i++)
    {
        e[i]=a[strlen(a)-1-i]-48;
    }
    for (i=0;i<strlen(b);i++)
    {
        f[i]=b[strlen(b)-1-i]-48;
    }
    for (i=0;i<max;i++)
    {
        sum[i]=e[i]+f[i];
    }
    t=0;
    for (i=0;i<m;i++)
    {
        sum[i]+=t;
        if (sum[i]>9)
        {
            sum[i]%=10;
            t=1;
        }
        else
        t=0;
    }
        if (t==0)
        {
        for(i=0;i<m;i++)
        printf("%d",sum[m-i-1]);
        }
        else
        {
            printf("1");
        for(i=0;i<m;i++)
        printf("%d",sum[m-i-1]);
        }

}