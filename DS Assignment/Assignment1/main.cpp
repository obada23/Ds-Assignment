#include <iostream>
#include <fstream>
#include <string>
#include "Shape.h"
#include "Cube.h"
#include "Sphere.h"
#include "Cylinder.h"
using namespace std;

void testShape()
{
    int location[3];
    int choice;

    while (true)
    {
        cout << "1: Cube" << endl;
        cout << "2: Sphere" << endl;
        cout << "3: Cylinder" << endl;
        cout << "4: Quit" << endl;
        cout << "Enter Choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            int w, h, l;
            cout << "Enter Width: ";
            cin >> w;
            cout << "Enter Height: ";
            cin >> h;
            cout << "Enter Length: ";
            cin >> l;           
            cout << "Enter Location : ";
            for (int i = 0; i < 3; i++)
            {
                cin >> location[i];
            }
            cout << "\nName: Cube " << endl;
            cout << "Location: (";
            for (int i = 0; i < 3; i++)
            {
                cout << location[i];
                if (i != 2)
                {
                    cout << ",";
                }
            }
            cout << ")" << endl;
            cout << "Width: " << w << endl;
            cout << "Height: " << h << endl;
            cout << "Length: " << l << endl;
            cout << "Area: " << 2 * (w * l + l * h + h * w) << endl;
            cout << "Volume: " << l * w * h << endl;
            break; 
        }
        case 2: 
        {
            int r;
            cout << "Enter Radius: ";
            cin >> r;
            cout << "Enter Location : ";
            for (int i = 0; i < 3; i++)
            {
                cin >> location[i];
            }
            cout << "\nName: Sphere " << endl;
            cout << "Location: (";
            for (int i = 0; i < 3; i++)
            {
                cout << location[i];
                if (i != 2)
                {
                    cout << ",";
                }
            }
            cout << ")" << endl;
            cout << "Radius: " << r << endl;
            cout << "Area:  " << 4 * 3.14 * (pow(r, 2)) << endl;
            cout << "Volume:" << (4.0 / 3.0) * 3.14 * (pow(r, 3)) << endl;
            break;


        }
        case 3: 
        {
            int r,h;
            cout << "Enter Radius: ";
            cin >> r;
            cout << "Enter Height: ";
            cin >> h;
            cout << "Enter Location : ";
            for (int i = 0; i < 3; i++)
            {
                cin >> location[i];
            }
            cout << "\nName: Cylinder " << endl;
            cout << "Location: (";
            for (int i = 0; i < 3; i++)
            {
                cout << location[i];
                if (i != 2)
                {
                    cout << ",";
                }
            }
            cout << ")" << endl;
            cout << "Radius: " << r << endl;
            cout << "Height: " << h << endl;
            cout << "Area:  " << 4 * 3.14 * (pow(r, 2)) << endl;
            cout << "Volume:" << (4.0 / 3.0) * 3.14 * (pow(r, 3)) << endl;
            break;

        }
        case 4: break;
        default:
        {
            cout << "### Invalid Option ###" << endl;
        }

        }
        break;
    }
}

Shape** readShapes(string filename, int& size) {
    ifstream Shapefile(filename);
    if (!Shapefile) {
        cout << "Failed to open the file: " << filename << endl;
        return nullptr;
    }
    Shapefile >> size;
    Shape** shapes = new Shape * [size];

    for (int i = 0; i < size; i++) 
    {
        string shapeType;
        Shapefile >> shapeType;
        if (shapeType == "Cube")
        {
        int loc[3], w, h, len;
        Shapefile >> loc[0] >> loc[1] >> loc[2] >> w >> h >> len;
        shapes[i] = new Cube(loc, w, h, len);
        }
        else if (shapeType == "Sphere") 
        {
            int r,loc[3];

            Shapefile >> r >> loc[0] >> loc[1] >> loc[2];
            shapes[i] = new Sphere(loc,r);
        }
        else if (shapeType == "Cylinder") 
        {
            int rad, hight, loc[3];
            Shapefile >> rad >> hight >> loc[0] >> loc[1] >> loc[2];
            shapes[i] = new Cylinder (loc,rad,hight);
        }
       
        else 
        {
            cout << "Invalid shape type: " << shapeType << endl;
            delete[] shapes;
            return nullptr;
        }
    }

    Shapefile.close();
    return shapes;
}

Shape* LargestVolumeShape(Shape* shape[], int& size)
{
    if (size <= 0||shape==nullptr)
    {
        return nullptr;
    }

    Shape* LargestVolumeShape = shape[0];
    float largestVolume = LargestVolumeShape->volume();
    for (int i = 1; i < size; i++)
    {
        float temp = shape[i]->volume();
        if (temp > largestVolume)
        {
            largestVolume = temp;
            LargestVolumeShape = shape[i];
            
        }
    }
    cout << "The Details Of The Shape Have The Largest Volume Is: " << endl;
    LargestVolumeShape->print();
    return 0;
    
}



int main()
{
    
    cout << "----------------------------------------------------------------------------------" << endl;
    int size;
    int loc[3];
    string filename = "Shapes.txt";
    Shape** shape = readShapes(filename, size);
    if (shape == nullptr)
    {
        cout << "Failed to read shapes from file." << endl;
    }

    for (int i = 0; i < size; i++)
    {
        
        shape[i]->print();
    }
    cout << "==================================================================================" << endl;
    LargestVolumeShape(shape, size);
    cout << "==================================================================================" << endl;
    Cube A;
    Cube B(loc, 3, 3, 3);
    B.print();
    cout << "==================================================================================" << endl;
    Sphere D;
    Sphere E(loc, 5);
    E.print();
    cout << "==================================================================================" << endl;
    Cylinder F;
    Cylinder G(loc, 5 , 7);
    G.print();
    cout << "==================================================================================" << endl;
    testShape();
    cout << "----------------------------------------------------------------------------------" << endl;

    return 0;
}