#include<stdio.h>
#include<string.h>
#define max 1000
int strdelete(char *s1,char *s2)
{
    int i,j,m=0;
    int a=strlen(s1);
    for(i=0;i<a;i++)
    {
        int t=0;
        for(j=0;j<strlen(s2);j++)
        if(s1[i+j]==s2[j])  t++;
        if(t==strlen(s2))
        {
            for(j=0;j<strlen(s2);j++) s1[i+j]='\0';
            m++;
        }
    }
    return a-m*strlen(s2);
}
int main()
{
    char s1[max]="\0",s2[max]="\0";
    scanf("%s %s",s1,s2);
    int k=strdelete(s1,s2),l;
    for(l=0;l<max;l++)
    if(s1[l]!='\0') printf("%c",s1[l]);
    printf(" %d",k);
}