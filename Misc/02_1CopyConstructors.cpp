// Copy constructor

#include <cassert>
#include <iostream>

class Fraction{
    private:
        int m_numnerator;
        int m_denominator;
    public:
        // Default constructor
        Fraction(int num = 0, int deno = 1) : m_numnerator(num), m_denominator(deno){
            assert(deno!=0);
        }
        Fraction(const Fraction &fractionCopy) : m_numnerator(fractionCopy.m_numnerator), m_denominator(fractionCopy.m_denominator){
            std :: cout << "In Copy constructor" << std :: endl;
        }
        friend std:: ostream& operator << (std::ostream& out, const Fraction &f1);
};

std :: ostream& operator << (std :: ostream& out, const Fraction &f1){
    out << f1.m_numnerator << "/" << f1.m_denominator;
    return out;
}


int main(){
    // Direct initialize a Fraction, calls Fraction(int, int) constructor
    Fraction fiveThirds(5, 3);
    // Direct initialize -- with what constrctor ?
    Fraction fCopy(fiveThirds);

    // Wil not call copy constructor *1
    Fraction fiveFourth(Fraction(5,4));
    std :: cout << fCopy << std :: endl;
    std :: cout << fiveFourth << std :: endl;
    return -1;
}

/* *1 - first, we direct initialize an anonymous Fraction object, using the
Fraction(int. int) constructor. Then we use that anonymous Fraction object as an
initializer for Fraction fiveFourth. Since the anonymous object is a Fraction,
as is fiveFourth, this should call the copy constructor. BUT WON'T.

Note that initializing an anonymous object and then using that object to direct
initialize our defined object takes two stages (one to create the aonymous objec,
one to call the copy constructor). However, the end reuslt is essentially identical
to just doing a direct initialization, which takes only one step.

For this reaso, in such cases, the compiler is allowed to opt out of caling the
copy constrcutor and just do a direct initialization instead. This process is called
ELIDING.
so although we wrote Fraction fiveFourth(Fration(5,4));,
the compiler may change this to Fraction fiveFourth(5,4);
*/
