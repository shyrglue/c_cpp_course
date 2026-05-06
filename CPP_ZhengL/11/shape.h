#pragma once
#include<math.h>
#include<iostream>
using namespace std;

class Shape
{
    virtual float getArea()const=0;
    virtual float getPerim()const=0;
};

class Rectangle:public Shape
{
    public:
    Rectangle(const float& width,const float& height)
    {
        this->height=height;
        this->width=width;
    }
    float getArea()
    {
        return width*height;
    }
    private:
    float height,width;
};
class Circle:public Shape
{
    public:
    Circle(const float& radius)
    {
        this->radius=radius;
    }
    float getArea()
    {
        return M_PI*radius*radius;
    }
    private:
    float radius;
};