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

void move_zeroes (int array [], int n) {

    
    int i = 0;

    for (int j = 0; j < n; j++) {

        if (array [j] != 0) {

            swap (array [j], array [i]);

            i++;
        }
    }
}

int main () {

    int n;

    cout << "Size: ";
    cin >> n;

    int array [1000];

    cout << "Original Array: ";

    for (int i = 0; i < n; i++) {

        cin >> array [i];
    }

    move_zeroes (array, n);

    cout << "Updated Array: ";

    print_array (array, n);


    return 0;
}