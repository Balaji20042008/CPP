#include<iostream>
#include<math.h>
#include<bits/stdc++.h>
using namespace std;

void print_array (int array [], int n) {

    for (int i = 0; i < n; i++) {

        cout << array [i] << " ";
    }

    cout << endl;
}

void merge_sorted_array (int array_01 [], int n, int array_02 [], int m, int array_03 []) {

    int i = 0;
    int j = 0;
    int k = 0;

    while (i < n && j < m && k < m + n) {

         if (array_01 [i] < array_02 [j] && i < n) {

            array_03 [k] = array_01 [i];

            i = i + 1;
            k = k + 1;

        } else if (array_01 [i] == array_02 [j] && i < n && j < m) {

            array_03 [k] = array_01 [i];
            array_03 [k+1] = array_02 [j];

            i = i + 1;
            j = j + 1;
            k = k + 2;

        } else {

            array_03 [k] = array_02 [j];

            j = j + 1;
            k = k + 1;
        }
    }

    int x = min (m, n);

    if (x == m) {

        while (i < n) {

            array_03 [k] = array_01 [i];

            i = i + 1;
            k = k + 1;
        }

    } else {

        while (j < m) {

            array_03 [k] = array_02 [j];

            j = j + 1;
            k = k + 1;
        }

    }
}



int main () {

    int n;

    cout << "The size of 1st Array: ";
    cin >> n;

    int m;

    cout << "The size of 2nd Array: ";
    cin >> m;

    int array_01 [1000];
    int array_02 [1000];

    cout << "Array 01: ";

    for (int i = 0; i < n; i++) {

        cin >> array_01 [i];
    }

    cout << "Array 02: ";

    for (int i = 0; i < m; i++) {

        cin >> array_02 [i];
    }

    int array_03 [1000];

    merge_sorted_array (array_01, n , array_02, m, array_03);

    cout << "Array 03: ";

    print_array (array_03, m + n);


    return 0;
}