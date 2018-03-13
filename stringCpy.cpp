#include <iostream>

using namespace std;

void cpy(char* ptr, char* ptr2, int size) {
	
	for (int i = 0; i < size; i++)
		*ptr2++ = *ptr++;
	return;
}

int main() {
	char str[256];
	char str2[256];

	cout << "Input String = ";
	cin >> str;

	cout << "str = " << str << endl;
	cpy(str, str2, sizeof(str));

	cout << "str2 = " << str2 << endl;
}
