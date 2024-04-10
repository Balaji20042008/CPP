#include<iostream>
#include <bits/stdc++.h>
using namespace std;

int binarySearch (int arr[], int n, int k) {

    int start = 0;
    int end = n - 1;

    while (start <= end) {

        int mid = start + (end - start) / 2;

        if (k == arr[mid]) {

            return mid;

        } else if (k > arr[mid]) {

            start = mid + 1;

        } else {

            end = mid - 1;

        }
    }

    return -1;

}

pair<int, int> firstAndLastPosition(int arr[], int n, int k) {

    int index = binarySearch(arr, n, k);

    int first = index;
    int last = index;

    if (index != -1) {

        while (arr[first] == k) {

            first--;
        }

        first++;

        while (arr[last] == k) {

            last++;
        }

        last--;

    } else {

        first = -1;
        last = -1;
    }

    pair<int, int> firstAndLast = {first, last};

    return firstAndLast;

}

int main() {

    int arr[1000];

    int n;

    cout << "Size : ";
    cin >> n;

    int k;

    cout << "K : ";
    cin >> k;

    cout << "Array : ";

    for (int i = 0; i < n; i++) {

        cin >> arr[i];
    }

    pair<int, int> pair = firstAndLastPosition(arr, n, k);

    cout << "First Occurence Index: " << pair.first << endl;
    cout << "Second Occurence Index: " << pair.second << endl;

    return 0;
}