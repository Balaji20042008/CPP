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

void merge_sorted_array (int nums1[], int m, int nums2[], int n) {

    for (int i = 0; i < n; i++) {

        int temporary = nums2[i];

        int j = m + i - 1;

        while (j >= 0) {

            if (nums1[j] > temporary) {

                nums1[j+1] = nums1[j];

                j--;

            } else {

                break;
            }
        }

        nums1[j+1] = temporary;
    }
        
 }


int main () {

    int m;

    cout << "The size of 1st Array: ";
    cin >> m;

    int n;

    cout << "The size of 2nd Array: ";
    cin >> n;

    int array_01 [1000];
    int array_02 [1000];

    cout << "Array 01: ";

    for (int i = 0; i < m + n; i++) {

        cin >> array_01 [i];
    }

    cout << "Array 02: ";

    for (int i = 0; i < n; i++) {

        cin >> array_02 [i];
    }

    merge_sorted_array (array_01, m , array_02, m);

    cout << "Merge Sorted Array: ";

    print_array (array_01, m + n);


    return 0;
}