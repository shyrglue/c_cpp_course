
#include<iostream>
#include<string>
#include<cmath>
using namespace std;
 
void reverse(string &s,int a,int b,int l)
{
	if(l==0||l ==1)
		return;
	else{
		swap(s[a],s[b]);
		reverse(s,++a,--b,l-2);
		return;
        }
}
int main()
{
	string str;
	cin>>str;
	reverse(str,0,str.length()-1,str.length());
    cout<<str;
}