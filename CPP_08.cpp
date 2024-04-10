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

    // for (int i = 1; i <= n; i++) {

    //     for (int j = 1; j <= m; j++) {

    //         if ((n - i) >= j) {

    //             cout << " " << " ";

    //         } else {

    //             cout << x << " ";

    //             x++;
    //         }
    //     }

    //     cout << endl;
    // }

    // int m;

    // cout << "The value of 'm' is: ";
    // cin >> m;

    // int n;

    // cout << "The value of 'n' is: ";
    // cin >> n;

    // for (int i = 1; i <= n; i++) {

    //     int x = 1;

    //     int y = i - 1;

    //     for (int j = 1; j <= m; j++) {

    //         if ((n - i) >= j) {

    //             cout << " " << " ";

    //         } else {

    //             cout << x << " ";

    //             x++;
    //         }
    //     }

    //     for (int k = 1; k <= m; k++) {

    //         if (k >= i) {

    //             cout << " " << " ";

    //         } else {

    //             cout << y << " ";

    //             y--;
    //         }
    //     }

    //     cout << endl;
    // }

    int m;

    cout << "The value of 'm' is: ";
    cin >> m;

    int n;

    cout << "The value of 'n' is: ";
    cin >> n;

    for (int i = 1; i <= n; i++) {

        for (int j = 1; j <= m; j++) {

            if ((n - i + 1) >= j) {

                cout << j << " ";

            } else {

                cout << "*" << " ";

            }
        }

        for (int k = m; k > 0; k--) {

            if ((n - i + 1) >= k) {

                cout << k << " ";

            } else {

                cout << "*" << " ";

            }
        }

        cout << endl;
    }


    return 0;
}