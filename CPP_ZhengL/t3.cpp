#include<iostream>
using namespace std;
int fib(int n)
{
    int i,m=1,t=1;
    for(i=1;2*i<n;i++)
    {
        t+=m;
        m+=t;
    }
    if(n%2==0)
    return m;
    else
    return t;
}
int main()
{
    int m,n,i;
    cin>>m>>n;
    for(i=0;fib(i+1)<n;i++)
    if(fib(i)>m) cout<<fib(i)<<' ';
    cout<<fib(i);
}