#include<stdio.h>
#define max 1000
int main()
{
    char key[max]="\0",input[max]="\0",alpha[max]="ABCDEFGHIJKLMNOPQRSTUVWXYZ",ans[max]="\0";
    gets(input);
    int i,j,t,m=0;
    for(i=0;i<1000;i++)
    {
        if(input[i]==' ')
        break;
        else
        {
            t=0;
            for(j=0;j<m;j++)
            {
                if(key[j]!=input[i])
                    t++;
            }
            if(t==m)
            {
                key[m]=input[i];
                m++;
            }
        }
    }

    int len=i,a;
    for(i=0;i<26;i++)
    {
        t=0;
        for(j=0;j<m;j++)
        {
            if(alpha[i]!=key[j])
            t++;
        }
        if(t==m)
        {
            key[m+a]=alpha[i];
            a++;
        }
    }

    i=0;
    while(input[len+i+1]!='\0')
    {
        printf("%c",key[input[len+i+1]-65]);
        i++;
    }
}