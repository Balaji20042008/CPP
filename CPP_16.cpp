#include<iostream>
using namespace std;

int fibonacci (int n) {

    int a = 0;
    int b = 1;

    int s;

    for (int i = 1; i < n; i++) {

        s = a + b;
        a = b;
        b = s;

    }

    return a;
}

int main () {

    int n;

    cout << "No. of Terms: ";
    cin >> n;

    int answer = fibonacci(n);

    cout << n << "th term of the fibonacci series is: " << answer << endl;

    return 0;
}