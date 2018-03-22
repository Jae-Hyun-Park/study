#include "LinkedList.h"

struct Person {
	char name[20];
	int age;
};

int main(int argc, char* argv[]) {
	LinkedList<Person*> people;
	Person* p1 = new Person;
	strcpy(p1->name, "박재현");
	p1->age = 26;
	people.AddTail(p1);

	Person* p2 = new Person;
	strcpy(p2->name, "asdf");
	p2->age = 25;
	people.AddHead(p2);

	Person* p3 = new Person;
	strcpy(p3->name, "qwer");
	p3->age = 40;
	people.Insert(p3, 1);
	people.Remove(2);
	for (unsigned int i = 0; i < people.Size(); ++i) {
		Person* person = people.At(i);
		if (person != NULL) {
			cout << i << "번째 데이터 : " << endl;
			cout << "name = " << person->name << endl;
			cout << "age = " << person->age << endl;
		}
	}
	cout << "=== 요소 삭제후 출력 =====" << endl;

	Person* person = people.At(0);
	if (person != NULL)
		delete person;
	people.Clear();
	return 0;
}