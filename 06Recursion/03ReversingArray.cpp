#include<iostream>
//#include<algorithm>
using namespace std;

typedef char Elem;

void reverse(Elem *first, Elem *last){
    if(first < last){
        swap(*first, *last);
        reverse(first+1, last-1);
    }
}


int main(){
    //Elem array[] = {1,2,3,4,5};
    Elem array[] = "abcdef";
    int size = (sizeof(array)/sizeof(Elem));
    reverse(array, array + (size-1) );
    for(int i = 0; i < size; i++){
        cout << "array: " << array[i] << endl;
    }
}
