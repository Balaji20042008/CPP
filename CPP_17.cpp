#include<iostream>
using namespace std;

int progression (int n) {

    int s;

    for (int i = 1; i <= n; i++) {

        s = 3 * i + 7;

        if (i == n) {

            return s;

        } 
    }

    return 0;
}

int main () {

    int n;

    cout << "No. of Terms: ";
    cin >> n;

    cout << n << "th term of the series is: " << progression(n) << endl;

    return 0;
}