//Uniform initialization and delegating constructors
// Compile with -std=c++11

/*
If the type has no declared constructor, the order in which the
members appear in the brace initializer is the same as the order in which
they are declared; in this case, you can initialize as many of the public
members as you wish, but you cannot skip any member.
The following example shows the order that's used in brace initialization
when there is no declared constructor
class_b
*/


#include <string>
#include <iostream>
using namespace std;


class class_a{
    private:
        double m_double;
        string m_string;
    public:
        class_a() {};
        class_a(string str) : m_string{str}{}
        class_a(string str, double dbl): m_string{str}, m_double{dbl} {}
};

class class_b{
    public:
        double m_double;
        string m_string;
};

class_b getClass_b(){
    return {7.8, "getClass_b"};
    // because of uniform initialization
    // we can minimize redudant typenames;
    // return class {7.8, "getClass_b"};
}

int main(){
    class_a c1{};
    class_a c1_1;

    class_a c2{"ww"};
    class_a c2_1("xx");

    // order of parameters is the same as the constructor
    class_a c3{ "yy", 4.4 };
    class_a c3_1{"zz", 5.5};

    class_b c4{};
    class_b c4_1{4.5};
    class_b c4_2{4.5, "a"};
    cout << "a: " << getClass_b().m_double;
    // gives compiler error
    //class_b c4_3("a", 4.5);
}
