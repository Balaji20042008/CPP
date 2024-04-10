#include<iostream>
using namespace std;
int main() {

    // int m;

    // cout << "The value of 'm' is: ";
    // cin >> m;

    // int n;

    // cout << "The value of 'n' is: ";
    // cin >> n;

    // int x = 1;

    // for (int i = 1; i <= m; i++) {
    //     for (int j = 1; j <= n; j++) {
    //         cout << x << " ";
    //         x++;
    //     }
    //     cout << endl;
    // }

    // int m;

    // cout << "The value of 'm' is: ";
    // cin >> m;

    // int n;

    // cout << "the value of 'n' is: ";
    // cin>> n;

    // for (int i = 1; i <= n; i++) {

    //     int x = i;

    //     for (int j = 1; j <= i; j++) {

    //         cout << x << " ";
    //         x++;

    //     }
    //     cout << endl;
    // }

    // int m;

    // cout << "The value of 'm' is: ";
    // cin >> m;

    // int n;

    // int x = 1;

    // cout << "The value of 'n' is: ";
    // cin >> n;

    // for (int i = 1; i <= n; i++) {

    //     for (int j = 1; j <= i; j++) {

    //         cout << x << " ";
    //         x = x + 1;
    //     }

    //     cout << endl;
    // }

    int m;

    cout << "The value of 'm' is: ";
    cin >> m;

    int n;

    cout << "the value of 'n' is: ";
    cin>> n;

    for (int i = 1; i <= n; i++) {

        for (int j = 1; j <= i; j++) {

            cout << i - j + 1 << " ";
        }

        cout << endl;
    }

    return 0;
}
