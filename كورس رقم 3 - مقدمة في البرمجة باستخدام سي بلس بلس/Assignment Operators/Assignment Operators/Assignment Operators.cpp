//Assignment Operators in C++ are used to assign values to variables.
//Assignment operators it is like =, +=, -=, *=, /=, %=, <<=, >>=, &=, ^=, |= etc.
#include <iostream>
using namespace std;
int main()
{
	int A = 10, B=20;

	A += B;// A = A + B
	cout << "A = " << A << endl;


	A -= B;// A = A - B
	cout << "A = " << A << endl;



	A *= B;// A = A * B
	cout << "A = " << A << endl;



	A /= B;// A = A / B
	cout << "A = " << A << endl;

	A %= B;// A = A % B
	cout << "A = " << A << endl;

}
