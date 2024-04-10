#include<iostream>
using namespace std;

void selection_sort (int *array, int n) {

    // base condition

    if (n == 0 || n == 1) {

        return;
    }

    int min_index = 0;

    for (int i = 1; i < n; i++) {

        if (array[min_index] > array[i]) {

            min_index = i;
        }
    }

    swap(array[0], array[min_index]);

    // recursive call

    selection_sort (array + 1, n - 1);
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

    selection_sort (array, n);

    cout << "Sorted Array: ";

    for (int i = 0; i < n; i++) {

        cout << array[i] << " ";
    }

    cout << endl;

    return 0;
}