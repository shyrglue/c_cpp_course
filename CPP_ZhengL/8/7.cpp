#include<iostream>
#include<iomanip>
using namespace std;
long double p(double x,double n)
{
    if(n==0) return 1;
    else if(n==1) return x;
    return ((2*n-1)*x*p(x,n-1)-(n-1)*p(x,n-2))/n;
}
int main()
{
    double n,x;
    cin>>n>>x;
    cout<<fixed<<setprecision(1)<<p(x,n)<<endl;
}