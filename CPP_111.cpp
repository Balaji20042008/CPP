#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int recursion(int index, int diff, vector<int> &array) {

    if (index < 0) {

        return 0;
    }

    int ans = 0;

    for (int back = index - 1; back >= 0; back--) {

        if (array[index] - array[back] == diff) {

            ans = max(ans, 1 + recursion(back, diff, array));
        }
    }

    return ans;
}

int memoization(int index, int diff, vector<int> &array, unordered_map<int,int> dp[]) {

    if (index < 0) {

        return 0;
    }

    if (dp[index].count(diff)) {

        return dp[index][diff];
    }

    int ans = 0;

    for (int back = index - 1; back >= 0; back--) {

        if (array[index] - array[back] == diff) {

            ans = max(ans, 1 + memoization(back, diff, array, dp));
        }
    }

    dp[index][diff] = ans;

    return dp[index][diff];
}

int main() {

    vector<int> array = {1, 7, 10, 13, 14, 19};

    int n = array.size();

    if (n == 2) {

        cout << "The length of the longest arithmetic subsequence array is: " << n << endl;
    }

    unordered_map<int,int> dp[n+1];

    // int ans = 0;

    // for (int i = 0; i < n; i++) {

    //     for (int j = i+1; j < n; j++) {

    //         ans = max(ans, 2 + recursion(i, array[j] - array[i], array));
    //     }
    // }

    // cout << "The length of the longest arithmetic subsequence array is: " << ans << endl;

    // int ans = 0;

    // for (int i = 0; i < n; i++) {

    //     for (int j = i+1; j < n; j++) {

    //         ans = max(ans, 2 + memoization(i, array[j] - array[i], array, dp));
    //     }
    // }

    // cout << "The length of the longest arithmetic subsequence array is: " << ans << endl;

    int ans = 0;

    for (int i = 1; i < n; i++) {
            
        for (int j = 0; j < i; j++) {
            
            int diff = array[i] - array[j];
            
            int count = 1;
            
            if (dp[j].count(diff)) {
                
                count = dp[j][diff];
            }
            
            dp[i][diff] = 1 + count;
            
            ans = max(ans, dp[i][diff]);
        }
    }

    cout << "The length of the longest arithmetic subsequence array is: " << ans << endl;

    return 0;
}