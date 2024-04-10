#include<iostream>
using namespace std;

int findUnique (int array[], int size) {

    for (int i = 0; i < size; i++) {

        int count = 0;

        for (int j = 0; j < size; j++) {

            if (array[i] == array[j]) {

                count = count + 1;

            }
        }

        if (count == 1) {

            return array[i];
        }
    }

    return 0;
}


int main() {

    int m;

    cout << "The value of 'm' is: ";
    cin >> m;

    int size = 2 * m + 1;

    int array[100];

    cout << "Original Array: ";

    for (int i = 0; i < size; i++) {

        cin >> array[i];

    }

    int unique = findUnique(array,size);

    cout << "Unique Element: " << unique << endl;
}