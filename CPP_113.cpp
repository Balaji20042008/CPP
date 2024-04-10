#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int recursion (int n) {

    if (n == 0 || n == 1) {

        return 1;
    }

    int ans = 0;

    for (int i = 1; i <= n; i++) {

        ans = ans + recursion(i-1) * recursion(n-i);
    }

    return ans;
}

int memoization (int n, vector<int> &dp) {

    if (n == 0 || n == 1) {

        return 1;
    }

    if (dp[n] != -1) {

        return dp[n];
    }

    int ans = 0;

    for (int i = 1; i <= n; i++) {

        ans = ans + memoization(i-1, dp) * memoization(n-i, dp);
    }

    return dp[n] = ans;
}

int tabulation (int n) {

    vector<int> dp (n+1, 0);

    dp[0] = dp[1] = 1;

    // i -> no. of nodes

    for (int i = 2; i <= n; i++) {

        // j -> root node

        for (int j = 1; j <= i; j++) {

            dp[i] = dp[i] + dp[j-1] * dp[i-j];
        }
    }

    return dp[n];
}

int main () {

    int n = 4;

    // cout << "The number of structurally unique BST's are: " << recursion(n) << endl;

    vector<int> dp (n+1, -1);

    cout << "The number of structurally unique BST's are: " << memoization(n, dp) << endl;

    // cout << "The number of structurally unique BST's are: " << tabulation(n, dp) << endl; 

    return 0;
}