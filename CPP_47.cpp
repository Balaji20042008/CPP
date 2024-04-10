#include<iostream>
#include<string.h>
#include<bits/stdc++.h>
using namespace std;

string removeOccurrences(string s, string part) {

    int n = s.length();
    int m = part.length();

    int i = 0;

    while (i < n) {

        if (s.substr(i,m) == part) {

            s.erase(i,m);
            n = s.length();
            i = 0;

        } else {

            i++;
        }
    }
        
    return s;
}

int main() {

    string s = "daabcbaabcbc";
    string part = "abc";

    cout << removeOccurrences(s,part) << endl;
}