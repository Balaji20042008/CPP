#include<iostream>
#include<vector>
using namespace std;

vector<int> wave_print(int arr[][100], int n, int m) {

    vector<int> ans;

    for (int col = 0; col < m; col++) {

        if (col & 1) {

            for (int row = n-1; row >= 0; row--) {

                ans.push_back(arr[row][col]);
            }

        } else {

            for (int row = 0; row < n; row++) {

                ans.push_back(arr[row][col]);
            }
        }
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

    vector<int> ans = wave_print(array, n, m);

    cout << "Wave Print: ";

    for (int i = 0; i < m * n; i++) {

        cout << ans[i] << " ";
    }

    cout << endl;

    return 0;
}