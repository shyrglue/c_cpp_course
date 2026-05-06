#include<iostream>
int main()
{
    int a[10]={1,2,3,4,5,6,7,8,9,10},*p=a;
    std::cout<<*(p+4)<<" "<<*(++p);
}