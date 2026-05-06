#pragma once
#include<iostream>
#include<math.h>
using namespace std;

class Circle
{
public:
    Circle(const float& r){radius=r;};
    
    float getArea() const {return radius*radius*M_PI;};

private:
    float radius;
};