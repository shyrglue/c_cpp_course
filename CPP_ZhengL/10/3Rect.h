#pragma once
#include<iostream>
using namespace std;
class Rect
{
    public:
    Rect(const float& top,const float& left,const float& bottom,const float& right)
    {
        this->bottom=bottom;
        this->left=left;
        this->right=right;
        this->top=top;
    }
    float getArea() const
    {
        return (top-bottom)*(right-left);
    }
    private:
    float top,left,bottom,right;
};