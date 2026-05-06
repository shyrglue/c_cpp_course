#include<iostream>
#include<string.h>
using namespace std;
class Employee
{
public:
    Employee(char*n,char*c,char*a,char*p)
    {
        strcpy(name,n);
        strcpy(city,c);
        strcpy(add,a);
        strcpy(pc,p);
    }
    void change_name(char*a)
    {
        strcpy(name,a);
    }
    void display()
    {
        cout<<"Name: "<<name<<"\nCity: "<<city<<"\nAddress: "<<add<<"\nPostcode: "<<pc<<endl;
    }
private:
    char name[500],city[500],add[500],pc[500];
};
int main()
{
    char a[500],b[500],c[500],d[500],e[500];
    cin.getline(a,500,'\n');
    cin.getline(b,500,'\n');
    cin.getline(c,500,'\n');
    cin.getline(d,500,'\n');
    cin.getline(e,500,'\n');
    Employee q=Employee(a,b,c,d);
    q.display();
    q.change_name(e);
    q.display();
}