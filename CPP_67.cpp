#include<iostream>
using namespace std;

void bubble_sort (int *array, int n) {

    // base condition

    if (n == 0 || n == 1) {

        return;
    }

    for (int i = 0; i < n-1; i++) {

        if (array[i] > array[i+1]) {

            swap (array[i], array[i+1]);
        }
    }

    bubble_sort (array, n-1);
}

int main() {

    int n; 

    cout << "Size: ";
    cin >> n;

    int *array = new int[n];

    cout << "Array: ";

    for (int i = 0; i < n; i++) {

        cin >> array[i];
    }

    bubble_sort (array, n);

    cout << "Sorted Array: ";

    for (int i = 0; i < n; i++) {

        cout << array[i] << " ";
    }

    cout << endl;




    return 0;
}