#include<iostream>
using namespace std;
int main() {

    int n;

    bool x = 1;

    cout << "The value of n is: ";
    cin >> n;

    if (n == 0 || n == 1) {

        cout << n << " is not a prime number";

    } else {

        for (int i = 2; i < n; i++) {
        if (n % i != 0) {
            continue;
        } else {
            x = 0;
            break;
        }
    }

    if (x == 1) {

        cout << n << " is a prime number." << endl;

    } else {

        cout << n << " is not a prime number." << endl;
        
    }
    }

    return 0;
}
