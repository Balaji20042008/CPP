#include<iostream>
using namespace std;

bool linear_search (int array[], int n, int key) {

    // base conditon

    if (n == 0) {

        return 0;
    }

    // recursive relation

    if (array[0] == key) {

        return 1;

    } else {

        return linear_search (array + 1, n - 1, key);
    }
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

    int key;

    cout << "Key: ";
    cin >> key;

    bool check = linear_search (array, n, key);

    if (check) {

        cout << "Key is Present." << endl;

    } else {

        cout << "Key is Absent." << endl;
    }

    return 0;
}