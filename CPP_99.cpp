#include<iostream>
#include<vector>
using namespace std;

int recursion (vector<int> &coins, int x) {

    if (x == 0) {

        return 0;
    }

    if (x < 0) {

        return INT_MAX;
    }

    int minimum = INT_MAX;

    for (int i = 0; i < coins.size(); i++) {

        int answer = recursion (coins, x - coins[i]);

        if (answer != INT_MAX) {

            minimum = min (minimum, 1 + answer);
        }
    }

    return minimum;
}

int memoization (vector<int> &coins, int x, vector<int> &dp) {

    if (x == 0) {

        return 0;
    }

    if (x < 0) {

        return INT_MAX;
    }

    if (dp[x] != -1) {

        return dp[x];
    }

    int minimum = INT_MAX;

    for (int i = 0; i < coins.size(); i++) {

        int answer = recursion (coins, x - coins[i]);

        if (answer != INT_MAX) {

            minimum = min (minimum, 1 + answer);
        }
    }

    dp[x] = minimum;

    return dp[x];
}

int tabulation (vector<int> &coins, int x) {

    vector<int> dp (x + 1);

    dp[0] = 0;

    for (int i = 1; i <= x; i++) {

        dp[i] = INT_MAX;

        for (int j = 0; j < coins.size(); j++) {

            if (i - coins[j] >= 0 && dp[i - coins[j]] != INT_MAX) {

                dp[i] = min (dp[i], dp[i - coins[j]] + 1);
            }
        }
    }

    return dp[x];
}

int main() {

    vector<int> coins = {1, 2, 3};

    int x = 7;

    vector<int> dp (x + 1 , -1);

    int answer = tabulation (coins, x);

    if (answer == INT_MAX) {

        cout << "The target amount cannot be made by using the coins array." << endl;

    } else {

        cout << "Minimum no. of coins required are: " << answer << endl;
    }

    return 0;
}