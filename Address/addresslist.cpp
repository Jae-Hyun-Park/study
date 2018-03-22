#include <iostream>

using namespace std;

struct person {
	char name[20];
	char phone[20];
	int age;
	char address[20];
	struct person* next;
};

person* head = NULL;
person* tail = NULL;
person* list = head;

void errorMessege() {
	cout << "error!!" << endl;
	return;
}
void interval() {
	cout << "==================================" << endl;
	return;
}
struct person* prdAdress() {
	person* temp = new person;
	
	cout << "name = ";
	cin >> temp->name;

	cout << "phone = ";
	cin >> temp->phone;

	cout << "age : ";
	cin >> temp->age;

	cout << "address = ";
	cin >> temp->address;
	temp->next = NULL;
	return temp;
}
void insertTail() {
	person* temp = prdAdress();
	if (head == NULL && tail == NULL) {
		head = tail = temp;	temp->next = head;
		return;
	}
	tail->next = temp;
	tail = temp;
	return;
}
void deleteMiddle(int s) {
	person* deleteNode = head;
	if (head == NULL && tail == NULL) {
		errorMessege();
		return;
	}
	else if (head == tail) {
		head = tail = NULL;
		delete deleteNode;
		return;
	}
	else if (s == 1) {
		head = list = deleteNode->next;
		deleteNode->next = NULL;
		delete deleteNode;
		return;
	}
	for (int i = 0; i < s - 2; i++) {
		list = list->next;
		if (list->next == tail) {
			tail = list;
			deleteNode = list->next;
			list->next = NULL;
			list = head;
			delete deleteNode;
			return;
		}
	}
	deleteNode = list->next;
	list->next = deleteNode->next;
	list = head;
	deleteNode->next = NULL;
	delete deleteNode;
	return;
}
void edit(int PeditNumber) {
	int editNumber = 0;

	for (int i = 0; i < PeditNumber; i++) {
		list = list->next;
		if (list == NULL) {
			errorMessege();
			return;
		}
	}
	cout << "1. name = " << list->name << "\n2. phone = " << list->phone
		<< "\n3. age = " << list->age << "\n4. address = " << list->address << endl;

	interval();

	cout << "input number(1 ~ 4) = ";
	cin >> editNumber;

	cout << "input data = ";
	switch (editNumber)
	{
	case 1:
		cin >> list->name;
		break;
	case 2:
		cin >> list->phone;
		break;
	case 3:
		cin >> list->age;
		break;
	case 4:
		cin >> list->address;
		break;
	default:
		cout << "error!" << endl;
		edit(editNumber);
		list = head;
		return;
	}
	list = head;
	return;
}
void view(int PeditNumber) {
	for (int i = 0; i < PeditNumber - 1; i++) {
		list = list->next;
		if (list == NULL) {
			errorMessege();
			return;
		}
	}
	cout << "1. name = " << list->name << "\n2. phone = " << list->phone
		<< "\n3. age = " << list->age << "\n4. address = " << list->address << endl;
	list = head;
	interval();
	return;
}
int main(void) {
	int menuNumber = 0, editNumber = 0;

	while (true)
	{
		cout << "Menu = 1.Insert // 2.Edit // 3.Delete // 4. View // 5.Exit" << endl;
		cout << "input Number = ";
		cin >> menuNumber;

		switch (menuNumber)
		{
		case 1:
			insertTail();
			break;
		case 2:
			cout << "Input Edit Number = ";
			cin >> editNumber;
			edit(editNumber);
			break;
		case 3:
			cout << "Input Delete Number = ";
			cin >> editNumber;
			deleteMiddle(editNumber);
			break;
		case 4:
			cout << "Input View Number = ";
			cin >> editNumber;
			view(editNumber);
			break;
		case 5:
			return 0;
		default:
			errorMessege();
			break;
		}
	}
	return 0;
}