// Lesson #41 - Arrays f Structure.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
struct stStudent {
	string FirstName;
	string LastName;
	short Age;
	string Phone;
};
void printStudent(stStudent student) {
	cout << "***********************************************************\n";
	cout << "First Name: " << student.FirstName << endl;
	cout << "Last Name: " << student.LastName << endl;
	cout << "Age: " << student.Age << endl;
	cout << "Phone: " << student.Phone << endl;
	cout << "***********************************************************\n";
}
void ReadStudentData(stStudent &students) {
	
		cout << "Enter student first name: ";
		cin >> students.FirstName;
		cout << "Enter student last name: ";
		cin >> students.LastName;
		cout << "Enter student age: ";
		cin >> students.Age;
		cout << "Enter student phone: ";
		cin >> students.Phone;
	
}
void ReadStudentsData(stStudent students[], int size) {
	for (int i = 0; i < size; i++) {
		ReadStudentData(students[i]);
	}
}
void printStudents(stStudent students[], int size) {
	for (int i = 0; i < size; i++) {
		printStudent(students[i]);
	}
}

int main()
{
	stStudent Student[2];
	ReadStudentData(Student[0]);
	printStudent(Student[0]);
	system("cls");
	system("pause>0");
	ReadStudentsData(Student, 2);

	printStudents(Student, 2);

	return 0;

}

