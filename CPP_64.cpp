#include<iostream>
#include<string.h>
using namespace std;

void reverse_string (string &name, int i, int j) {

    // base condition

    if (i > j) {

        return;
    }

    swap (name[i], name[j]);

    i++;
    j--;

    reverse_string (name, i, j);
}

int main () {

    string name = "balaji";

    int length = name.length();

    int start = 0;
    int end = length - 1;

    reverse_string (name, start, end);

    cout << "Reverse String: " << name << endl;

    return 0;
}