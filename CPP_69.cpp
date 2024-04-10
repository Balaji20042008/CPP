#include<iostream>
using namespace std;

int main() {

    int n;

    cout << "Size: ";
    cin >> n;

    int *array = new int[n];

    cout << "Array: ";

    for (int i = 0; i < n; i++) {

        cin >> array[i];
    }

    insertion_sort (array, n);

    cout << "Sorted Array: ";

    for (int i = 0; i < n; i++) {

        cout << array[i] << " ";
    }

    cout << endl;

    return 0;
}