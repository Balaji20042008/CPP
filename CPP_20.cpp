#include<iostream>
using namespace std;

void reverseOfArray (int array[], int size) {

    int swap;
    int start = 0;
    int end = size - 1;

    while (start <= size / 2) {

        swap = array[start]; 
        array[start] = array[end];
        array[end] = swap;

        start++;
        end--;
    }

    cout << "Reverse Array: ";

    for (int i = 0; i < size; i++) {

        cout << array[i] << " ";
    }

    cout << endl;
}

int main() {

    int size;

    cout << "Size: ";
    cin >> size;

    int array[100];

    cout << "Array: ";

    for (int i = 0; i < size; i++) {

        cin >> array[i];

    }

    reverseOfArray(array,size);

    return 0;
}