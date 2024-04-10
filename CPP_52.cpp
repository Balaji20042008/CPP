#include<iostream>
using namespace std;

int gcd (int &a, int  &b) {

    if (a == 0) {

        return b;

    }
    
    if  (b == 0) {

        return a;

    }


     while (a != b) {

        if (a > b) {

            a = a - b;

        } else {

            b = b - a;
        }
    }

    return a;
}

int lcm  (int &a, int &b) {

    int ans = (a*b) / gcd(a,b);

    return ans;
}


int main() {

    int a;

    cout << "The value of 'a' is: ";
    cin >> a;

    int *p = &a;

    int b;

    cout << "The value of 'b' is: ";
    cin >> b;

    int *q = &b;

    // Call by Value

    // cout << "HCF of " << a << " & " << b << " is: " << gcd(a,b) << endl;
    // cout << "LCM of " << a << " & " << b << " is: " << lcm(a,b) << endl;

    // cout << "The value of 'a' is: " << a << endl;
    // cout << "The value of 'b' is: " << b << endl;

    // Call by Reference

    cout << "HCF of " << a << " & " << b << " is: " << gcd(*p,*q) << endl;
    cout << "LCM of " << a << " & " << b << " is: " << lcm(*p,*q) << endl;

    cout << "The value of 'a' is: " << a << endl;
    cout << "The value of 'b' is: " << b << endl;
}