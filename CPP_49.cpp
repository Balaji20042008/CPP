#include<iostream>
#include<vector>
using namespace std;

bool linear_search (int array[][100], int key, int n, int m) {

    for (int i = 0; i < n; i++) {

        for (int j = 0; j < m; j++) {

            if (array[i][j] == key) {

                return 1;
            }
        }
    }

    return 0;
}

void largest_row (vector<int> &array, int n) {

    int max = array[0];
    int index = 0;

    for (int i = 0; i < n; i++) {

        if (max < array[i]) {

            max = array[i];
            index = i;
        }
    }

    cout << "Maximum Row Addition: " << max << endl;
    cout << "Row Number of Maximum: " << index << endl;
}

void largest_column (vector<int> &array, int n) {

    int max = array[0];
    int index = 0;

    for (int i = 0; i < n; i++) {

        if (max < array[i]) {

            max = array[i];
            index = i;
        }
    }

    cout << "Maximum Column Addition: " << max << endl;
    cout << "Column Number of Maximum: " << index << endl;
}

void row_addition (int array[][100], int n, int m ) {

    vector <int> row;

    for (int i = 0; i < n; i++) {

        int sum = 0;

        for (int j = 0; j < m; j++) {

            sum = sum + array[i][j];

        }

        cout << "Row " << i << ": "<< sum << endl;

        row.push_back(sum);
    }

    largest_row (row, n);
}

void column_addition (int array[][100], int n, int m) {

    vector<int> column;
 
    for (int i = 0; i < m; i++) {

        int sum = 0;

        for (int j = 0; j < n; j++) {

            sum = sum + array[j][i];
        }

        cout << "Column " << i << ": " << sum << endl;

        column.push_back(sum);
    }

    largest_column (column, m);
}

int main () {

    int array[100][100];

    int n;

    cout << "No. of Rows: ";
    cin >> n;

    int m;

    cout << "No. of Columns: ";
    cin >> m;

    cout << "Elements in 2D Array: ";

    // Row Input

    for (int i = 0; i < n; i++) {

        for (int j = 0; j < m; j++) {

            cin >> array[i][j];

        }
    }

    // Column Input

   /* for (int i = 0; i < m; i++) {

        for (int j = 0; j < n; j++) {

            cin >> array[j][i];

        }
    } 
*/

    for (int i = 0; i < n; i++) {

        for (int j = 0; j < m; j++) {

            cout << array[i][j] << " ";
        }

        cout << endl;
    }

    int key;

    cout << "The value of key is: ";
    cin >> key;

    bool check = linear_search(array, key, n, m);

    if (check) {

        cout << "The key is present in the 2D Array." << endl;

    } else {

        cout << "The key is not present in the 2D Array." << endl;
    }

    row_addition (array, n, m);
    column_addition (array, n, m);

    return 0;
}