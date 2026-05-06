#include<iostream>
#include<cstring>
using namespace std;

int main()
{
    char s[500]="\0";
    int n[500],i,j;
    for(i=0;i<500;i++)n[i]=1;
    cin.getline(s,500,'\n');
    int l=strlen(s);
    for(i=0;i<l;i++)
    {
        for(j=i+1;j<l;j++)
        {
            if(s[j]==s[i])
            {
                s[j]=' ';
                n[i]++;
            }
        }
    }
    char tc;
    int ti;
    for(i=0;i<l-1;i++)
    {
        for(j=0;j<l-1-i;j++)
        {
            if(s[j]>s[j+1])
            {
                tc=s[j];
                s[j]=s[j+1];
                s[j+1]=tc;
                ti=n[j];
                n[j]=n[j+1];
                n[j+1]=ti;
            }
        }
    }
    for(i=0;i<l;i++)
    {
        if(s[i]==' ')continue;
        else cout<<s[i]<<" "<<n[i]<<endl;
    }
}