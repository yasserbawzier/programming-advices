// Lesson #25 - Logical Operators

#include <iostream>
using namespace std;
int main()
{
	bool A = true, B = false;
	cout << (A && B) << endl;
	cout << (A || B) << endl;
	cout << (!A) << endl;
	cout << (!B) << endl;
	cout << !(A && B) << endl;
	cout << !(A || B) << endl;
	return 0;
}