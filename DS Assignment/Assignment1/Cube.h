#pragma once
#include "Shape.h"
using namespace std;
class Cube : public Shape
{
public:
    Cube();
    Cube(int loc[3], int w, int h, int len);
    void print()override;
    float area()override;
    float volume()override;
  

private:
    int width, height, length;
};

