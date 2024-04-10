#include<iostream>
using namespace std;

void fibonacci(int n, int a = 0, int b = 1) {

    int x;

    // Base Condition

    if (n == 0) {

        return;
    }

    n--;

    // Processing

    cout << a << " ";

    x = a;
    a = b;
    b = x + b;

    // Recursive Relation

    fibonacci(n, a, b);
}

int main() {

    int n;

    cout << "The value of 'n' is: ";
    cin >> n;

    fibonacci(n);


    return 0;
}