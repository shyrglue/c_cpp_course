#include<iostream>
using namespace std;

int main()
{
    int m,n;
    cin>>m>>n;
    char str1[100]="\0",str2[100]="\0";
    cin>>str1>>str2;
    for(int i=m;i<m+n;i++)
    {
        str1[i]=str2[i-m];
    }
    cout<<str1;
}