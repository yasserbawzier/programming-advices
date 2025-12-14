// Lesson #45 - Switch Case Statement.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
enum enOperationType
{
	Add = '+',
	Subtract = '-',
	Multiply = '*',
	Divide = '/'
};
enum enDaysOfWeek{
	Saturday,
	Sunday,
	Monday,
	Tuesday,
	Wednesday,
	Thursday,
	Friday
};
float Calculate(enOperationType Operation,float num1, float num2)
{
	switch (Operation) {
	case enOperationType::Add:
		return num1 + num2;
	case enOperationType::Subtract:
		return num1 - num2;
	case enOperationType::Multiply:
		return num1 * num2;
	case enOperationType::Divide:
		return num1 / num2;
	}
}
float ReadNumber(string Message) {
	float Number;
	cout << Message;
	cin >> Number;
	return Number;
}
char ReadOperationType(string Message) {
	char Operation;
	cout << Message;
	cin >> Operation;
	return Operation;
}
void PrintDayOfWeek(short DayNumber) {
	switch (DayNumber) {
	case enDaysOfWeek::Saturday:
		cout << "It's Saturday";
		break;
	case enDaysOfWeek::Sunday:
		cout << "It's Sunday";
		break;
	case enDaysOfWeek::Monday:
		cout << "It's Monday:";
		break;
	case enDaysOfWeek::Thursday:
		cout << "It's Thursday";
		break;
	case enDaysOfWeek::Tuesday:
		cout << "It's Tuesday";
		break;
	case enDaysOfWeek::Wednesday:
		cout << "It's Wednesday";
		break;
	case enDaysOfWeek::Friday:
		cout << "It's Friday";
		break;
	default :
		cout << "the entered number does not exist";
	}
}
int main()
{
	//this is problem #36 - Simple Calculator 
	/*
	cout << Calculate((enOperationType)ReadOperationType("enter the Operation (+,-,*,/):"), ReadNumber("enter the num2:"), ReadNumber("enter the num1:"));
	*/
	
	//this is Problem #44 - day Of Week 
	/*
	PrintDayOfWeek((short)ReadNumber("enter the number Day:\n(1)Sunday\n(2)Monday\n(3)Tuesday\n(4)Wednesday\n(5)Thursday\n(6)Friday\n(7)Saturday\nthe number is :"));
	*/
	return 0;
}
