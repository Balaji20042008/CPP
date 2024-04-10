#include<iostream>
#include<vector>
using namespace std;

vector<int> spiral_print(int matrix[][100], int n, int m) {

        vector<int> ans;

        int count = 0;
        int total = m*n;

        int startingRow = 0;
        int endingCol = m-1;
        int endingRow = n-1;
        int startingCol = 0;

        while (count < total) {

            for (int index = startingCol; count < total && index <= endingCol; index++) {

                ans.push_back(matrix[startingRow][index]);
                count++;
            }

            startingRow++;

            for (int index = startingRow; count < total && index <= endingRow; index++) {

                ans.push_back(matrix[index][endingCol]);
                count++;
            }

            endingCol--;

            for (int index = endingCol; count < total && index >= startingCol; index--) {

                ans.push_back(matrix[endingRow][index]);
                count++;
            }

            endingRow--;

            for (int index = endingRow; count < total && index >= startingRow; index--) {

                ans.push_back(matrix[index][startingCol]);
                count++;
            }

            startingCol++;
        }

        return ans;
}

int main() {

    int array[100][100];

    int n;

    cout << "No. of Rows: ";
    cin >> n;

    int m;

    cout << "No. of Columns: ";
    cin >> m;

    cout << "Elements in 2D Array: ";

    for (int i = 0; i < n; i++) {

        for (int j = 0; j < m; j++) {

            cin >> array[i][j];

        }
    }

    for (int i = 0; i < n; i++) {

        for (int j = 0; j < m; j++) {

            cout << array[i][j] << " ";
        }

        cout << endl;
    }

    vector<int> ans = spiral_print(array, n, m);

    cout << "Spiral Print: ";

    for (int i = 0; i < m * n; i++) {

        cout << ans[i] << " ";
    }

    cout << endl;

    return 0;
}