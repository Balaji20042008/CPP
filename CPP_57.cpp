#include<iostream>
using namespace std;
int main() {

    int row;

    cout << "Rows: ";
    cin >> row;

    cout << "Size: ";

    int *size = new int[row];

    for (int i = 0; i < row; i++) {

        cin >> size[i];
    }

    // creating a 2D array dynamically

    int **array = new int*[row];

    for (int i = 0; i < row; i++) {

        array[i] = new int[size[i]];
    }

    // 2D array input

    cout << "Jagged 2D Array: ";

    for (int i = 0; i < row; i++) {

        for (int j = 0; j < size[i]; j++) {

            cin >> array[i][j];
        }
    }

    // 2D array output

    for (int i = 0; i < row; i++) {

        for (int j = 0; j < size[i]; j++) {

            cout << array[i][j] << " ";
        }

        cout << endl;
    }

    // releasing memory

    for (int i = 0; i < row; i++) {

        delete [] array[i];
    }

    delete [] array;
    delete [] size;


    return 0;
}