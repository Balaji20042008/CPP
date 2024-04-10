#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector <int> arrayIntersection (int array_01[], int array_02[], int x, int y) {

    vector <int> intersection;

    int i = 0;
    int j = 0;

    while (i < x && j < y) {

        if (array_01[i] == array_02[j]) {

            intersection.push_back(array_01[i]);

            i++; j++;

        } else if (array_01[i] < array_02[j]) {

            i++;

        } else {

            j++;

        }
    }

    if (intersection.empty()) {

        intersection.push_back(-1);
    }

    return intersection;


}

int main() {

    int x;

    cout << "The value of 'x' is : ";
    cin >> x;

    int y;

    cout << "The value of 'y' is : ";
    cin >> y;

    int array_01[100];

    cout << "Array 01 : ";

    for (int i = 0; i < x; i++) {

        cin >> array_01[i];

    }

    int array_02[100];

    cout << "Array 02 : ";

    for (int i = 0; i < y; i++) {

        cin >> array_02[i];

    }

    vector <int> intersection = arrayIntersection (array_01, array_02, x , y);

    cout << "Intersection Array : ";

    for (int i = 0; i < intersection.size(); i++) {

        cout << intersection[i] << " ";

    }




    return 0;
}