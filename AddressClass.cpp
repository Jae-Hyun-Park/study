#include <iostream>

using namespace std;

struct Person {
	char name[20];
	char phone[20];
	int age;
	char address[20];

	void interval() {
		cout << "====================" << endl;
	}
	void insertName() {
		cout << "name = ";
		cin >> name;
	}
	void insertPhone() {
		cout << "phone = ";
		cin >> phone;
	}
	void insertAge() {
		cout << "age = ";
		cin >> age;
	}
	void insertAddress() {
		cout << "address = ";
		cin >> address;
	}
	void print() {
		cout << "1. name = " << name << "\n2. phone = " << phone
			<< "\n3. age = " << age << "\n4. address = " << address << endl;
	}
};

Person* people[10] = { 0, };
int personNumber = 0;

void insertData() {
	people[personNumber] = new Person;

	cout << (personNumber + 1) << "'s people " << endl;
	people[personNumber]->insertName();
	people[personNumber]->insertPhone();
	people[personNumber]->insertAge();
	people[personNumber]->insertAddress();
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
