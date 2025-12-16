

#include <iostream>
#include <string>
using namespace std;
//Struct : stName
//variable:string FirstName & string LastName
struct stName {
	string FirstName;
	string LastName;
};


// fonction string : EnterString
//populate the string with your name
//Transactions: The message that will appear before the user enters a value.
// Returned value : The text entered by the user.
string EnterString(string Message) {

	string Text;                //variable to store the Text
	
	cout << Message << endl;    //Display a message asking the user to enter their Text
	getline(cin, Text);         //get the Text from user input
	
	return Text;                //return the Text
}

//fonction stName:ReadName
stName StName_ReadName() {
	stName Info;//A variable to store a value of type stName

	Info.FirstName = EnterString("Please Enter Your First Name?");
	Info.LastName = EnterString("Please Enter Your Last Name?");
	return Info;
}


//fonction string :PrintFullName
//populate the string with your full name
//Parameters:stName Info
//Returned value : The full name of the user.

string GetFullName(stName Info) {
	return Info.FirstName + " " + Info.LastName; //conatonation FirstName and LastName 
}
//proseger : the jod is this proseger it is Print fill name
//parameter :string FullName 
void PrintFullName(string FullName) {
	cout << "Your full name is :" << FullName << endl;
}

//function :HalfName
//parameter:short Number
//rerurn :This function gives half the number

float CalculateHalfName(short Number) {
	return ((float)Number / 2);
}

//proseger :PrintNumber
//parameter:short Number,string Message
//return :This is a proseger Prints Message and Number
void PrintNumber(string Message,float Nuamber) {
	cout << Message +to_string(Nuamber) << endl;
}

//function :ReatNumber
// parameter:stirng Message
//return :This Function displays the Message and get a number's user
short ReadNumber(string Message) {
	short Number;
	cout << Message << endl;
	cin >> Number;
	return Number;
}

//----------------------------------------------------------------------------------

//#8

//enum :enPassFail
//this is an enum can you use it to check whether the studant pass or not
enum enPassFail{Pass,Fail};
 

//function:CheckMark
//parameter:short Mark
//return :it check Mark is Pass or not
enPassFail enCheckMark(short Mark) {
	if (Mark >= 50)
		return enPassFail::Pass;
	else
		return enPassFail::Fail;
		
}

//prasager :PrintResults
//parameter:short Mark
//return :print Pass or Fail
void PrintResults(short Mark) {
	if (enCheckMark(Mark) == enPassFail::Pass)
		cout << "You Passed";
	else
		cout << "You Faild";
	
}


//------------------------------------------

//#9 

//functino:Sum
//parameter:short num1,short num2,short num3
//return : sum three numbers
short Sum(short num1, short num2, short num3) {
	return num1 + num2 + num3;
}

//------------------------------------------------------

//#10

float CalculaterAverage(short num1, short num2, short num3) {
	return (float)Sum(num1, num2, num3) / 3;
}
int main()
{

	// This line of code extracts the full name
	//PrintFullName(GetFullName(stNameReadName()));

	//this code Receives a number and gives you Hilf of that number
	//float Number = ReadNumber("enter the number ?");
	//PrintNumber("the half's Your number is :",CalculateHalfName(Number));

	//this code check the mark is pass or not 
	//short Mark = ReadNumber("enter the Nubmer?");
	//PrintResults(Mark);

	//this code sum three numbers
   //short num1, num2, num3;
	//num1 = ReadNumber("enter num1:");
	//num2 = ReadNumber("enter num2:");
	//num3 = ReadNumber("enter num3");
	//PrintNumber("Total is : ", Sum(num1, num2, num3));


	//this code sum three numbers
    short num1, num2, num3;
    num1 = ReadNumber("enter num1:");
    num2 = ReadNumber("enter num2:");
	num3 = ReadNumber("enter num3");
	PrintNumber("Average is : ", CalculaterAverage(num1, num2, num3));
}
