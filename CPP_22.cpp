#include<iostream>
using namespace std;

void printArray (int array[], int size) {

    for (int i = 0; i < size; i++) {

        cout << array[i] << " ";

    }

    cout << endl;
}

void swapAlternateArray (int array[], int size) {

    for (int i = 0; i < size; i = i + 2) {

        if (i+1 < size) {

            swap (array[i], array[i+1]);

        }
    }
}


int main() {

    int size;

    cout << "Size: ";
    cin >> size;

    int array[100];

    cout << "Original Array: ";

    for (int i = 0; i < size; i++) {

        cin >> array[i];
    }

    swapAlternateArray(array,size);

    cout << "Updated Array: ";

    printArray(array,size);

    return 0;
}
