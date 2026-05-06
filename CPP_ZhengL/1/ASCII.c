#include<stdio.h>
int main()
{
    char ch,ch1;
    int offset;
    scanf("%d %c",&offset,&ch);

    ch1=ch+offset;
    printf("%c",ch1);
}