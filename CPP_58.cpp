#include<iostream>
using namespace std;

int print(int n) {

    if (n == 0) {

        return 0;
    }

    print(n-1);

    cout << n << " ";

    return n;
}

int main() {

    int n;

    cout << "The value of 'n' is: ";
    cin >> n;

    print(n);

    cout << endl;

    return 0;
}