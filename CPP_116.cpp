#include<iostream>
#include<string>
#include<bits/stdc++.h>
using namespace std;

int recursion (int i, int j, string &a, string &b) {

    if (i >= a.length() || j >= b.length()) {

        return 0;
    }

    if (a[i] == b[j]) {

        return 1 + recursion(i+1, j+1, a, b);

    } else {

        return max(recursion(i, j+1, a, b), recursion(i+1, j, a, b));
    }
}

int memoization (int i, int j, string &a, string &b, vector<vector<int>> &dp) {

    if (i >= a.length() || j >= b.length()) {

        return 0;
    }

    if (dp[i][j] != -1) {

        return dp[i][j];
    }

    if (a[i] == b[j]) {

        return dp[i][j] = 1 + memoization(i+1, j+1, a, b, dp);

    } else {

        return dp[i][j] = max(memoization(i, j+1, a, b, dp), memoization(i+1, j, a, b, dp));
    }
}

int tabulation (string &a, string &b) {

    int m = a.length();
    int n = b.length();

    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

    for (int i = m-1; i >= 0; i--) {

        for (int j = n-1; j >= 0; j--) {

            if (a[i] == b[j]) {

                dp[i][j] = 1 + dp[i+1][j+1];

            } else {

                dp[i][j] = max(dp[i][j+1], dp[i+1][j]);
            }
        }
    }

    return dp[0][0];
}

int optimisation (string &a, string &b) {

    int m = a.length();
    int n = b.length();

    vector<int> curr(n+1, 0);
    vector<int> next(n+1 ,0);

    for (int i = m-1; i >= 0; i--) {

        for (int j = n-1; j >= 0; j--) {

            if (a[i] == b[j]) {

                curr[j] = 1 + next[j+1];

            } else {

                curr[j] = max(curr[j+1], next[j]);
            }
        }

        next = curr;
    }

    return next[0];
}

int main() {

    // string text_01 = "abc";
    // string text_02 = "def";

    // int m = text_01.length();
    // int n = text_02.length();

    // cout << "The length of the longest common subsequence is: " << recursion(0, 0, text_01, text_02) << endl;
    
    // vector<vector<int>> dp(m, vector<int>(n, -1));

    // cout << "The length of the longest common subsequence is: " << memoization(0, 0, text_01, text_02, dp) << endl;

    // cout << "The length of the longest common subsequence is: " << tabulation(text_01, text_02) << endl;

    // cout << "The length of the longest common subsequence is: " << optimisation(text_01, text_02) << endl;

    string s = "bbbab";

    string rev_string = s;
    reverse (rev_string.begin(), rev_string.end());

    cout << "The length of the longest palindrome subsequence is: " << optimisation(s, rev_string) << endl;

    return 0;
}