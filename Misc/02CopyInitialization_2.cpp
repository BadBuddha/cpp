// Copy initialization

/* _1 shows where copy initalization is used, but two of them are worth
    mentioning explicity.
    1. When you pass or 2. return a class by value
*/

#include <cassert>
#include <iostream>

class Fraction{
    private:
        int m_numerator;
        int m_denominator;

    public:
        // Default constructor
        Fraction(int numerator = 0, int denominator = 1): m_numerator(numerator), m_denominator(denominator){
            assert(denominator != 0);
        }
        // Copy constrcutor
        Fraction(const Fraction &copy) : m_numerator(copy.m_numerator), m_denominator(copy.m_denominator){
            // no need to check for a denominator of 0 here since copy must already be a valid Fraction
            std :: cout << "Copy constrcutor called" << std :: endl;
        }
        friend std :: ostream& operator<< (std:: ostream& out, const Fraction&f1);
        int getNumerator(){return m_numerator;}
        void setNumerator(int numerator){m_numerator = numerator;}
};

std:: ostream& operator << (std :: ostream& out, const Fraction &f1){
    out << f1.m_numerator << "/" << f1.m_denominator;
    return out;
}

/*
Both the arguent passed by value and return value cannot be ELIDED
*/
Fraction makeNegative(Fraction f){
    f.setNumerator(-f.getNumerator());
    return f;
}

/*
The compiler will ELIDE the copy constructor, even though variable s is returned
by value.
*/
Fraction getOneThird(){
    Fraction oneThrid(1,3);
    return oneThrid;
}

int main(){
    Fraction fiveThirds(5, 3);
    std :: cout << makeNegative(fiveThirds) << std :: endl;
    std :: cout << getOneThird() << std :: endl;
    return -1;

}
