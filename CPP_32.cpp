#include<iostream>
using namespace std;

int binarySearch (int arr[], int size, int key) {

    int start = 0;
    int end = size - 1;

    while (start <= end) {

        int mid = start + (end - start) / 2;

        if (key == arr[mid]) {

            return mid;

        } else if (key > arr[mid]) {

            start = mid + 1;

        } else {

            end = mid - 1;

        }
    }

    return -1;


}

int main() {

    int even[6] = {2, 4, 6, 8, 10, 16};
    int odd[5] = {3, 8, 9, 13, 18};

    int evenIndex = binarySearch(even, 6, 10);

    cout << "Index at 10 is " << evenIndex << endl;

    int oddIndex = binarySearch(odd, 5, 9);

    cout << "Index at 9 is " << oddIndex << endl;


    return 0;
}