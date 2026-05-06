#pragma once
#include<iostream>

using namespace std;

class vehicle
{
    public:
    vehicle()
    {
        cout<<"vehicle Construct"<<endl;
    }
    ~vehicle()
    {
        cout<<"vehicle Destroy"<<endl;
    }
};
class bicycle:virtual public vehicle
{
    public:
    bicycle()
    {
        cout<<"bicycle Construct"<<endl;
    }
    ~bicycle()
    {
        cout<<"bicycle Destroy"<<endl;
    }
};
class motocar:virtual public vehicle
{
    public:
    motocar()
    {
        cout<<"motocar Construct"<<endl;
    }
    ~motocar()
    {
        cout<<"motocar Destroy"<<endl;
    }
};
class motocycle:public bicycle,public motocar
{
    public:
    motocycle()
    {
        cout<<"motocycle Construct"<<endl;
    }
    ~motocycle()
    {
        cout<<"motocycle Destroy"<<endl;
    }
};