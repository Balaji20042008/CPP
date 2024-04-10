#include<iostream>
#include <bits/stdc++.h>
using namespace std;

void print_array (int array[], int n) {

    for (int i = 0; i < n; i++) {

        cout << array[i] << " ";
    }
}

void selection_sort (int array[], int n)
{   
    for (int i = 0; i < n; i++) {

        int minimum = INT_MAX;

        for (int j = i + 1; j < n; j++) {

            minimum = min (minimum, array[j]);
        }

        for (int k = i + 1; k < n; k++) {

            if (array[i] > minimum && minimum == array[k]) {

                swap (array[i], array[k]);
            }
        }
    }
}

int main() {

    int array[5] = {64, 25, 12, 22, 11};

    cout << "Original Array : ";
    
    print_array (array, 5);
    
    cout << endl;

    selection_sort (array, 5);

    cout << "Sorted Array : ";
    
    print_array (array, 5);
    
    cout << endl;

    return 0;
}