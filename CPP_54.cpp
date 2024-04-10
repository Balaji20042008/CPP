#include<iostream>
using namespace std;

void update (int **p) {

    // p = p + 1;

    // *p = *p + 1;

    // **p = **p + 1;
}

int main() {

    int a = 5;
    int *p = &a;
    int **q = &p;

    // cout << "1." << a << endl;
    // cout << "2." << *p << endl;
    // cout << "3." << **q << endl;

    // cout << "4." << &a << endl;
    // cout << "5." << p << endl;
    // cout << "6." << *q << endl;

    // cout << "7." << &p << endl;
    // cout << "8." << q << endl;

    cout << "Before: " << a << endl;
    cout << "Before: " << p << endl;
    cout << "Before: " << q << endl;

    update(q);

    cout << "After: " << a << endl;
    cout << "After: " << p << endl;
    cout << "After: " << q << endl;

    return 0;
}