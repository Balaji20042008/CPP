#include<iostream>
#include<bits/stdc++.h>
using namespace std;

long long int floorSqrt(int n) {

    int start = 0;
    int end = n;

    long long int mid = start + (end-start) / 2;

    long long int ans;

    while (start <= end) {

        long long square = mid * mid;

        if (square > n) {

            end = mid - 1;

        } else if (square == n) {

            return mid;

        } else {

            ans = mid;

            start = mid + 1;
        }

        mid = start + (end-start) / 2;
    }

    return ans;
}

double morePrecision (int n, int precision, int integer) {

    double factor = 1;
    double ans = integer;

    for (int i = 1; i <= precision; i++) {

        factor = factor/10;

        for (double j = ans; j*j < n; j = j + factor) {

            ans = j;
        }
    }

    return ans;
}

int main() {

    int n;

    cout << "The value of 'n' is: ";
    cin >> n;

    int integer = floorSqrt(n);

    cout << "Sqrt of " << n << " is " << morePrecision(n, 3, integer);


}