#include<iostream>
#include<math.h>
using namespace std;

#define pi 3.14

int main() {

    float r;

    cout << "Radius of the Cylinder: ";
    cin >> r;

    float h;

    cout << "Height of the Cylinder: ";
    cin >> h;

    float curved_area = 2 * pi * r * h;
    float circle_area = pi * r * r;
    float total_area =  curved_area + (2 * circle_area);
    float total_volume = pi * r * r * h;

    cout << "Curved Surface Area: " << curved_area << endl;
    cout << "Total Surface Area: " << total_area << endl;
    cout << "Volume of the Cylinder: " << total_volume << endl; 
}