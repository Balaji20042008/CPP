#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool check (int nums[], int n) {

    int count = 0;
    bool x = 1;

    for (int i = 0; i < n - 1; i++) {

        if (nums[i] <= nums[i+1]) {

            if (count == 0) {

                continue;
            }

        } else {

            count++;
        }

        if (count == 1 && nums[i+1] <= nums[0]) {

            x = 1;

        } else {

            x = 0;
            break;
        }
    }

    return x;
        
}

int main() {

    int array[5] = {1, 1, 1, 1, 1};

    if (check (array, 5)) {

        cout << "The given array is sorted and rotated.";

    } else {

        cout << "The given array is not sorted and rotated.";
    }


    return 0;
}