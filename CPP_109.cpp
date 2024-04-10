#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int recursion (int index, int end, vector<int> &slices, int n) {

    if (n == 0 || index > end) {

        return 0;
    }

    int include = slices[index] + recursion(index + 2, end, slices, n-1);
    int exclude = 0 + recursion(index + 1, end, slices, n);

    return max(include, exclude);
}

int memoization (int index, int end, vector<int> &slices, int n, vector<vector<int>> &dp) {

    if (n == 0 || index > end) {

        return 0;
    }

    if (dp[index][n] != -1) {

        return dp[index][n];
    }

    int include = slices[index] + memoization(index + 2, end, slices, n-1, dp);
    int exclude = 0 + memoization(index + 1, end, slices, n, dp);

    dp[index][n] = max(include, exclude);

    return dp[index][n];
}

int tabulation (vector<int> &slices) {

    int k = slices.size();

    vector<vector<int>> dp_01(k+2, vector<int>(k+2, 0));
    vector<vector<int>> dp_02(k+2, vector<int>(k+2, 0));

    for (int index = k-2; index >= 0; index--) {

        for (int n = 1; n <= k/3; n++) {

            int include = slices[index] + dp_01[index + 2][n-1];
            int exclude = 0 + dp_01[index + 1][n];

            dp_01[index][n] = max(include, exclude);
        }
    }

    int case_01 = dp_01[0][k/3];

    for (int index = k-1; index >= 1; index--) {

        for (int n = 1; n <= k/3; n++) {

            int include = slices[index] + dp_02[index + 2][n-1];
            int exclude = 0 + dp_02[index + 1][n];

            dp_02[index][n] = max(include, exclude);
        }
    }

    int case_02 = dp_02[1][k/3];

    return max(case_01, case_02);

}

int optimisation (vector<int> &slices) {

    int k = slices.size();

    vector<int> prev(k+2, 0);
    vector<int> curr(k+2, 0);
    vector<int> next(k+2, 0);

    for (int index = k-2; index >= 0; index--) {

        for (int n = 1; n <= k/3; n++) {

            int include = slices[index] + next[n-1];
            int exclude = 0 + curr[n];

            prev[n] = max(include, exclude);
        }

        next = curr;
        curr = prev;
    }

    int case_01 = curr[k/3];

    for (int i = 0; i < k+2; i++) {

        prev[i] = 0;
        curr[i] = 0;
        next[i] = 0;
    }

    for (int index = k-1; index >= 1; index--) {

        for (int n = 1; n <= k/3; n++) {

            int include = slices[index] + next[n-1];
            int exclude = 0 + curr[n];

            prev[n] = max(include, exclude);
        }

        next = curr;
        curr = prev;
    }

    int case_02 = curr[k/3];

    return max(case_01, case_02);
}

int main() {

    vector<int> slices = {1,2,3,4,5,6};

    // recursion

    // int k = slices.size();

    // int case_01 = recursion(0, k-2, slices, k/3);
    // int case_02 = recursion(1, k-1, slices, k/3);

    // cout << "The maximum possible sum of slice sizes that I can pick is: " << max(case_01, case_02) << endl; 

    // memoization

    // int k = slices.size();

    // vector<vector<int>> dp_01(k, vector<int>(k, -1));
    // int case_01 = memoization(0, k-2, slices, k/3, dp_01);

    // vector<vector<int>> dp_02(k, vector<int>(k, -1));
    // int case_02 = memoization(1, k-1, slices, k/3, dp_02);

    // cout << "The maximum possible sum of slice sizes that I can pick is: " << max(case_01, case_02) << endl;

    // tabulation

    // cout << "The maximum possible sum of slice sizes that I can pick is: " << tabulation(slices) << endl;

    // space optimisation

    cout << "The maximum possible sum of slice sizes that I can pick is: " << optimisation(slices) << endl; 

    return 0;
}