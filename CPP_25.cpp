#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {

    vector<int> vector;

    int n;

    cout << "Size: ";
    cin >> n;

    int a;

    cout << "Vector: ";

    for (int i = 0; i < n; i++) {

        cin >> a;
        vector.push_back(a);

    }

    cout << "Vector: ";

    for (auto &p : vector) {

        cout << p << " ";

    }

    cout << endl;

    cout << "Capacity: " << vector.capacity() << endl;

}