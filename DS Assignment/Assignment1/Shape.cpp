#include <iostream>
#include "Shape.h"
using namespace std;
using namespace std;
Shape::Shape()
{
    this->name = "Empty";
    for (int i = 0; i < 3; i++)
    {
        this->location[i] = 0;
    }
    cout << "Defult Shape Constructer Is Called " << endl;
}
Shape::Shape(string n, int loc[3])
{
    this->name = n;
    cout << "Enter x y z : ";
    for (int i = 0; i < 3; i++)
    {
        cin >> loc[i];
    }
    for (int i = 0; i < 3; i++)
    {
        this->location[i] = loc[i];
    }
    cout << "Parameterized Shape Constructer Is Called " << endl;
}

void Shape::print()
{
    cout << "Name Is " << this->name << endl;
    cout << "His Location Is (";
    for (int i = 0; i < 3; i++)
    {
        cout << this->location[i];
        if (i != 2)
        {
            cout << ",";
        }
    }
    cout << ")" << endl;
}