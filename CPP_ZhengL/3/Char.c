#include<stdio.h>
#include<ctype.h>
int main()
{
    char s[200];
    gets(s);
    int i=0,a=0,b=0,c=0,d=1;
    while(s[i]!='.')
    {
        if(isupper(s[i]))s[i]=tolower(s[i]);
        else if(islower(s[i]))s[i]=toupper(s[i]);
        if(isalpha(s[i]))a++;
        else if(isspace(s[i]))b++;
        else if(isdigit(s[i]))c++;
        else d++;
        i++;
    }
    printf("%s\n%d\n%d\n%d\n%d",s,a,b,c,d);
}