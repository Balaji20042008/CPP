#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int search (int arr[], int n, int k) {

    int start = 0;
    int end = n - 1;

    int mid = start + (end-start) / 2;

    while (start <= end) {

        if (arr[mid] > arr[0] && k >= arr[0]) {

            if (k == arr[mid]) {

                return mid;

            } else if (k > arr[mid]) {

                start = mid + 1;

            } else {

                end = mid - 1;
            }

        } else if (arr[mid] > arr[0] && k <= arr[0]) {

            start = mid + 1;

        } else if (arr[mid] < arr[0] && k >= arr[0]) {

            end = mid;

        } else {

            if (k == arr[mid]) {

                return mid;

            } else if (k > arr[mid]) {

                start = mid + 1;

            } else {

                end = mid - 1;
            }
        }

        mid = start + (end-start) / 2;
    }

    return -1;
}

int main() {

    int arr[6] = {6, 7, 9, 1, 3, 4};

    int index = search (arr, 6, 7);

    cout << "Index at 7 is " << index << endl;
}