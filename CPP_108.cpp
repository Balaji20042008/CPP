#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int recursion (vector<int> &satisfaction, int index, int time) {

    if (index == satisfaction.size()) {

        return 0;
    }

    int include = satisfaction[index] * (time + 1) + recursion (satisfaction, index + 1, time + 1);
    int exclude = 0 + recursion (satisfaction, index + 1, time);

    return max(include, exclude);
}

int memoization (vector<int> &satisfaction, int index, int time, vector<vector<int>> &dp) {

    if (index == satisfaction.size()) {

        return 0;
    }

    if (dp[index][time] != -1) {

        return dp[index][time];
    }

    int include = satisfaction[index] * (time + 1) + memoization (satisfaction, index + 1, time + 1, dp);
    int exclude = 0 + memoization (satisfaction, index + 1, time, dp);

    dp[index][time] = max(include, exclude);

    return dp[index][time];
}

// int memoization (vector<int> &satisfaction) {

//     int n = satisfaction.size();

//     vector<vector<int>> dp(n, vector<int>(n, -1));


// }

int main () {

    vector<int> satisfaction = {4, 3, 5};

    int n = satisfaction.size();

    vector<vector<int>> dp(n+1, vector<int>(n+1, -1));

    sort (satisfaction.begin(), satisfaction.end());

    cout << "The maximum like-time coefficient is: " << recursion (satisfaction, 0, 0) << endl;
    cout << "The maximum like-time coefficient is: " << memoization (satisfaction, 0, 0, dp) << endl;

    return 0;
}