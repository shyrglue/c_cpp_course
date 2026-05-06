#include<iostream>
using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;
    int a[5000];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int j=0;j<n-1;j++)
    {
        for(int i=0;i<n-j-1;i++)
        {
            if(a[i]>a[i+1])
            {
                int t=a[i];
                a[i]=a[i+1];
                a[i+1]=t;
            }
        }
    }
    cout<<a[k-1];
}