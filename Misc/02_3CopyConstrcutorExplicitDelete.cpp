// Copy initialization

/*  While doing implicit conversions makes sense in the Fraction case, in other cases.
    (char getting converted to int), this may be undesirable, or lead to unexpected behaviors
*/

#include <cassert>
#include <iostream>

class Fraction{
    private:
        int m_numerator;
        int m_denominator;

    public:
        // Default constructor
        explicit Fraction(int numerator = 0, int denominator = 1): m_numerator(numerator), m_denominator(denominator){
            assert(denominator != 0);
        }
        // // Copy constrcutor
        // Fraction(const Fraction &copy) : m_numerator(copy.m_numerator), m_denominator(copy.m_denominator){
        //     // no need to check for a denominator of 0 here since copy must already be a valid Fraction
        //     std :: cout << "Copy constrcutor called" << std :: endl;
        // }
        friend std :: ostream& operator<< (std:: ostream& out, const Fraction&f1);
    };

std:: ostream& operator << (std :: ostream& out, const Fraction &f1){
    out << f1.m_numerator << "/" << f1.m_denominator;
    return out;
}

int main(){
    //Fraction f1 = 'x';
    Fraction f1('x');
    std :: cout << f1 << std :: endl;
    return -1;
}

/*  The above program will not compile, since Fraction(int, int) was made explicit.
    and an appropriate converting constructor could not be found to conver 'x' to a
    Fraction.

    NOTE : that making a constrcutor explicit only prevents IMPLICIT conversions.
    Explicit conversions (via direct or unifom initialization or explicit casts)
    are still allowed.
    Fraction f1('x'); // allowed, even though Fraction(int, int) is explicit
*/
