#include<iostream>
#include<iomanip>
using namespace std;
enum CPU_Rank{P1=1,P2,P3,P4,P5,P6,P7};
class CPU
{
public:
    CPU(int r,int f,float v){
        rank=(enum CPU_Rank)r;
        fre=f;
        vol=v;
        cout<<"CPU Construct"<<endl;
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
    ~CPU()
    {
        cout<<"CPU Destroy"<<endl;
    }
private:
    enum CPU_Rank rank;
    unsigned int fre;
    float vol;
};
int main()
{
    int r,f;
    float v;
    cin>>r>>f>>v;
    CPU a=CPU(r,f,v);
    a.run();
    a.stop();
}