#include<stdio.h>
int main()
{
    char s[1000];
    int i,j;
    j=0;
    scanf("%s",s);
    for(i=0;i<1000;i++)
    {
        if (s[i]=='a'&&s[i+1]=='b'&&s[i+2]=='a')
        j++;
        else
        continue;
    }
    printf("%d",j);
}