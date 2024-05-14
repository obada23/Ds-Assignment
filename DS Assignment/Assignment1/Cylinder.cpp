#include <iostream>
#include "Cylinder.h"
#include "Shape.h"
using namespace std;

Cylinder::Cylinder() : Shape()
{
	this->h = 0;
	this->r = 0;
	cout << "Defult Cylinder Constructer Is Called " << endl;
}

Cylinder::Cylinder(int loc[3], int rad, int height) : Shape("Cylinder", loc)
{
	this->r = rad;
	this->h = height;
	cout << "Parameterized Cylinder Constructer Is Called " << endl;
}

void Cylinder::print()
{
	Shape::print();
	cout << "Radius Is: " << this->r << endl;
	cout << "Hight Is: " << this->h << endl;
	cout << "Have Area " << area() << endl;
	cout << "And Volume " << volume() << endl;
}

float Cylinder::area()
{
	return 2 * 3.14 * (pow(this->r, 2)) + 2 * 3.14 * this->r * this->h;
}

float Cylinder::volume()
{
	return 3.14 * pow(this->r, 2) * this->h;
}