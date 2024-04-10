#include<iostream>
#include<string.h>
#include<bits/stdc++.h>
using namespace std;

bool check (int a[26], int b[26]) {

    for (int i = 0; i < 26; i++) {

        if (a[i] != b[i]) {

            return 0;
        }
    }

    return 1;
}

bool checkInclusion (string s1, string s2) {

    int count_01[26] = {0};
    int n = s1.length();

    for (int  i = 0; i < n; i++) {

        char character = s1[i];
        int index = character - 'a';
        count_01[index]++;
    }

    int count_02[26] = {0};
    int m = s2.length();

    int i = 0;

    while (i < n && i < m) {

        char character = s2[i];
        int index = character - 'a';
        count_02[index]++;
        i++;
    }

    if (check(count_01,count_02))
        return 1;

    while (i < m) {

        char new_character = s2[i];
        int new_index = new_character - 'a';
        count_02[new_index]++;

        char old_character = s2[i-n];
        int old_index = old_character - 'a';
        count_02[old_index]--;

        i++;

        if (check(count_01,count_02)) 
            return 1;
    }

    return 0;    
}

int main() {

    string string_01 = "ab";
    string string_02 = "eidbaooo";

    if (checkInclusion(string_01,string_02)) {

        cout << "True" << endl;

    } else {

        cout << "False" << endl;
    }
}