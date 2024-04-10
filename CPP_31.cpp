#include<iostream>
using namespace std;

void printArray (int array[], int size) {

    cout << "Sorted Array : ";

    for (int i = 0; i < size; i++) {

        cout << array[i] << " ";
        
    }

    cout << endl;
}

void sortZeroOneTwo (int array[], int size) {

    int i = 0;
    int j = size - 1;

    while (i < j) {

        if (array[i] == 0 && i < j) {

            i++;

        }

        if (array[j] != 0 && i < j) {

            j--;

        }

        if (array[i] != 0 && array[j] == 0 && i < j) {

            swap (array[i], array[j]);

            i++; j--;

        }
    }

    int x = i;
    int y = size - 1;

    while (x < y) {

        if (array[x] == 1 && x < y) {

            x++;

        }

        if (array[y] == 2 && x < y) {

            y--;

        }

        if (array[x] == 2 && array[y] == 1 && x < y) {

            swap (array[x], array[y]);

            x++; y--;
        }
    }
}


int main() {

    int n;

    cout << "Size : ";
    cin >> n;

    int array[100];

    cout << "Initial Array : ";

    for (int i = 0; i < n; i++) {

        cin >> array[i];

    }

    sortZeroOneTwo (array, n);
    printArray (array, n);

    return 0;
}