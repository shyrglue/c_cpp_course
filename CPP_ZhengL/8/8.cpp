#include<iostream>
using namespace std;
typedef struct TIME
{
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
}TIME;
int main()
{
    TIME a;
    cin>>a.year>>a.month>>a.day>>a.hour>>a.minute>>a.second;
    cout<<a.year<<' '<<a.month
    <<' '<<a.day<<' '<<a.hour<<' '
    <<a.minute<<' '<<a.second;
}