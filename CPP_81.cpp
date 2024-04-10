#include<iostream>
#include<string.h>
#include<stack>
using namespace std;

bool findRedundantBrackets(string s) {

    stack<char> stack;

    for (int i = 0; i < s.length(); i++) {

        char character = s[i];

        if (character == '(' || character == '+' || character == '-' || character == '*' || character == '/') {

            stack.push(character);

        } else {

            if (character == ')') {

                bool redundant = true;

                while (stack.top() != '(') {

                    if (stack.top() == '+' || stack.top() == '-' || stack.top() == '*' || stack.top() == '/') {

                        redundant = false;
                        stack.pop();
                    }
                }

                if (redundant) {

                    return true;
                }

                stack.pop();
            }
        }
    }

    return false;
}

int main() {

    string s  = "(a+b)";

    bool check = findRedundantBrackets(s);

    if (check) {

        cout << "The given brackets are redundant brackets." << endl;

    } else {

        cout << "The given brackets are not redundant brackets." << endl;
    }

    return 0;
}