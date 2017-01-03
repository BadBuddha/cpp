/* In C++, the programmer abstracts real world objects using classes as concrete
types.
Sometimes it is required to convert one concrete type to another concrete type
or primitive type implicitly.
Conversion operators play smart role in such situations.
*/


#include <iostream>
#include <cmath>

using namespace std;

class Complex{
    private:
        double real;
        double imag;
    public:
        // Default constructor
        Complex(double r = 0.0, double i = 0.0): real(r), imag(i){}
        // Magnitude
        double mag(){return getMag();}
        // Magniude Conversion operator
        operator double (){cout << "here"<< endl; return getMag();}
    private:
        // class to get Magnitude
        double getMag(){return sqrt(real * real + imag * imag);}
};


int main(){
    Complex com(3.0, 4.0);
    //cout << com.mag() << endl;
    cout << com << endl;
    return -1;
}
