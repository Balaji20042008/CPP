#include<iostream>
using namespace std;

class Complex {

    public:

    int real;
    int imag;

    Complex (int real = 0, int imag = 0) {

        this-> real = real;
        this-> imag = imag;
    }

    Complex operator+ (Complex &b) {

        Complex a;

        a.real = this-> real + b.real;
        a.imag = this-> imag + b.imag;

        return a;
    }

    void print () {

        cout << real << "+" << imag << "i" << endl;
    }
};

class Real: public Complex {

    public:

    Real operator+ (Real &b) {

        Real a;

        a.real = this-> real + b.real;

        return a;
    }

    void print () {

        cout << real << endl;
    }
};

class Imaginary: public Complex {

    public:

    Imaginary operator+ (Imaginary &b) {

        Imaginary a;
        
        a.imag = this-> imag + b.imag;

        return a;
    }

    void print () {

        cout << imag << "i" << endl;
    }

};
  
int main() {

    Real real_01;
    Real real_02;

    real_01.real = 5;
    real_02.real = 7;

    Real real_03 = real_01 + real_02;

    real_03.print();

    return  0; 
}