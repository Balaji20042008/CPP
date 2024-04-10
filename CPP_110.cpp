#include<iostream>
#include<bits/stdc++.h>
using namespace std;

long long recursion (int faces, int dice, int target) {

    if (target < 0) {

        return 0;
    }

    if (dice == 0 && target != 0) {

        return 0;
    }

    if (dice != 0 && target == 0) {

        return 0;
    }

    if (dice == 0 && target == 0) {

        return 1;
    }

    long long ans = 0;

    for (int i = 1; i <= faces; i++) {

        ans = ans + recursion(faces, dice - 1, target - i);
    }

    return ans;
}

long long memoization (int faces, int dice, int target, vector<vector<int>> &dp) {

    if (target < 0) {

        return 0;
    }

    if (dice == 0 && target != 0) {

        return 0;
    }

    if (dice != 0 && target == 0) {

        return 0;
    }

    if (dice == 0 && target == 0) {

        return 1;
    }

    if (dp[dice][target] != -1) {

        return dp[dice][target];
    }

    long long ans = 0;

    for (int i = 1; i <= faces; i++) {

        ans = ans + memoization(faces, dice - 1, target - i, dp);
    }

    dp[dice][target] = ans;

    return dp[dice][target];
}

long long tabulation (int M, int N, int X) {

    vector<vector<int>> dp(N+1, vector<int>(X+1, 0));

    dp[0][0] = 1;

    for (int dice = 1; dice <= N; dice++) {

        for (int target = 1; target <= X; target++) {

            long long ans = 0;

            for (int i = 1; i <= M; i++) {

                if (target - i >= 0) {

                    ans = ans + dp[dice - 1][target - i];
                }
            }

            dp[dice][target] = ans;
        }
    }

    return dp[N][X];
}

long long optimisation (int M, int N, int X) {

    vector<int> prev(X+1, 0);
    vector<int> curr(X+1, 0);

    prev[0] = 1;

    for (int dice = 1; dice <= N; dice++) {

        for (int target = 1; target <= X; target++) {

            long long ans = 0;

            for (int i = 1; i <= M; i++) {

                if (target - i >= 0) {

                    ans = ans + prev[target - i];
                }
            }

            curr[target] = ans;
        }

        prev = curr;
    }

    return prev[X];
}

int main() {

    int M = 6;
    int N = 3;
    int X = 12;

    // recursion

    // cout  << "The no. of ways to get the target sum are: " << recursion(M,N,X);

    // memoization

    // vector<vector<int>> dp(N+1, vector<int>(X+1, -1));

    // cout  << "The no. of ways to get the target sum are: " << memoization(M,N,X,dp);

    // tabulation 

    // cout  << "The no. of ways to get the target sum are: " << tabulation(M,N,X);

    // optimisation

    cout  << "The no. of ways to get the target sum are: " << optimisation(M,N,X);


    return 0;
}