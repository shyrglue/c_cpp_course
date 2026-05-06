#include <iostream>
#include <string>
#include<set>
using namespace std;
int main()
{
    multiset<string> a;
    string s;
    cin>>s;
    while(s!="QUIT")
    {
        int t=0;
        t=a.count(s);
        cout<<t<<endl;
        a.insert(s);
        cin>>s;
    }
}