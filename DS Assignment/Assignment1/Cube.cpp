#include <iostream>
#include "Cube.h"
#include "Shape.h"
using namespace std;

Cube::Cube() : Shape()
{
    this->width = 0;
    this->height = 0;
    this->length = 0;
    cout << "Defult Cube Constructer Is Called " << endl;

}

Cube::Cube(int loc[3], int w, int h, int len) : Shape("Cube", loc)
{
   
    this->length = len;
    this->width = w;
    this->height = h;
    cout << "Parameterized Cube Constructer Is Called " << endl;
}

float Cube::area()
{
   // return 6 * this->length * this->length;
    return 2 * (this->width * this->length + this->length * this->height + this->height * this->width);
}

float Cube::volume()
{
    return this->length * this->width * this->height;
}

void Cube::print()
{
    Shape::print();
    cout << "Width Is: " << this->width << endl;
    cout << "Height Is: " << this->height << endl;
    cout << "Lenght Is: " << this->length << endl;
    cout << "Have Area: " << area() << endl;
    cout << "And Volume: " << volume() << endl;
}
