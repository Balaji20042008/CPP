#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int recursion (vector<int> &days, vector<int> &cost, int n, int index) {

    if (index >= n) {

        return 0;
    }

    int option_01 = cost[0] + recursion (days, cost, n, index + 1);

    int i = index;

    while (i < n && days[i] < days[index] + 7) {

        i++;
    }

    int option_02 = cost[1] + recursion (days, cost, n, i);

    i = index;

    while (i < n && days[i] < days[index] + 30) {

        i++;
    }

    int option_03 = cost[2] + recursion (days, cost, n, i);

    return min (option_01, min (option_02, option_03)); 
}

int memoization (vector<int> &days, vector<int> &cost, int n, int index, vector<int> &dp) {

    if (index >= n) {

        return 0;
    }

    if (dp[index] != -1) {

        return dp[index];
    }

    int option_01 = cost[0] + memoization (days, cost, n, index + 1, dp);

    int i = index;

    while (i < n && days[i] < days[index] + 7) {

        i++;
    }

    int option_02 = cost[1] + memoization (days, cost, n, i, dp);

    i = index;

    while (i < n && days[i] < days[index] + 30) {

        i++;
    }

    int option_03 = cost[2] + memoization (days, cost, n, i, dp);

    dp[index] = min (option_01, min (option_02, option_03));

    return dp[index];
}

int optimisation (vector<int> &days, vector<int> &cost) {

    int answer = 0;

    queue<pair<int,int>> month;
    queue<pair<int,int>> week;

    for (int day : days) {

        // step 01: remove the expired days froom the queue

        while (!month.empty() && month.front().first + 30 <= day) {

            month.pop();
        }

        while (!week.empty() && week.front().first + 7 <= day) {

            week.pop();
        }

        // step 02: add the current day in the queue

        week.push (make_pair (day, answer + cost[1]));
        month.push (make_pair (day, answer + cost[2]));

        // step 03: find out the minimum cost for the tickets

        answer = min (answer + cost[0], min (month.front().second, week.front().second));
    }

    return answer;
}

int tabulation (vector<int> &days, vector<int> &cost, int n) {

    vector<int> dp(n+1, INT_MAX);

    dp[n] = 0;

    for (int k = n - 1; k >= 0; k--) {

        int option_01 = cost[0] + dp[k + 1];

        int i = k;

        while (i < n && days[i] < days[k] + 7) {

            i++;
        }

        int option_02 = cost[1] + dp[i];

        i = k;

        while (i < n && days[i] < days[k] + 30) {

            i++;
        }

        int option_03 = cost[2] + dp[i];

        dp[k] = min (option_01, min (option_02, option_03));
    }

    return dp[0];
}

int main () {

    vector<int> days = {1, 4, 6, 7, 8, 20};
    vector<int> cost = {2, 7, 15};

    int n = days.size();

    vector<int> dp (n + 1, -1);

    cout << "The minimum cost of the tickets are: " << recursion (days, cost, n, 0) << endl;
    cout << "The minimum cost of the tickets are: " << memoization (days, cost, n, 0, dp) << endl;
    cout << "The minimum cost of the tickets are: " << tabulation (days, cost, n) << endl;
    cout << "The minimum cost of the tickets are: " << optimisation (days, cost);

    return 0;
}