
#include <iostream>
using namespace std;
int main()
{
	//(increase)سيزيد
	int A = 10;
	int B = A++;//B will tke the old value of A, then A will increase by 1

	cout << "B = " << B << endl;
	cout << "A = " << A << endl;

	B = ++A;//A will increase by 1 , then B will take the new value of A
	
	cout << "B = " << B << endl;
	cout << "A = " << A << endl;


}