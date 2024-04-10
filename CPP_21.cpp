#include<iostream>
using namespace std;

bool search (int array[], int size, int key) {

    for (int i = 0; i < size; i++) {

        if (key == array[i]) {

            return 1;

        }
    }

    return 0;
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

    int key;

    cout << "Key: ";
    cin >> key;

    bool found = search(array,size,key);

    if (found) {

        cout << "The given key is present in the array." << endl;

    } else {

        cout << "The given key is absent in the array." << endl;
    }

    return 0;
}