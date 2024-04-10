#include<iostream>
using namespace std;
int main() {

    int n;

    cout << "The size of the array is: "; 
    cin >> n; 

    int *array = new int[n];

    cout << "Array: ";

    for (int i = 0; i < n; i++) {

        cin >> array[i];
    }

    int sum = 0;

    for (int i = 0; i < n; i++) {

        sum = sum + array[i];
    }

    cout << "The sum of all the elements in the array is: " << sum << endl;

    return 0;
}