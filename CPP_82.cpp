#include<iostream>
#include<string.h>
#include<stack>
using namespace std;

int findMinimumCost(string s) {

    if (s.length() % 2 != 0) {

        return -1;
    }

    stack<char> stack;

    for (int i = 0; i < s.length(); i++) {

        char character = s[i];

        if (character == '{') {

            stack.push(character);

        } else {

            if (!stack.empty() && stack.top() == '{') {

                stack.pop();

            } else {

                stack.push(character);
            }
        }
    }

    int a = 0;
    int b = 0;

    while (!stack.empty()) {

        if (stack.top() == '{') {

            a++;

        } else {

            b++;
        }

        stack.pop();
    }

    return (a+1)/2 + (b+1)/2;
}

int main() {

    string s  = "}}}{{{";

    cout << "Minimum Reversals: " << findMinimumCost(s) << endl;

    return 0;
}