#include<iostream>
#include<iomanip>
using namespace std;
enum CPU_Rank{P1=1,P2,P3,P4,P5,P6,P7};
class CPU
{
    public:
    CPU()
    {
        rank=(enum CPU_Rank)0;
        fre=0;
        vol=0;
    }
    CPU(int r,int f,float v){
        rank=(enum CPU_Rank)r;
        fre=f;
        vol=v;
    }
    CPU(const CPU&a)
    {
        this->rank=a.rank;
        this->fre=a.fre;
        this->vol=a.vol;
    }
    void run(){
        cout<<"CPU RUN"
            <<"\nCPU rank: P"<<rank
            <<"\nCPU frequency: "<<fre
            <<" MHz\nCPU voltage: "<<fixed<<setprecision(2)<<vol
            <<" V"<<endl;
    }
    void stop()
    {
        cout<<"CPU STOP"<<endl;
    }
private:
    enum CPU_Rank rank;
    unsigned int fre;
    float vol;
};
class RAM
{
    public:
    RAM()
    {
        type="a";
    }
    RAM(string t)
    {
        type=t;
    }
    void run()
    {
        cout<<"RAM RUN"
            <<"\nRAM type: "<<type<<endl;
    }
    void stop()
    {
        cout<<"RAM STOP"<<endl;
    }
    private:
    string type;
};
class CDROM
{
    public:
    CDROM()
    {
        type="a";
    }
    CDROM(string t)
    {
        type=t;
    }
    void run()
    {
        cout<<"CDROM RUN"
            <<"\nCDROM type: "<<type<<endl;
    }
    void stop()
    {
        cout<<"CDROM STOP"<<endl;
    }
    private:
    string type;
};
class Computer
{
    public:
    Computer(CPU a,RAM b,CDROM c)
    {
        cpu=a;
        ram=b;
        cdrom=c;
    }
    void run()
    {
        cout<<"Computer RUN"<<endl;
        cpu.run();
        ram.run();
        cdrom.run();
    }
    void stop()
    {
        cdrom.stop();
        ram.stop();
        cpu.stop();
        cout<<"Computer STOP"<<endl;
    }
    private:
    CPU cpu;
    RAM ram;
    CDROM cdrom;
};
int main()
{
    CPU a{0,0,0};
    RAM b("a");
    CDROM c("a");
    for(int i=0;i<3;i++)
    {
        string op;
        cin>>op;
        if(op=="CPU")
        {
            int r,f;
            float v;
            cin>>r>>f>>v;
            a=CPU{r,f,v};
        }
        if(op=="RAM")
        {
            string t;
            cin>>t;
            b=RAM(t);    
        }
        if(op=="CDROM")
        {
            string t;
            cin>>t;
            c=CDROM(t);
        }
    }
    Computer com{a,b,c};
    com.run();
    com.stop();
}