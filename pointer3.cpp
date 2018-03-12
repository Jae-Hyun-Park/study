#include <iostream>

using namespace std;

int main() {
	int arr1[5] = { 9, 6, 8, 7, 4 };
	int arr2[5] = { 5, 4, 3, 2, 1 };
	int* ptr1 = arr1;
	int* ptr2 = arr2;
	int number1 = 0;
	int number2 = 0;
	int temp = 0;
	
	cout << "변경전 arr1 : ";
	for (int i = 0; i < 5; i++) {
		cout << *(ptr1 + i);
	}
	cout << "\n========================\n변경전 arr2 : ";
	for (int i = 0; i < 5; i++) {
		cout << *(ptr2 + i);
	}
	cout << "\n========================" << endl;

	cout << "Input First Number = ";
	cin >> number1;

	cout << "Input Second Number = ";
	cin >> number2;

	temp = *(ptr1 + number1);
	*(ptr1 + number1) = *(ptr2 + number2);
	*(ptr2 + number2) = temp;

	cout << "변경후 arr1 : ";
	for (int i = 0; i < 5; i++) {
		cout << *(ptr1 + i);
	}
	cout << "\n========================\n 변경후 arr2 : ";
	for (int i = 0; i < 5; i++) {
		cout << *(ptr2 + i);
	}
	cout << "\n========================" << endl;

	return 0;
}