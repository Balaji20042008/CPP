#include<iostream>
using namespace std;
int main() {

   char x;

   cout << "The character is: ";
   cin >> x;

   if (x >= 65 && x <= 90) {
    cout << "The given character is an upper case character." << endl;
   } else if (x >= 90 && x <= 122) {
    cout << "The given character is a lower case character." << endl;
   } else if (x >= 48 && x <= 57) {
    cout << "The given character is a number between 0 to 9." << endl;
   } else {
    cout << "The given character is a special character." << endl;
   }

    return 0;
}