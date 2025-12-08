
#include <iostream>
using namespace std;
int main()
{
	//signed int _signed_int;
	int _int;//this is same as 'signed int' range -2147483648 to 2147483647

	unsigned int _unsigned_int; //range 0 to 4294967295

	//short int _short_int;
	short _short; //this is same as short int -32768 to 32767

	//unsigned short int _unsigned_short_int;
	unsigned short _unsigned_short;//this is same as 'unsigned short int' ronge 0 to 65535


	//signed long int _signed_long_int;
	//long int _long_int;
	long _long;//this is same as 'singned long int' or 'long int' range -9223372036854775808 to 9223372036854775807 

	unsigned long _unsigned_long;//range 0 to 18446744073709551615
	

	long long int _long_long_int;//range -9223372036854775808 to 9223372036854775807

	unsigned long long _unsigned_long_long;//range 0 to 18446744073709551615

	long double _long_double;//range 10 e-307 to 10 e+308


	//signed char _signed_char;
	char _char;//this is same as 'signed char'  range -128 to 127

	unsigned char _unsigned_char; //range 0 to 255



	cout << "---------------------------------------------------------------------------------------\n\n";
	cout << "char Range : (" << CHAR_MIN << ", " << CHAR_MAX << ")\tSize (bytes) : " << sizeof(char) <<"\n";
	cout << "unsigned char Range : (" << 0 << ", " << UCHAR_MAX << ")\tSize (bytes) : " << sizeof(char) << "\n\n";

	cout << "short Range : (" << SHRT_MIN << ", " << SHRT_MAX << ")\tSize (bytes) : " << sizeof(short) << "\n";
	cout << "unsigned short Range : (" << 0 << ", " << USHRT_MAX << ")\tSize (bytes) : " << sizeof(short) << "\n\n";
	
	cout << "int Range : (" << 0 << ", " << INT_MAX << ")\tSize (bytes) : " << sizeof(int) << "\n";
	cout << "unsigned int Range : (" << 0 << ", " << UINT_MAX << ")\tSize (bytes) : " << sizeof(int) << "\n";
	cout << "long int Range : (" << LONG_MIN << ", " << LONG_MAX << ")\tSize (bytes) : " << sizeof(long int) << "\n";
	cout << "unsigned long int Range : (" << 0 << ", " << ULONG_MAX << ")\tSize (bytes) : " << sizeof(long int) << "\n\n";

	cout << "long long int Range : (" << LLONG_MIN << ", " << LLONG_MAX << ")\tSize (bytes) : " << sizeof(long long int) << "\n";
	cout << "unsigned long long int Range : (" << 0 << ", " << ULLONG_MAX << ")\tSize (bytes) : " << sizeof(long long int) << "\n\n";
	

	cout << "float  Range : (" << FLT_MIN << ", " <<FLT_MAX << ")\tSize (bytes) : " << sizeof(float) << "\n";
	cout << "float(negative) Range : (" << -FLT_MIN << ", " << -FLT_MAX << ")\tSize (bytes) : " << sizeof(long int) << "\n\n";
	
	cout << "double  Range : (" << DBL_MIN << ", " << DBL_MAX << ")\tSize (bytes) : " << sizeof(double) << "\n";
	cout << "float(negative) Range : (" << -DBL_MIN << ", " << -DBL_MAX << ")\tSize (bytes) : " << sizeof(double) << "\n";
	cout << "long double  Range : (" << LDBL_MIN_10_EXP << ", " << LDBL_MAX_10_EXP << ")\tSize (bytes) : " << sizeof(double) << "\n\n";


	cout << "---------------------------------------------------------------------------------------\n";

	return 0;
}
