#include<iostream>
using namespace std;
int main() {

    // Type - 01

    // int m;

    // cout << "The value of 'm' is: ";
    // cin >> m;

    // int n;

    // cout << "The value of 'n' is: ";
    // cin >> n;

    // for (int i = 1; i <= n; i++) {

    //     for (int j = 1; j <= m; j++) {

    //         char x = 'A' + i - 1;

    //         cout << x << " ";

    //     }

    //     cout << endl;
    // }

    // Type - 02

    // int m;

    // cout << "The value of 'm' is: ";
    // cin >> m;

    // int n;

    // cout << "The value of 'n' is: ";
    // cin >> n;

    // for (int i = 1; i <= n; i++) {

    //     for (int j = 1; j <= m; j++) {

    //         char x = 'A' + j - 1;

    //         cout << x << " ";

    //     }

    //     cout << endl;
    // }

    // Type - 03

    // int m;

    // cout << "The value of 'm' is: ";
    // cin >> m;

    // int n;

    // cout << "The value of 'n' is: ";
    // cin >> n;

    // int y = 1;

    // for (int i = 1; i <= n; i++) {

    //     for (int j = 1; j <= m; j++) {

    //         char x = 'A' + y - 1;

    //         cout << x << " ";

    //         y++;

    //     }

    //     cout << endl;
    // }

    // Type - 04

    // int m;

    // cout << "The value of 'm' is: ";
    // cin >> m;

    // int n;

    // cout << "The value of 'n' is: ";
    // cin >> n;

    // for (int i = 1; i <= n; i++) {

    //     int y = i;

    //     for (int j = 1; j <= m; j++) {

    //         char x = 'A' + y - 1;

    //         cout << x << " ";

    //         y++;
    //     }

    //     cout << endl;
    // }

    // Type - 05

    // int m;

    // cout << "The value of 'm' is: ";
    // cin >> m;

    // int n;

    // cout << "The value of 'n' is: ";
    // cin >> n;

    // for (int i = 1; i <= n; i++) {

    //     for (int j = 1; j <= i; j++) {

    //         char x = 'A' + i - 1;

    //         cout << x << " ";
    //     }

    //     cout << endl;
    // }

    // Type - 06

    // int m;

    // cout << "The value of 'm' is: ";
    // cin >> m;

    // int n;

    // cout << "The value of 'n' is: ";
    // cin >> n;

    // for (int i = 1; i <= n; i++) {

    //     for (int j = 1; j <= i; j++) {

    //         char x = 'A' + j - 1;

    //         cout << x << " ";
    //     }

    //     cout << endl;
    // }

    // Type - 07

    // int m;

    // cout << "The value of 'm' is: ";
    // cin >> m;

    // int n;

    // cout << "The value of 'n' is: ";
    // cin >> n;

    // int y = 1;

    // for (int i = 1; i <= n; i++) {

    //     for (int j = 1; j <= i; j++) {

    //         char x = 'A' + y - 1;

    //         cout << x << " ";

    //         y++;
    //     }

    //     cout << endl;
    // }

    // Type - 08

    // int m;

    // cout << "The value of 'm' is: ";
    // cin >> m;

    // int n;

    // cout << "The value of 'n' is: ";
    // cin >> n;

    // for (int i = 1; i <= n; i++) {

    //     int y = i;

    //     for (int j = 1; j <= i; j++) {

    //         char x = 'A' + y - 1;

    //         cout << x << " ";

    //         y++;
    //     }

    //     cout << endl;
    // }

    // Type - 09

    int m;

    cout << "The value of 'm' is: ";
    cin >> m;

    int n;

    cout << "The value of 'n' is: ";
    cin >> n;

    for (int i = n; i > 0; i--) {

        int y = i;

        for (int j = n; j >= i; j--) {

            char x = 'A' + y - 1;

            cout << x;

            y++;
        }

        cout << endl;
    }


    return 0;
}