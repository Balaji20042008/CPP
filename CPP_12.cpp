#include<iostream>
#include<cmath>
using namespace std;
int main() {

    // Decimal --> Binary

    // int n;
    // int r;

    // cout << "Decimal Number: ";
    // cin >> n;

    // int ans = 0;

    // for (int i = 0; n > 0; i++) {

    //     r = n % 2;
    //     ans = ans + (pow(10,i) * r);
    //     n = n / 2;

    // }

    // cout << "Binary Number: " << ans << endl;

    // Reverse of an Integer

    // int n;
    // int r;

    // cout << "Original Integer: ";
    // cin >> n;

    // int s = 0;

    // for (int i = 0; n > 0; i++) {

    //     if ((s > INT_MAX/10) || (s < INT_MIN/10)) {

    //         return 0;
    //     }

    //     r = n % 10;
    //     s = r + s * 10;
    //     n = n / 10;

    // }

    // cout << "Reverse Integer: " << s << endl;

    // Binary --> Decimal

    // int n;
    // int r;

    // cout << "Binary Number: ";
    // cin >> n;

    // int s = 0;

    // for (int i = 0; n > 0; i++) {

    //     r = n % 10;
    //     s = s + pow(2,i) * r;
    //     n = n / 10;

    // }

    // cout << "Decimal Number: " << s << endl;

    // Compliment of Base-10 Integer 

    // int n;
    // int r;

    // cout << "Original Number: ";
    // cin >> n;

    // int s = 0;

    // for (int i = 0; n > 0; i++) {

    //     r =  n % 2;

    //     if (n & 1 == 1) {

    //         r = 0;

    //     } else {

    //         r = 1;
    //     }

    //     s = s + pow(10,i) * r;
    //     n = n / 2;

    // }

    // int t = 0;

    // for (int i = 0; s > 0; i++) {

    //     r = s % 10;
    //     t = t + pow(2,i) * r;
    //     s = s / 10;

    // }

    // cout << "Compliment Number: " << t << endl;

    // Power of 2

    int n;

    cout << "The value of 'n' is: ";
    cin >> n;

    bool x;

    for (int i = 0; n >= pow(2,i); i++) {

        x = (n == pow(2,i));
    }

    if (x == 1) {

        cout << "The given number is a power of 2." << endl;

    } else {

        cout << "The given number is not a power of 2." << endl;
    }

    return 0;
}