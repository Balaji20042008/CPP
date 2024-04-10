#include<iostream>
#include<vector>
using namespace std;

int recursion (vector<int> &array, int target, vector<int> &answer, vector<vector<int>> &result) {

    if (target == 0) {

        result.push_back(answer);
        return 1;
    }

    if (target < 0) {

        return 0;
    }

    int sum = 0;

    for (int i = 0; i < array.size(); i++) {

        answer.push_back(array[i]);

        sum = sum + recursion (array, target - array[i], answer, result, dp);

        answer.pop_back();
    }

    return sum;
}

int main () {

    // input
    // n = 3;
    // array = {1, 2, 5};
    // target = 5;

    // output
    // {1 1 1 1 1}
    // {1 1 1 2} {1 1 2 1} {1 2 1 1} {2 1 1 1}
    // {1 2 2} {2 2 1} {2 1 2}
    // {5}

    vector<int> array = {1, 2, 5};
    int target = 5;

    vector<vector<int>> result;

    vector<int> answer;

    cout << "The no. of possilble ways to make the target are:  " << recursion (array, target, answer, result, dp) << endl;

    cout << "The possilble answers are: " << endl;

    for (int i = 0; i < result.size(); i++) {

        for (int j = 0; j < result[i].size(); j++) {

            cout << result[i][j] << " ";
        }

        cout << endl;
    }

    return 0;
}