#include<iostream>
#include<string.h>
using namespace std;

class Student {

	public:

	char *name;
	int roll_number;
	char section;
	static int strength;

	Student () {

		cout << "The object is created via a simple constructor." << endl << endl;

		name = new char[100];

	}

	Student (char *name, int roll_number, char section) {

		cout << "The object is created via a parametrized constructor." << endl << endl;

		this-> name = name;
		this-> roll_number = roll_number;
		this-> section = section;
	}

	Student (Student &student) {

		cout << "The object is created via a copy constructor." << endl << endl;

		char *ch = new char[strlen(student.name)];
		strcpy(ch,student.name);

	    this-> name = ch;
		this-> roll_number = student.roll_number;
		this-> section = student.section;
		this-> age = student.age;
		this-> weight = student.weight;
		this-> height = student.height;
	}

	private:

	int age;
	int weight;
	int height;

	public:

	void set_age (int age) {

		this-> age = age;
	}

	int get_age () {

		return this-> age;
	}

	void set_weight (int weight) {

		this-> weight = weight;
	}

	int get_weight () {

		return this-> weight;
	}

	void set_height (int height) {

		this-> height = height;
	}

	int get_height () {

		return this-> height;
	}

	static int get_strength() {

		return strength;
	}

	~ Student () {

		cout << "The object has been deleted permanently." << endl << endl;

	}
};

int Student::strength = 50;

int main() {

	cout << endl;

	Student student_01;

	cout << "The strength of the classroom is: " << Student::strength << endl;
	cout << "The strength of the classroom is: " << Student::get_strength() << endl << endl;

	char name[] = "Balaji";

	student_01.name = name;
	student_01.roll_number = 41;
	student_01.section = 'B';

	student_01.set_age(18);
	student_01.set_weight(78);
	student_01.set_height(190);

	cout << "Name: " << student_01.name << endl;
	cout << "Roll Number: " << student_01.roll_number << endl;
	cout << "Section: " << student_01.section << endl;
	cout << "Age: " << student_01.get_age() << endl;
	cout << "Weight: " << student_01.get_weight() << endl;
	cout << "Height: " << student_01.get_height() << endl;

	cout << endl;

	Student student_02 = student_01;

	cout << "Name: " << student_02.name << endl;
	cout << "Roll Number: " << student_02.roll_number << endl;
	cout << "Section: " << student_02.section << endl;
	cout << "Age: " << student_02.get_age() << endl;
	cout << "Weight: " << student_02.get_weight() << endl;
	cout << "Height: " << student_02.get_height() << endl;

	cout << endl;

	name[0] = 'K';

	cout << "Name of Stduent 01: " << student_01.name << endl;
	cout << "Name of Student 02: " << student_02.name << endl;

	cout << endl;

	return 0;
}
