#include<stdio.h>
#define max 255
char *strcattype(char *s1, char *s2, int type)
{
    int a=0,b=0,i;
    while(s1[a]!='\0') a++;
    while(s2[b]!='\0') b++;
    if(type==1)
    {
        for(i=0;i<b;i++)
        s1[a+i]=s2[i];
        return s1;
    }
    else
    {
        for(i=0;i<a;i++)
        s2[b+i]=s1[i];
        return s2;
    }
}
int main()
{
    char s1[max]="\0",s2[max]="\0",s[max]="\0";
    int t;
    scanf("%s %s %d",s1,s2,&t);
    int a=0,b=0;
    while(s1[a]!='\0') a++;
    while(s2[b]!='\0') b++;
    int c=a+b;
    printf("%s %d",strcattype(s1,s2,t),c);
}