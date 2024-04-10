#include<iostream>
using namespace std;

bool check_palindrome (string &str, int i, int j) {

    // base condition

    if (i > j) {

        return 1;
    }

    if (str[i] != str[j]) {

        return 0;

    } else {

        i++;
        j--;

        // recursive relation

        return check_palindrome (str, i, j);
    }
}

int main() {

    string str = "abdcba";

    int start = 0;
    int end = str.length() - 1;

    bool check = check_palindrome (str, start, end);

    if (check) {

        cout << "The string is a plaindrome." << endl;

    } else {

        cout << "The string is not a palindrome." << endl;
    }

    return 0;
}