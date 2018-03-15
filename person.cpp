#include <iostream>

using namespace std;

struct Person {
	char name[20];
	char phone[20];
	int age;
	char address[20];
};

int main() {
	Person* persons[5] = { 0, };
	int personNumber = 0;

	for (int i = 0; i < 5; i++) {
		persons[i] = new Person;

		cout << "name = ";
		cin >> persons[i]->name;
		
		cout << "phone = ";
		cin >> persons[i]->phone;

		cout << "age = ";
		cin >> persons[i]->age;

		cout << "address = ";
		cin >> persons[i]->address;
		cout << persons[i] << endl;
	}

	cout << "Input person Number = ";
	cin >> personNumber;
	cout << personNumber << "'s Person : name = " << persons[personNumber]->name <<"\nphone = " 
		<< persons[personNumber]->phone << "\nage = " << persons[personNumber]->age << "\naddress = " 
		<< persons[personNumber]->address << endl;

	for (int i = 0; i < 5; i++) {
		delete persons[i];
		persons[i] = NULL;
	}
}