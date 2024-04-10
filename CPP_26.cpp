#include<iostream>
using namespace std;

int findDuplicate (int array[], int size) {

    for (int i = 0; i < size; i++) {

        int count = 0;

        for (int j = 0; j < size; j++) {

            if (array[i] == array[j]) {

                count++;

            }
        }

        if (count > 1) {

           return array[i]; 
        }
    }

    return 0;
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

    int duplicate = findDuplicate(array,size);

    cout << "Duplicate Number: " << duplicate << endl;

    return 0;
}