#include<iostream>
#include<iomanip>
using namespace std;
#pragma once

class Complex
{
public:
Complex(float a,float b){R=a;I=b;}
Complex(float a){R=a;}
void add(Complex c)
{
    this->R+=c.R;
    this->I+=c.I;
}
void show()
{
    cout<<fixed<<setprecision(2)<<R<<" + "<<I<<"i";
}
private:
float R,I;
};