

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
void PrintNumber(string Message,float Nuamber=0) {
	if(Nuamber==0)
		cout << Message << endl;
	else
	cout << Message +to_string(Nuamber) << endl;
}

//function :ReatNumber
// parameter:stirng Message
//return :This Function displays the Message and get a number's user
short ReadNumber(string Message) {
	short Number;
	cout << Message ;
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
void PrintResults(enPassFail Mark) {
	if (Mark == enPassFail::Pass)
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

//--------------------------------------------------------
// #11
// function:enCheckAverage
//parameter:short TotalMark
// return :this function check average is pass or not
enPassFail enCheckAverage(short TotalMark)
{
	if (TotalMark < 50)
		return enPassFail::Fail;
	else
		return enPassFail::Pass;
}


//--------------------------------------------------------
// #12
//function :MaxOf2Number
//Parameter:short num1,short num2
//return :it is chacke they numbers and give you largeNumber
short MaxOf2Number(float num1, float num2) {
	
	 if (num2 == num1)
		return num1;//equal
	 else if (num1 > num2)
		 return num1;
	else
		return num2;

}

//--------------------------------------------------------
// #13
//function :MaxOf3Number
//Parameter:float num1,float num2,float num3
//return :it is chacke they numbers and give you Max number
short MaxOf3Number(float num1, float num2,float num3) {
	return MaxOf2Number(MaxOf2Number(num1, num2),num3);
}


//--------------------------------------------------------
// #14
//proseager:SwapTwoNumbers
//Parameters:float num1,float num2
//Return: This is the code that can be used to switch between two numbers
void SwapTwoNumbers(float &num1, float &num2) {
	float swithc = num1;
	num1 = num2;
	num2 = swithc;
	

}

//--------------------------------------------------------
// #15
//function:CalculateRectangArea
//Parameters:float Lenth,float width
//return :this function is can it find rectang area
float CalculateRectangArea(float Lenth, float Width) {
	return Lenth * Width; 
}


int main()
{

	// This line of code extracts the full name
	/*
	PrintFullName(GetFullName(stNameReadName()));
	*/

	//this code Receives a number and gives you Hilf of that number
	/*
	float Number = ReadNumber("enter the number ?");
	PrintNumber("the half's Your number is :",CalculateHalfName(Number));
	*/
	

	//this code check the mark is pass or not 
	/*
	short Mark = ReadNumber("enter the Mark?");
	PrintResults(enCheckMark(Mark));
	*/

	//this code sum three numbers
	/*
   short num1, num2, num3;
	num1 = ReadNumber("enter num1:");
	num2 = ReadNumber("enter num2:");
	num3 = ReadNumber("enter num3");
	PrintNumber("Total is : ", Sum(num1, num2, num3));
	*/

	//this code sum three numbers
	/*
    short num1, num2, num3;
    num1 = ReadNumber("enter num1:");
    num2 = ReadNumber("enter num2:");
	num3 = ReadNumber("enter num3");
	PrintNumber("Average is : ", CalculaterAverage(num1, num2, num3));
	*/

	//this code check the Avrage is pass or not 
	/*
	short Avrage = ReadNumber("enter the Avrage?");
	PrintResults(enCheckAverage(Avrage));
	*/

	//this code print the bigger number
	/*
	short num1, num2;
	num1 = ReadNumber("enter a num1:");
	num2 = ReadNumber("enter a num2:");
	PrintNumber("Large numbe is :", MaxOf2Number(num1, num2));
	*/

	//this cod print the Max number between 3 numbers
	/*
	short num1, num2,num3;
	num1 = ReadNumber("enter a num1:");
	num2 = ReadNumber("enter a num2:");
	num3 = ReadNumber("enter a num3:");
	PrintNumber("Large numbe is :", MaxOf3Number(num1, num2,num3));
	*/

	//this code do be swap between two numbers
	/*
	float num1, num2;
	num1 = ReadNumber("enter the num1:");
	num2 = ReadNumber("enter the num2:");
	
	PrintNumber("they numbers beform swap");
	PrintNumber("num1=", num1);
	PrintNumber("num2=", num2);
	
	SwapTwoNumbers(num1, num2);
	
	PrintNumber("they numbers after swap");
	PrintNumber("num1=", num1);
	PrintNumber("num2=", num2);
	*/


	//this code calculate rctangl area
	/*
	float Lenth, Width;
	Lenth = ReadNumber("enter the Lenth:");
	Width = ReadNumber("enter the Width:");
	
	PrintNumber("the calculat rctangl area is :", CalculateRectangArea(Lenth, Width));
	*/
}
