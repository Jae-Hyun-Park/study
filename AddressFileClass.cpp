#include <iostream>
#include <stdio.h>
using namespace std;

int personNumber = 0;

struct Person {
	char name[20];
	char phone[20];
	int age;
	char address[20];

	void interval() {
		cout << "====================" << endl;
		return;
	}
	void insertName() {
		cout << "name = ";
		cin >> name;
		return;
	}
	void insertPhone() {
		cout << "phone = ";
		cin >> phone;
		return;
	}
	void insertAge() {
		cout << "age = ";
		cin >> age;
		return;
	}
	void insertAddress() {
		cout << "address = ";
		cin >> address;		
		return;
	}
	void print() {
		cout << "1. name = " << name << "\n2. phone = " << phone
			<< "\n3. age = " << age << "\n4. address = " << address << endl;
		return;
	}
};

Person* people[10] = { 0, };

void insertFile() {
	FILE* add = fopen("address.txt", "wt");

	for (int i = 0; i <= personNumber; i++) {
		if (people[i] == NULL)
			break;
		fprintf(add, "%s %s %d %s\r\n", people[i]->name, people[i]->phone, people[i]->age, people[i]->address);
	}
	fclose(add);
	return;
}
void ViewFile() {
	FILE* ld = fopen("address.txt", "rt");

	while (!feof(ld)) {
		people[personNumber] = new Person;
		fscanf(ld, "%s %s %d %s\r\n", people[personNumber]->name, people[personNumber]->phone, &(people[personNumber]->age), people[personNumber]->address);
		personNumber++;
	}
	return;
}
void insertData() {
	people[personNumber] = new Person;

	cout << (personNumber + 1) << "'s people " << endl;
	people[personNumber]->insertName();
	people[personNumber]->insertPhone();
	people[personNumber]->insertAge();
	people[personNumber]->insertAddress();
	insertFile();
	people[personNumber]->interval();
	people[personNumber]->print();
	people[personNumber]->interval();
	personNumber++;
	return;
}
void editData(int number) {
	int edit = 0;
	people[number - 1]->print();
	people[personNumber]->interval();

	cout << "input number(1 ~ 4) = ";
	cin >> edit;

	cout << "input data = ";
	switch (edit)
	{
	case 1:
		people[number - 1]->insertName();
		break;
	case 2:
		people[number - 1]->insertPhone();
		break;
	case 3:
		people[number - 1]->insertAge();
		break;
	case 4:
		people[number - 1]->insertAddress();
		break;
	default:
		cout << "error!" << endl;
		editData(number);
		return;
	}

	people[personNumber]->interval();
	insertFile();
	people[number - 1]->print();
	people[personNumber]->interval();
	return;
}
void deleteData() {
	int number = 0;
	cout << "input delete Number = ";
	cin >> number;
	for (int i = number; i < 9; i++) {
		delete people[number];
		people[i] = people[i + 1];
		people[i + 1] = NULL;
	}
	personNumber--;
	insertFile();
	return;
}
int main() {
	int menuNumber = 0;
	int editNumber = 0;
	while (true)
	{
		cout << "Menu = 1.insert // 2.Edit // 3. View // 4.delete // 5.Exit" << endl;
		cout << "input Number = ";
		cin >> menuNumber;

		switch (menuNumber)
		{
		case 1:
			if (personNumber >= 10) {
				cout << "error! Address is Full" << endl;
				break;
			}
			insertData();
			break;
		case 2:
			cout << "Input Edit Number = ";
			cin >> editNumber;
			if (people[editNumber - 1] == NULL) {
				cout << "error!" << endl;
				break;
			}
			editData(editNumber);
			break;
		case 3:
			personNumber = 0;
			ViewFile();
			cout << "Input View Number = ";
			cin >> editNumber;
			people[editNumber - 1]->print();
			break;
		case 4:
			deleteData();
			break;
		case 5:
			return 0;
		default:
			cout << "error!" << endl;
			break;
		}
	}
	return 0;
}