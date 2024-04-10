#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void findDuplicate (int array[], int size) {

    vector<int> vector;

    for (int i = 0; i < size; i++) {

        int count = 0;

        for (int j = 0; j < size; j++) {

            if (array[i] == array[j]) {

                count++;

            }
        }

        if (count > 1) {

            if (std :: count (vector.begin(), vector.end(), array[i])) {

                continue;

            } else {

                vector.push_back(array[i]);
            }

        }
    }

    cout << "Duplicate Array: ";

    for (int i = 0; i < vector.size(); i++) {

        cout << vector[i] << " ";

    }

    cout << endl;
}


int main() {

    int size;

    cout << "Size: ";
    cin >> size;

    int array[100];

    cout << "Original Array: ";

    for (int i = 0; i < size; i++) {

        cin >> array[i];

    }

    findDuplicate(array,size);

    return 0;

}