#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int peakIndexInMountainArray (int arr[], int n) {

    int start = 0;
    int end = n - 1;

    int mid = start + (end-start) / 2;

    while (start < end) {

        if (arr[mid] < arr[mid+1]) {

            start = mid + 1;

        } else {

            end = mid;
        }

        mid = start + (end-start) / 2;
    }

    return mid;
}

int main() {

    int mountainArray[6] = {3, 4, 5, 9, 6, 1};

    int peakIndex = peakIndexInMountainArray (mountainArray, 6);

    cout << "Peak Index : " << peakIndex << endl;

    return 0;
}