#include<iostream>
using namespace std;
class BOX
{
public:
BOX(int x){a=x;}
BOX(const BOX& b)//拷贝构造函数教学
{
    this->a=b.a;
}//不写这个函数也是一样的
void S(){cout<<6*a*a;}
void V(){cout<<a*a*a;}
private:
int a;
};
int main()
{
    int a;
    cin>>a;
    BOX b=a;  //竟然是这么写的
    BOX c=b;  //我真是爱死C++了
    c.V();
    cout<<" ";
    c.S();
}
//eyes:easy