#include <iostream>

using namespace std;

int sum(int array[], int n){
    if(n == 0)
        return array[n];
    else
        return (array[n] + sum(array, n-1));
}

int main(){
    int array[] = {1,2,3,4,5,6,7,8,9,10};
    cout << "Sum : " << sum(array, sizeof(array)/sizeof(int)-1) << endl;
}
