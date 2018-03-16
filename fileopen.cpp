#include <iostream>

using namespace std;

int& inco(){
	int val = 40;
	return ++val;
}
int main() {
	int& ref = inco();
	cout << ref << endl;
	return 0;
}