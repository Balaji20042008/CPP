#include<iostream>
using namespace std;

int sum (int array[], int size) {

    int s = 0;

    for (int i = 0; i < size; i++) {

        s = s + array[i];

    }

    return s;
}


int main() {

    int size;

    cout << "Size: ";
    cin >> size;

    int num[100];

    cout << "Array: ";

    for (int i = 0; i < size; i++) {

        cin >> num[i];

    }

    cout << "Sum: " << sum(num,size) << endl;


    return 0;
}