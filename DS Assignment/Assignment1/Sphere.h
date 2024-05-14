#pragma once
#include "Shape.h"
using namespace std;
class Sphere : public Shape
{
public:
	Sphere();
	Sphere(int loc[3], int rad);
	void print() override;
	float area() override;
	float volume() override;

private:
	int r;
};
