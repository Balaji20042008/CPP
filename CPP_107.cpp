#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int recursion (vector<int> &obstacles, int lane, int position) {

    int n = obstacles.size();

    if (position == n) {

        return 0;
    }

    if (obstacles[position + 1] != lane) {

        return recursion (obstacles, lane, position + 1);

    } else {

        int answer = INT_MAX;

        for (int i = 1; i <= 3; i++) {

            if (obstacles[position] != i && lane != i) {

                answer = min (answer, 1 + recursion (obstacles, i, position));
            }
        }

        return answer;
    }
}

int memoization (vector<int> &obstacles, int lane, int position, vector<vector<int>> &dp) {

    int n = obstacles.size();

    if (position == n) {

        return 0;
    }

    if (dp[lane][position] != -1) {

        return dp[lane][position];
    }

    if (obstacles[position + 1] != lane) {

        dp[lane][position] =  memoization (obstacles, lane, position + 1, dp);

        return dp[lane][position];

    } else {

        int answer = INT_MAX;

        for (int i = 1; i <= 3; i++) {

            if (obstacles[position] != i && lane != i) {

                answer = min (answer, 1 + memoization (obstacles, i, position, dp));
            }
        }

        dp[lane][position] = answer;

        return dp[lane][position];
    }
}

int tabulation (vector<int> &obstacles) {

    int n = obstacles.size() - 1;

    vector<vector<int>> dp(4, vector<int>(obstacles.size(), INT_MAX));

    for (int i = 0; i <= 3; i++) {

        dp[i][n] = 0;
    }

    for (int position = n-1; position >= 0; position--) {

        for (int lane = 1; lane <= 3; lane++) {

            if (obstacles[position + 1] != lane) {

                dp[lane][position] =  dp[lane][position + 1];

            } else {

                int answer = INT_MAX;

                for (int i = 1; i <= 3; i++) {

                    if (obstacles[position] != i && lane != i) {

                        answer = min (answer, 1 + dp[i][position + 1]);
                    }
                }

                dp[lane][position] = answer;
            }
        }
    }

    return min (dp[2][0], min(1 + dp[1][0], 1 +dp[3][0]));
}

int optimisation (vector<int> &obstacles) {

    int n = obstacles.size() - 1;

    vector<int> curr(4);
    vector<int> next(4);

    for (int i = 0; i <= 3; i++) {

        next[i] = 0;
    }

    for (int position = n-1; position >= 0; position--) {

        for (int lane = 1; lane <= 3; lane++) {

            if (obstacles[position + 1] != lane) {

                curr[lane] =  next[lane];

            } else {

                int answer = INT_MAX;

                for (int i = 1; i <= 3; i++) {

                    if (obstacles[position] != i && lane != i) {

                        answer = min (answer, 1 + next[i]);
                    }
                }

                curr[lane] = answer;
            }
        }

        next = curr;
    }

    return min (next[2], min(1 + next[1], 1 + next[3]));
}

int main () {

    vector<int> obstacles = {0, 1, 2, 3, 0};

    vector<vector<int>> dp(4, vector<int>(obstacles.size(), -1));

    cout << "The minimum no. of sideway jumps are: " << recursion (obstacles, 2, 0) << endl;
    cout << "The minimum no. of sideway jumps are: " << memoization (obstacles, 2, 0, dp) << endl;
    cout << "The minimum no. of sideway jumps are: " << tabulation (obstacles) << endl;
    cout << "The minimum no. of sideway jumps are: " << optimisation (obstacles) << endl;

    return 0;
}