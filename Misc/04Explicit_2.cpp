#include <iostream>
#include <string>

using namespace std;

class Complex{
    private:
        double real;
        double imag;
    public:
        //defualt constructor
        Complex(double r = 0.0, double i = 0.0) : real(r), imag(i){
            cout << "real: " << real << endl;
            cout << "imag: " << imag << endl;
        }
        // A mehtod to compare two default values
        bool operator == (const Complex &rhs){
           return (real == rhs.real && imag == rhs.imag)? true: false;
        }
};

int main(){
    Complex c(1, 0);
    // Checks real part
    if (c == (1.0,2.0))
        cout << "same" << endl;
    else
        cout << "different" << endl;
    return -1;
}
