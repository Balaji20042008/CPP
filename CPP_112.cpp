#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main() {

    vector<int> array = {1, 5, 7, 8, 5, 3, 4, 2, 1};
    int difference = -2;

    unordered_map<int,int> dp;

    int ans = 0;

    for (int i = 0; i < array.size(); i++) {

        int temp = array[i] - difference;
        int temp_ans = 0;

        if (dp.count(temp)) {

            temp_ans = dp[temp];
        }

        dp[array[i]] = 1 + temp_ans;

        ans = max (ans, dp[array[i]]);
    }

    cout << "The length of the longest arithmetic subsequence of the given difference is: " << ans << endl;

    return 0;
}