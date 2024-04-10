#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int recursion (vector<int> &values, int i, int j) {

    if (i + 1 == j) {

        return 0;
    }

    int answer = INT_MAX;

    for (int k = i + 1; k < j; k++) {

        answer = min (answer, values[i] * values[j] * values[k] + recursion (values, i, k) + recursion (values, k, j));
    }

    return answer;
}

int memoization (vector<int> &values, int i, int j, vector<vector<int>> &dp) {

    if (i + 1 == j) {

        return 0;
    }

    if (dp[i][j] != -1) {

        return dp[i][j];
    }

    int answer = INT_MAX;

    for (int k = i + 1; k < j; k++) {

        answer = min (answer, values[i] * values[j] * values[k] +  memoization (values, i, k, dp) + memoization (values, k, j, dp));
    }

    dp[i][j] = answer;

    return dp[i][j];
}

int tabulation (vector<int> &values) {

    int n = values.size();

    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int i = n-1; i >= 0; i--) {

        for (int j = i+2; j < n; j++) {

            int answer = INT_MAX;

            for (int k = i + 1; k < j; k++) {

                answer = min (answer, values[i] * values[j] * values[k] +  dp[i][k] + dp[k][j]);
            }

            dp[i][j] = answer;
        }
    }

    return dp[0][n-1];
}

int main () {

    vector<int> values = {3, 7, 4, 5};

    int n = values.size();

    vector<vector<int>> dp(n, vector<int>(n, -1));

    cout << " The smallest possible score with some triangulation of the polygon is: " << recursion (values, 0, n-1) << endl;
    cout << " The smallest possible score with some triangulation of the polygon is: " << memoization (values, 0, n-1, dp) << endl;
    cout << " The smallest possible score with some triangulation of the polygon is: " << tabulation (values) << endl;

    return 0;
}