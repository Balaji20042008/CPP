#include<iostream>
using namespace std;

int getMax (int array[], int size) {

    int max = INT_MIN;

    for (int i = 0; i < size; i++) {

        if (array[i] > max) {

            max = array[i];

        }
    }

    return max;
}

int getMin (int array[], int size) {

    int min = INT_MAX;

    for (int i = 0; i < size; i++) {

        if (array[i] < min) {

            min = array[i];

        }
    }

    return min;
}


int main() {

    int size;

    cout << "Size: ";
    cin >> size;

    cout << "Array: ";

    int num[100];

    for (int i = 0; i < size; i++) {

        cin >> num[i];

    }

    cout << "Maximum: " << getMax(num,size) << endl;
    cout << "Minumum: " << getMin(num,size) << endl;



    return 0;
}