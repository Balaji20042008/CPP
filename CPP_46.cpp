#include<iostream>
#include<string.h>
#include<bits/stdc++.h>
using namespace std;

string replaceSpaces(string str){

	string new_string = "";

	int n = str.length();

	for (int i = 0; i < n; i++) {

		if (str[i] == ' ') {

            new_string.push_back('@');
            new_string.push_back('4');
            new_string.push_back('0');

		} else {

            new_string.push_back(str[i]);
        }
	}

	return new_string;
}

int main() {

    string s = "Hello World";

    cout << replaceSpaces(s) << endl;
}