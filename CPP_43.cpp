#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int get_length (char name[]) {

    int count = 0;

    for (int i = 0; name[i] != '\0'; i++) {

        count++;
    }

    return count;
}

void reverse_string (char name[], int n) {

    int start = 0;
    int end = n - 1;

    while (start < end) {

        swap (name[start], name[end]);

        start++;
        end--;
    }
}

bool palindrome (char name[], int n) {

    int start = 0;
    int end = n - 1;

    while (start < end) {

        if (name[start] == name[end]) {

            start++;
            end--;

        } else {

            return 0;
        }
    }

    return 1;
}

int main() {

    char name[100];

    cout << "Name: ";
    cin >> name;

    cout << "Name: " << name << endl;

    // 1. Length of a String

    int length = get_length (name);

    cout << "Length: " << length << endl;

    // 2. Reverse of a String

    // cout << "Reverse: ";

    // reverse_string (name, length);

    // cout << name << endl;

    // 3. Check Palindrome

    if (palindrome (name, length)) {

        cout << "The given name is a palindrome." << endl;

    } else {

        cout << "The given name is not a palindrome." << endl;
    }


    return 0;
}