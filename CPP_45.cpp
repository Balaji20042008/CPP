#include<iostream>
#include<string.h>
#include<vector>
using namespace std;

char getMaxOccurCharacter (string s) {

	int array[26] = {0};

	for (int i = 0; i < s.length(); i++) {

		char character = s[i];
		int number = character - 'a';
		array[number]++;
	}

	int max = 0;
	int ans = 0;

	for (int i = 0; i < 26; i++) {

		if (max < array[i]) {

			ans = i;
			max = array[i];
		}
	}

	return 'a' + ans;
}



int main () {

    string s;

	cout << "String: ";
	cin >> s;

	cout << "Maximum Occuring Character: " << getMaxOccurCharacter(s);

    return 0;
}