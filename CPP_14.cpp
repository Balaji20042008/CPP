#include<iostream>
using namespace std;

// Power Function

// int power () {

//     int a;

//     cout << "Base: ";
//     cin >> a;

//     int b;

//     cout << "Exponent: ";
//     cin >> b;

//     int p = 1;

//     for (int i = 1; i <= b; i++) {

//         p = p * a;

//     }

//     return p;

// }

// nCr Function

// int factorial (int n) {

//     int p = 1;

//     for (int i = 1; i <= n; i++) {

//         p = p * i;

//     }

//     return p;
// }

// float nCr () {

//     int n;

//     cout << "n: ";
//     cin >> n;

//     int r;

//     cout << "r: ";
//     cin >> r;

//     float numerator = factorial(n);
//     float denominator = factorial(r) * factorial(n-r);
//     float result = numerator / denominator;

//     return result;
// }

int main() {

    // Power Function

    int x = power();

    cout << "Answer: " << x << endl;

    int y = power();

    cout << "Answer: " << y << endl;

    // nCr Function

    // float x = nCr();

    // cout << "answer: " << x << endl;

    // float y = nCr();

    // cout << "answer: " << y << endl;

    return 0;

}