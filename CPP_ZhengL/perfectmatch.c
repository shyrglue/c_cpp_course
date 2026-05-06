#include<stdio.h>
#include<string.h>
int main()
{
int n;
scanf("%d",&n);
for(int j=0;j<n;j++)
{
char s[1000];
scanf("%s",s);
int i=0,l=strlen(s)-1;
while(i<l)
{
if(s[i]+1==s[i+1]||s[i]+2==s[i+1]) i+=2;
else if(s[i]+1==s[l]||s[i]+2==s[l])
{i++;l--;}
else goto label;
}
if(i==l)
{
label:printf("no\n");
continue;
}
else printf("yes\n");
}
}