#pragma once
#include "Shape.h"
using namespace std;

class Cylinder : public Shape
{
public:
	Cylinder();
	Cylinder(int loc[3], int rad, int height);
	void print()override;
	float area()override;
	float volume()override;

private:
	int h,r;
};

