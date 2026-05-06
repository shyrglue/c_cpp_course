#include<stdio.h>
int main()
{
    char num[4];
    int max,min,sub=0,i,j,t;
    scanf("%s",num);
    if (num[0]==num[1]&&num[0]==num[2]&&num[0]==num[3])
    printf("ERROR");
    else{
    while(1)
    {
        for(i=0;i<3;i++)
        {
            for(j=0;j<3-i;j++)
            {
                if (num[j]<num[j+1])
                {
                t=num[j];
                num[j]=num[j+1];
                num[j+1]=t;
                }
            }
        }
    max=1000*(num[0]-'0')+100*(num[1]-'0')+10*(num[2]-'0')+(num[3]-'0');
        min=1000*(num[3]-'0')+100*(num[2]-'0')+10*(num[1]-'0')+(num[0]-'0');
    if(sub==max-min) break;
    else
    {
    sub=max-min;
    printf("(%d,%d,%d)\n",max,min,sub);
    num[0]=sub/1000;
    num[1]=sub/100%10;
    num[2]=sub/10%10;
    num[3]=sub%10;
    for(i=0;i<4;i++)
    num[i]+='0';
    }
    }
}}