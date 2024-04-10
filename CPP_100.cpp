#include<iostream>
#include<vector>
using namespace std;

int recursion (int n, int x, int y, int z) {

    if (n == 0) {

        return 0;
    }

    if (n < 0) {

        return INT_MIN;
    }

    int a = recursion (n-x, x, y, z) + 1;
    int b = recursion (n-y, x, y, z) + 1;
    int c = recursion (n-z, x, y, z) + 1;

    int answer = max (a, max(b,c));

    return answer;
}

int main () {

    int n = 8;

    int x = 3;
    int y = 3;
    int z = 3;

    int answer = recursion (n, x, y, z);

    if (answer < 0) {

        cout << "Maximum no. of segments are: 0" << endl;

    } else {

        cout << "Maximum no. of segments are: " << answer << endl;
    }

    return 0;
}