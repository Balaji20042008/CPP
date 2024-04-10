#include<iostream>
using namespace std;

bool binarySearch (int *array, int n, int key, int start, int end) {

    if (start > end) {

        return false;
    }

    int mid = start + (end-start) / 2;

    if (array[mid] == key) {

        return true;
    }

    if (array[mid] < key) {

        start = mid + 1;

        return binarySearch (array, n, key, start, end);

    } else {

        end = mid - 1;

        return binarySearch (array, n, key, start, end);
    }
}

int main () {

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

    int start = 0;
    int end = n - 1;

    bool ans = binarySearch (array, n, key, start, end);

    if (ans) {

        cout << "Key is Present." << endl;

    } else {

        cout << "Key is Absent." << endl;
    }

    return 0;
}