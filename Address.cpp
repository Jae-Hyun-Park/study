#include <iostream>

using namespace std;
struct Person {
	char name[20];
	char phone[20];
	int age;
	char address[20];
};

Person* people[10] = { 0, };
int personNumber = 0;

void interval() {
	cout << "====================" << endl;
}
void insertData() {
	people[personNumber] = new Person;
	
	cout << (personNumber+1) << "'s people " << endl;
	cout << "name = ";
	cin >> people[personNumber]->name;

	cout << "phone = ";
	cin >> people[personNumber]->phone;

	cout << "age = ";
	cin >> people[personNumber]->age;

	cout << "address = ";
	cin >> people[personNumber]->address;

	interval();

	cout << "1. name = " << people[personNumber]->name << "\n2. phone = " << people[personNumber]->phone
		<< "\n3. age = " << people[personNumber]->age << "\n4. address = " << people[personNumber]->address << endl;

	interval();

	personNumber++;
	return;
}
void editData(int number) {
	int edit = 0;
	cout << "1. name = " << people[number - 1]->name << "\n2. phone = " << people[number - 1]->phone
		<< "\n3. age = " << people[number - 1]->age << "\n4. address = " << people[number - 1]->address << endl;
	
	interval();

	cout << "input number(1 ~ 4) = ";
	cin >> edit;

	cout << "input data = ";
	switch (edit)
	{
	case 1:
		cin >> people[number - 1]->name;
		break;
	case 2:
		cin >> people[number - 1]->phone;
		break;
	case 3:
		cin >> people[number - 1]->age;
		break;
	case 4:
		cin >> people[number - 1]->address;
		break;
	default:
		cout << "error!" << endl;
		editData(number);
		return;
	}

	interval();
	cout << "1. name = " << people[number - 1]->name << "\n2. phone = " << people[number - 1]->phone
		<< "\n3. age = " << people[number - 1]->age << "\n4. address = " << people[number - 1]->address << endl;
	interval();
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
		cout << "Menu = 1.insert // 2.Edit // 3.delete // 4.Exit" << endl;
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
			deleteData();
			break;
		case 4:
			return 0;
		default:
			cout << "error!" << endl;
			break;
		}
	}
	return 0;
}