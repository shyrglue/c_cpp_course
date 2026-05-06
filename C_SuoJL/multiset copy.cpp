#include<iostream>
#include<vector>
#include<iterator>
#include<algorithm>
#include<functional>
using namespace std;

double sq(double x){
    return x*x;
}

int main()
{
    const int N=5;
    vector<int> s(N);
    for(int i=0;i<N;i++)
    cin>>s[i];
    transform(s.begin(),s.end(),ostream_iterator<int>(cout," "),negate<int>());
    cout<<endl;
    transform(istream_iterator<double>(cin),istream_iterator<double>(),ostream_iterator<double>(cout,"\t"),sq);
    cout<<endl;
}