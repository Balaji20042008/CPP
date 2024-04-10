#include<iostream>
using namespace std;
int main() {

    int m;

    cout << "The value of 'm' is: ";
    cin >> m;

    int n;

    cout << "The value of 'n' is: ";
    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}