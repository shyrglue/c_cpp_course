#pragma once
#include<iostream>
#include<iomanip>
class Person
{
    public:
    Person(const int& height,const float& weight)
    {
        this->height=height;
        this->weight=weight;
    }
    void showInfo()
    {
        std::cout<<height<<","<<std::fixed<<std::setprecision(2)<<weight;
    }
    private:
    
        int height;
        float weight;
    
};