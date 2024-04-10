#include<iostream>
#include<string.h>
#include<stack>
using namespace std;
int main() {

    string string_01 = "BALAJI";

    cout << "Original String: " << string_01 << endl;

    stack <char> stack_01;

    for (int i = 0; i < string_01.length(); i++) {

        char character = string_01[i];
        stack_01.push(character);
    }

    string string_02 = "";

    while (!stack_01.empty()) {

        char character = stack_01.top();
        string_02.push_back(character);
        stack_01.pop();
    }

    cout << "Reverse String: " << string_02 << endl;

    return 0;
}