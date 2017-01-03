#include <string>
#include <iostream>

using namespace std;

int main(){
	string str = "Test String";
	cout << "str.length: " << str.length() << endl;
	cout << "str.data: " << str.data()+1 << endl;
	return -1;
}
