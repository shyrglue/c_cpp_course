#include<iostream>
#include<iomanip>
using namespace std;
double Maxpro(double a,double b)
{
    if(a>b) cout<<setiosflags(ios::fixed)<<setprecision(1)<<a;
    else cout<<setiosflags(ios::fixed)<<setprecision(1)<<b;
    return 0;
}
int MaxPro(int a,int b)
{
    double EPS = 1e-6;
    if(a>b+EPS)  cout<<a;
    else cout<<b;
    return 0;
}
int main()
{
    int o;
    cin>>o;
    if(o==2)
    {
        double a,b;
        cin>>a>>b;
        Maxpro(a,b);
    }
    else
    {
        int a,b;
        cin>>a>>b;
        MaxPro(a,b);
    }
}