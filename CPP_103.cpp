#include<iostream>
#include<vector>
using namespace std;

int recursion (int n) {

    if (n == 0) {

        return 0;
    }

    int answer = n;

    for (int i = 1; i * i <= n; i++) {

        answer = min (answer, recursion (n - (i * i)) + 1);
    }

    return answer;
}

int memoization (int n, vector<int> &dp) {

    if (n == 0) {

        return 0;
    }

    if (dp[n] != -1) {

        return dp[n];
    }

    int answer = n;

    for (int i = 1; i * i <= n; i++) {

        answer = min (answer, memoization (n - (i * i), dp) + 1);
    }

    dp[n] = answer;

    return dp[n];
}

int tabulation (int n) {

    vector<int> dp (n + 1, n);

    dp[0] = 0;

    for (int i = 1; i <= n; i++) {

        for (int j = 1; j * j <= n; j++) {

            if (i >= j * j) {

                dp[i] = min (dp[i], dp[i - (j * j)] + 1);
            }
        }
    }

    return dp[n];
}

int main () {

    int n = 6;

    vector<int> dp(n + 1, -1);

    cout << "The minimum no. of squares required are: " << recursion (n) << endl;
    cout << "The minimum no. of squares required are: " << memoization (n, dp) << endl;
    cout << "The minimum no. of squares required are: " << tabulation (n) << endl;

    return 0;
}