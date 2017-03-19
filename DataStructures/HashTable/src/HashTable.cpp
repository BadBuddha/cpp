#include <iostream>
#include "HashEntry.h"
#include "HashMap.h"

using namespace std;

void doStuff(){
    HashMap map;
    map.put(1, 123);
    map.put(1234, 113);
    cout << "element at 1st key: " << map.get(1) << endl;
    cout << "element at 1234th key: " << map.get(1234) << endl;
}

int main(){
    doStuff();
    return -1;
}
