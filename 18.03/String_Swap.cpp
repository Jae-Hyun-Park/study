#include <iostream>

using namespace std;

int main() {
	const int max = 6;
	char str[max] = "Hello";
	char* ptr = str;
	char* ptr2 = str;
	char temp = 0;

	cout << str << endl;

	for (int i = 0; i < (max / 2); i++) {
		temp = *ptr;
		*ptr = *(ptr2 + max - (i + 2));
		cout << temp << endl;
		*(ptr2 + max - (i + 2)) = temp;
		ptr++;
	}

	cout << str << endl;
}
