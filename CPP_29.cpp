#include<iostream>
using namespace std;

void pairSum (int array[], int size, int sum) {

    for (int i = 0; i < size; i++) {

        for (int j = 0; j < size; j++) {

            if (array[i] + array[j] == sum && i < j) {

                cout << "Pair : " << array[i] << " " << array[j] << endl;
            }
        }
    }
}


int main() {

    int n;

    cout << "Size : ";
    cin >> n;

    int sum;

    cout << "Sum : ";
    cin >> sum;

    int array[1000];

    cout << "Array : ";

    for (int i = 0; i < n; i++) {

        cin >> array[i];
    }

    pairSum (array, n, sum);

    return 0;
}
