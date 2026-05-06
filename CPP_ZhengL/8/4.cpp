#include<iostream>
#include<iomanip>
using namespace std;

int getPower(int x,int y)
{
    if(y<0) return 0;
    if(y==0)
    return 1;
    return x*getPower(x,y-1);
}
double getPower(double x,int y)
{
    if(y<0)
    {
        x=1/x;
        y=-y;
    }
    if(y==0)
    return 1;
    return x*getPower(x,y-1);
}
int main()
{
    int a,m;
    double b;
    cin>>a>>b>>m;
    double p;
    p=getPower(b,m);
    p*=10000;
    p=(int)p;
    p/=10000;
    cout<<getPower(a,m)<<' '<<setiosflags(ios::fixed)<<setprecision(4)<<p;
}