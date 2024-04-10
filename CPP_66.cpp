#include<iostream>
using namespace std;

int power (int a, int b) {

    if (b == 0) {

        return 1;
    }

    if (b == 1) {

        return a;
    }

    int ans = power (a, b/2);

    if (b % 2 == 0) {

        return ans * ans;

    } else {

        return a * ans * ans;
    }
}

int main() {

    int base;

    cout << "Base: ";
    cin >> base;

    int exponent;

    cout << "Exponent: ";
    cin >> exponent; 

    cout << "Answer: " << power (base, exponent);

    return 0;
}