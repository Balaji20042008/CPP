#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int recursion (vector<vector<int>> &matrix, int i, int j, int &maxi) {

    if (i >= matrix.size() || j >= matrix[0].size()) {

        return 0;
    }

    int right = recursion (matrix, i, j + 1, maxi);
    int diagonal = recursion (matrix, i + 1, j + 1, maxi);
    int down = recursion (matrix, i + 1, j, maxi);

    if (matrix[i][j] == 1) {

        int answer = 1 + min (right, min (diagonal, down));
        maxi = max (maxi, answer);
        return answer;

    } else {

        return 0;
    }
}

int memoization (vector<vector<int>> &matrix, int i, int j, int &maxi, vector<vector<int>> &dp) {

    if (i >= matrix.size() || j >= matrix[0].size()) {

        return 0;
    }

    if (dp[i][j] != -1) {

        return dp[i][j];
    }

    int right = recursion (matrix, i, j + 1, maxi);
    int diagonal = recursion (matrix, i + 1, j + 1, maxi);
    int down = recursion (matrix, i + 1, j, maxi);

    if (matrix[i][j] == 1) {

        dp[i][j] = 1 + min (right, min (diagonal, down));
        maxi = max (maxi, dp[i][j]);
        return dp[i][j];

    } else {

        dp[i][j] = 0;
        return dp[i][j];
    }
}

int tabulation (vector<vector<int>> &matrix, int &maxi) {

    int n = matrix.size();
    int m = matrix[0].size();

    vector<vector<int>> dp(n, (vector<int>(m, -1)));

    for (int i = n-1; i >= 0; i--) {

        for (int j = m-1; j >= 0; j--) {

            int right = 0;

            if (j + 1 < m) {

                right = dp[i][j+1];
            }

            int diagonal = 0;

            if (i + 1 < n && j + 1 < m) {

                diagonal = dp[i+1][j+1];
            }

            int down = 0;

            if (i + 1 < n) {

                down = dp[i+1][j];
            }

            if (matrix[i][j] == 1) {

                dp[i][j] = 1 + min (right, min (diagonal, down));
                maxi = max (maxi, dp[i][j]);

            } else {

                dp[i][j] = 0;
            }
        }
    }

    return dp[0][0];
}

int optimisation_01 (vector<vector<int>> &matrix, int &maxi) {

    int n = matrix.size();
    int m = matrix[0].size();

    vector<int> curr(m,0);
    vector<int> next(m,0);

    for (int i = n-1; i >= 0; i--) {

        for (int j = m-1; j >= 0; j--) {

            int right = 0;

            if (j + 1 < m) {

                right = curr[j+1];
            }

            int diagonal = 0;

            if (i + 1 < n && j + 1 < m) {

                diagonal = next[j+1];
            }

            int down = 0;

            if (i + 1 < n) {

                down = next[j];
            }

            if (matrix[i][j] == 1) {

                curr[j] = 1 + min (right, min (diagonal, down));
                maxi = max (maxi, curr[j]);

            } else {

                curr[j] = 0;
            }
        }

        next = curr;
    }

    return next[0];
}

int optimisation_02 (vector<vector<int>> &matrix, int &maxi) {

    int n = matrix.size();
    int m = matrix[0].size();

    for (int i = n-1; i >= 0; i--) {

        for (int j = m-1; j >= 0; j--) {

            int right = 0;

            if (j + 1 < m) {

                right = matrix[i][j+1];
            }

            int diagonal = 0;

            if (i + 1 < n && j + 1 < m) {

                diagonal = matrix[i+1][j+1];
            }

            int down = 0;

            if (i + 1 < n) {

                down = matrix[i+1][j];
            }

            if (matrix[i][j] == 1) {

                matrix[i][j] = 1 + min (right, min (diagonal, down));
                maxi = max (maxi, matrix[i][j]);

            } else {

                matrix[i][j] = 0;
            }
        }
    }

    return matrix[0][0];
}

int main () {

    vector<vector<int>> matrix = {{1,1,1,0},{1,1,1,1},{1,1,1,1},{1,1,1,0}};

    int n = matrix.size();
    int m = matrix[0].size();

    int maxi = 0;

    recursion (matrix, 0, 0, maxi);

    cout << "The size of the maximum sub square matrix with all 1's is: " << maxi << endl;

    maxi = 0;

    vector<vector<int>> dp(n, vector<int>(m, -1));

    memoization (matrix, 0, 0, maxi, dp);

    cout << "The size of the maximum sub square matrix with all 1's is: " << maxi << endl;

    maxi = 0;

    tabulation (matrix, maxi);

    cout << "The size of the maximum sub square matrix with all 1's is: " << maxi << endl;

    maxi = 0;

    optimisation_01 (matrix, maxi);

    cout << "The size of the maximum sub square matrix with all 1's is: " << maxi << endl;

    maxi = 0;

    optimisation_02 (matrix, maxi);

    cout << "The size of the maximum sub square matrix with all 1's is: " << maxi << endl;

    return 0;
}