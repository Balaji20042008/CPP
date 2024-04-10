#include<iostream>
#include<string.h>
using namespace std;

char lower_case (char character) {

    if (character >= 'A' && character <= 'Z') {

        character = character - 'A' + 'a';
    }

    return character;
}

int get_length (string phrase) {

    int count = 0;

    for (int i = 0; phrase[i] != '\0'; i++) {

        count++;
    }

    return count;
}

bool check_palindrome (string phrase, int n) {

    int start = 0;
    int end = n - 1;

    // int i = 0;

    while (start <= end) {

        // cout << "for i = " << i << ", start = " << start << endl;
        // cout << "for i = " << i << ", end = " << end << endl;

        char forward = lower_case (phrase [start]);
        char backward = lower_case (phrase [end]);

        // cout << "for i = " << i << ", forward = " << forward<<  endl;
        // cout << "for i = " << i << ", backward = " << backward << endl;

        bool check_01 = (forward < 'a' || forward > 'z') && (forward < '0' || forward > '9');
        bool check_02 = (backward < 'a' || backward> 'z') && (backward < '0' || backward > '9');
        bool check_03 = check_01 || check_02;

        // cout << "for i = " << i << ", check_01 = " << check_01 << endl;
        // cout << "for i = " << i << ", check_02 = " << check_02 << endl;
        // cout << "for i = " << i << ", check_03 = " << check_03 << endl;

        if (forward == backward) {

            start++;
            end--;

        } else if (check_03) {

            if (check_01 == 1 && check_02 == 0) {

                start++;

            } else if (check_01 == 0 && check_02 == 1) {

                end--;

            } else {

                start++;
                end--;
            }

        } else {

            return 0;
        }

        // i++;
    }

    return 1;
}

int main () {

    string phrase;

    cout << "Phrase: ";
    cin >> phrase;

    int length = phrase.length();

    bool check = check_palindrome (phrase, length);

    if (check) {

        cout << "The given string is a palindrome." << endl;

    } else {

        cout << "The given string is not a palindrome." << endl;
    }


    return 0;
}
