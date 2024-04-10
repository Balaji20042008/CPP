#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int maximum (int left, int right, vector<int> &array) {

    int max = INT_MIN;

    for (int i = left; i <= right; i++) {

        if (array[i] > max) {

            max = array[i];
        }
    }

    return max;
}

int recursion (int left, int right, vector<int> &array) {

    if (left == right) {

        return 0;
    }

    int ans = INT_MAX;

    for (int k = left; k < right; k++) {

        ans = min (ans, maximum(left, k, array) * maximum(k+1, right, array) + recursion(left, k, array) + recursion(k+1, right, array));
    }

    return ans;
}

int main () {

    vector<int> array = {4, 11};

    int n = array.size() - 1;

    cout << "The smallest possible sum of the values of each non-leaf node is: " << recursion(0,n,array) << endl;

    return 0;
}