#include <iostream>
#include "Sphere.h"
#include "Shape.h"
using namespace std;

Sphere::Sphere() : Shape()
{
	this->r = 0;
	cout << "Defult Sphere Constructer Is Called " << endl;
}

Sphere::Sphere(int loc[3], int rad) : Shape("Sphere", loc) , r(rad)
{
	cout << "Parameterized Sphere Constructer Is Called " << endl;
}

void Sphere::print()
{
	Shape::print();
	cout << "Radius Is: " << this->r << endl;
	cout << "Have Area: " << area() << endl;
	cout << "And Volume: " << volume() << endl;
}
float Sphere::area()
{
	return 4 * 3.14 * (pow(this->r, 2));
}

float Sphere::volume()
{
	return (4.0 / 3.0) * 3.14 * (pow(this->r, 3));
}



