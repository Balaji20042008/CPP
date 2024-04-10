#include<iostream>
using namespace std;

int update_01 (int a) {

    a = 20;
}

void update_02 (int &a) {

    a = 20;
}

int main() {

    int i = 10;

    cout << "Before: " << i << endl;

    update_01(i);

    cout << "After: " << i  << endl;

    int j = 10;

    cout << "Before: " << j  << endl;

    update_02(j);

    cout << "After: " << j << endl;

    return 0;
}