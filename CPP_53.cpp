#include<iostream>
using namespace std;

int main() {

    int array[7] = {1,2,3,4,5,6,7};

    cout << "1." << array << endl; // prints the address of the first memory location of the array

    char name[7] = "balaji";

    cout << "2." << name << endl; // prints the total character array
    cout << "3." << name[0] << endl; // prints only the value stored at the 0th index of the character array
    cout << "4." << &name[0] << endl; // prints the total character array

    char *p = name;

    cout << "5." << p << endl; // prints the total character array
    cout << "6." << *p << endl; // prints only the value stored at the first memory location of the character array

    char character = 'a';
    char *q = &character;

    cout << "7." << q << endl; // prints all the characters until it finds the null character
    cout << "8." << &character << endl; // prints all the characters until it finds the null character
    cout << "9." << *q << endl; // prints only the value stored at the address of the character
 
    
    return 0;
}