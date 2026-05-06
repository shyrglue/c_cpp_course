#include<iostream>

using namespace std;

class CLIENT
{
    public:
    static void ChangeServerName(string a)
    {
        ServerName=a;
    }
    static void add(int a)
    {
        ClientNum+=a;
        if(ClientNum>100000)
        ClientNum=100000;
    }
    static void sub(int a)
    {
        ClientNum-=a;
        if(ClientNum<0)
            ClientNum=0;
    }
    void output()
    {
        cout<<"server name: "<<ServerName<<"\nclient number: "<<ClientNum<<endl;
    }
    private:
    static string ServerName;
    static int ClientNum;
};
int CLIENT::ClientNum=0;
string CLIENT::ServerName="Server1";
int main()
{

    int n;
    cin>>n;
    CLIENT c;
    c.output();
    for(int i=0;i<n;i++)
    {
        string op;
        cin>>op;
        if(op=="rename")
        {
            string a;
            cin>>a;
            c.ChangeServerName(a);
        }
        else if(op=="add")
        {
            int a;
            cin>>a;
            c.add(a);
        }
        else if(op=="sub")
        {
            int a;
            cin>>a;
            c.sub(a);
        }
        c.output();
    }
}