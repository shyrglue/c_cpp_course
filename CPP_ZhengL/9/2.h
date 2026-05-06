#include<iostream>
#pragma once
using namespace std;
class Tree
{
    public:
    Tree(const int& age)
    {
        ages=age;
    }
    int grow(int year)
    {
        ages+=year;
    }
    int age()
    {
        return ages;
    }
private:
int ages;
};