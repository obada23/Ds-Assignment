#pragma once
using namespace std;
class Shape
{
public:
    Shape();
    Shape(string n, int loc[3]);
    virtual void print();
    virtual float area() = 0;
    virtual float volume() = 0;
    

protected:
    string name;
    int location[3];
};