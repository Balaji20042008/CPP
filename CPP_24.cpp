#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool uniqueNoOfOccurences (int array[], int size) {

    vector<int> vector;

    for (int i = 0; i < size; i++) {

        int count = 0;

        for (int j = 0; j < size; j++) {

            if (array[i] == array[j]) {

                count = count + 1;

            }
        }

       vector.push_back(count);


    }

    for (int i = 0; i < size; i++) {

        for (int j = 0; j < size; j++) {

            if (vector[i] == vector[j]) {

                if (array[i] != array[j]) {

                    return 0;

                }

            }
        }
    }

    return 1;


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

    bool answer = uniqueNoOfOccurences(array,size);

    if (answer) {

        cout << "True" << endl;

    } else {

        cout << "False" << endl;
    }
}