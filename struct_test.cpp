#include <iostream>

using namespace std;

struct node {
	int data;
	struct node* next;
};

node* head = NULL;
node* tail = NULL;
node* list = head;

void errorMessege() {
	cout << "error!!" << endl;
}
void interval() {
	cout << "==================================" << endl;
}
struct node* prdNode(int xdata) {
	node* temp = new node;
	temp->data = xdata;
	temp->next = NULL;

	return temp;
}
void insertHeadData(int xdata) {
	node* temp = prdNode(xdata);
	if (head == NULL && tail == NULL) {
		head = tail = temp;	temp->next = head;
		return;
	}
	temp->next = head;
	head = temp;
	return;
}
void insertMiddleData(int xdata, int s) {
	node* temp = prdNode(xdata);

	if (head == NULL && tail == NULL) {
		head = tail = temp;	temp->next = head;
		return;
	}else if (s == 1) {
		temp->next = head;
		head = temp;
		return;
	}
	for (int i = 0; i < s - 2; i++) {
		list = list->next;
		if (list->next == NULL) {
			list->next = temp;
			tail = temp;
			return;
		}
	}
	temp->next = list->next;
	list->next = temp;
	list = head;
	return;
}
void insertTailData(int xdata) {
	node* temp = prdNode(xdata);
	if (head == NULL && tail == NULL) {
		head = tail = temp;	temp->next = head;
		return;
	}
	tail->next = temp;
	tail = temp;
}
void deleteHeadData() {
	if (head == NULL && tail == NULL) {
		errorMessege();
		return;
	}else if (head == tail){
		head = tail = NULL;
		return;
	}
	node* deleteNode = head;
	head = list = deleteNode->next;
	deleteNode->next = NULL;
	delete deleteNode;
	return;
}
void deleteMiddleData(int s) {
	node* deleteNode = head;
	if (head == NULL && tail == NULL) {
		errorMessege();
		return;
	}else if (head == tail) {
		head = tail = NULL;
		return;
	}else if (s == 1) {
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

}
void deleteTailData() {
	node* deleteNode = NULL;
	if (head == NULL && tail == NULL) {
		errorMessege();
		return;
	}
	else if (head == tail) {
		head = tail = NULL;
		return;
	}
	while (list->next->next != NULL) {
		list = list->next;
	}
	tail = list;
	deleteNode = list->next;
	list->next = NULL;
	list = head;
	delete deleteNode;	
}
void editData(int editNumber, int data) {
	for (int i = 0; i < editNumber; i++) {
		list->next;
		if (list == NULL) {
			errorMessege();
			return;
		}
	}
	list->data = data;
	return;
}
int main(void) {
	int data = 0, menuNumber = 0, editNumber = 0;

	while (true)
	{
		cout << "Menu = 1.insert // 2.Edit // 3.delete // 4.Exit" << endl;
		cout << "input Number = ";
		cin >> menuNumber;

		cout << "input Data = ";
		cin >> data;
		switch (menuNumber)
		{
		case 1:
			insertTailData(data);
			break;
		case 2:
			cout << "Input Edit Number = ";
			cin >> editNumber;
			cout << "Input Data = ";
			cin >> data;

			break;
		case 3:
			deleteTailData();
			break;
		case 4:
			return 0;
		default:
			errorMessege();
			break;
		}
	}
return 0;
}