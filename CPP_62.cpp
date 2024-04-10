#include<iostream>
using namespace std;

int find_sum (int *array, int n) {

    // base condition

    if (n == 0) {

        return 0;
    }

    // recursive relation

    int ans = array[0] + find_sum (array + 1, n - 1);

    return ans;
}

int main() {

    int n;

    cout << "Size: ";
    cin >> n;

    int *array = new int[n];

    cout << "Array: ";

    for (int i = 0; i < n; i++) {

        cin >> array[i];
    }

    cout << "Sum: " << find_sum (array, n) << endl;

    return 0;
}