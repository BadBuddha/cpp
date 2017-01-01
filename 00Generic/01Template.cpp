#include<iostream>

using namespace std;

// int integerMin(int a, int b){
//     return (((a < b)?a:b));
// }
//
template <typename T>
T genericMin(T a, T b){
    return (a < b ? a : b);
}




// template <typename T>
// BasicVector<T> :: BasicVector(int capac){
//     capacity = capac;
// }



int main(){
    cout << "inf : " << genericMin(13,12) << endl;
    cout << "inf : " << genericMin(1.3,1.2) << endl;
    cout << "inf : " << genericMin('t','g') << endl;
    return -1;
}
