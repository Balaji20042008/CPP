#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int pivotIndex (int arr[], int n) {

    int start = 0;
    int end = n - 1;

    int mid = start + (end-start) / 2;

    while (start < end) {

        if (arr[mid] >= arr[0]) {

            start = mid + 1;

        } else {

            end = mid;
        }

        mid = start + (end-start) / 2;
    }

    return mid;
}

int main() {

    int arr[6] = {6, 7, 9, 1, 3, 4};

    int pivot = pivotIndex(arr, 6);

    cout << "Pivot Index : " << pivot << endl;

    return 0;
}