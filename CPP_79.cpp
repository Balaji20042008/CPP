#include<iostream>
using namespace std;

class stack {

    public:

    int *array;
    int size;
    int top;

    stack (int size) {

        this -> size = size;
        array = new int[size];
        top = -1;
    }

    void push (int element) {

        if (size - top > 1) {

            top++;
            array[top] = element;

        } else {

            cout << "Stack Overflow" << endl;
        }
    }

    void pop () {

        if (top >= 0) {

            top--;

        } else {

            cout << "Stack Underflow" << endl;
        }
    }

    int peak () {

        if (top >= 0 && top < size) {

            return array[top];

        } else {

            cout << "Empty Stack "; return -1;
        }
    }

    void empty () {

        if (top == -1) {

            cout << "Empty Stack" << endl;

        } else {

            cout << "Non-Empty Stack" << endl;
        }
    }
};

int main() {

    stack s(5);

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    cout << "Peak Element: " << s.peak() << endl;

    s.pop();

    cout << "Peak Element: " << s.peak() << endl;

    s.pop();

    cout << "Peak Element: " << s.peak() << endl;

    s.pop();

    cout << "Peak Element: " << s.peak() << endl;

    s.pop();

    cout << "Peak Element: " << s.peak() << endl;

    s.pop();

    cout << "Peak Element: " << s.peak() << endl;

    return 0;
}