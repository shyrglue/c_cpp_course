#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
class Date
{
    public:
    Date()
    {
        strcpy(date,"a");
    }
    Date(char a[12])
    {
        strcpy(date,a);
    }
    Date(const Date&a)
    {
        strcpy(this->date,a.date);
    }
    void output()
    {
        cout<<date;
    }
    private:
    char date[12];
};
class People
{
    public:
    People(char n[],char num[],char s[],Date a,char i[])
    {
        strcpy(name,n);
        strcpy(number,num);
        strcpy(sex,s);
        strcpy(id,i);
        birthday=a;
    }
    void output()
    {
        cout<<"Name: "<<name<<"\nNumber: "<<number<<"\nSex: "<<sex<<"\nBirthday: ";
        birthday.output();
        cout<<"\nID: "<<id;
    }
    private:
    char name[11];
    char number[7];
    char sex[8];
    Date birthday;
    char id[20];
};
int main()
{
    char n[11],num[7],s[8],i[20],d[12];
    scanf("%s",n);
    scanf("%s",num);
    scanf("%s",s);
    scanf("%s",d);
    scanf("%s",i);
    Date a(d);
    People A(n,num,s,a,i);
    if(!(d[0]==i[6]&&d[1]==i[7]&&d[2]==i[8]&&d[3]==i[9]&&d[5]==i[10]&&d[6]==i[11]&&d[8]==i[12]&&d[9]==i[13]))
        cout<<"birthday mismatch!"<<endl;
    A.output();
}