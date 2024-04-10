#include<iostream>
#include<vector>
using namespace std;

int recursion (vector<int> &array, int x) {

    if (x == 0) {

        return 1;
    }

    if (x < 0) {

        return 0;
    }

    int answer = 0;

    for (int i = 0; i < array.size(); i++) {

        answer = answer + recursion (array, x - array[i]);
    }

    return answer;
}

int memoization (vector<int> &array, int x, vector<int> &dp) {

    if (x == 0) {

        return 1;
    }

    if (x < 0) {

        return 0;
    }

    if (dp[x] != -1) {

        return dp[x];
    }

    int answer = 0;

    for (int i = 0; i < array.size(); i++) {

        answer = answer + memoization (array, x - array[i], dp);
    }

    dp[x] = answer;
    
    return dp[x];
}

int tabulation (vector<int> &array, int x) {

    vector<int> dp (x+1, 0);

    dp[0] = 1;

    for (int i = 1; i <= x; i++) {

        for (int j = 0; j < array.size(); j++) {

            if (i >= array[j]) {

                dp[i] = dp[i] + dp[i - array[j]];
            }
        }
    }

    return dp[x];
}

int main () {

    vector<int> array = {1,2,5};

    int x = 5;

    vector<int> dp (x+1, -1);

    cout << "The no. of possible ways to make the target are: " << recursion (array, x) << endl;
    cout << "The no. of possible ways to make the target are: " << memoization (array, x, dp) << endl;
    cout << "The no. of possible ways to make the target are: " << tabulation (array, x) << endl;

    return 0;
}