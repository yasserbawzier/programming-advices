

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
	cout << Message <<Nuamber << endl;
}

//function :ReatNumber
// parameter:stirng Message
//return :This Function displays the Message and get a number's user
int ReadNumber(string Message) {
	int Number;
	cout << Message ;
	cin >> Number;
	return Number;
}

//----------------------------------------------------------------------------------

//#8

//enum :enPassFail
//this is an enum can you use it to check whether the studant pass or not
enum enPassFail{Pass=1,Fail=0};
 

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


//--------------------------------------------------------
// #16

//function:calculateSquareRoot
//Parameters:double Number
//reutrn : this ia a function that you can use to get the root
double calculateSquareRoot(double n) {
	//ما قدرت احله حاولت ساعه وبعدها استعنت بالذكاء الاصطناعي
	
	// Starting with an initial guess
	double x = n;
	double y = 1;

	// e represents the precision (accuracy level)
	double e = 0.000001;

	while (x - y > e) {
		x = (x + y) / 2;
		y = n / x;
	}
	return x;
}

//function:CaluculateRectangleAreaByDiagonalAndSideArea
//parameters:float Diogonal, float SideArea
// return :this is a function thay you can use to get the Rectangle Area By Side And Diagonal
float CaluculateRectangleAreaByDiagonalAndSideArea(float Diogonal, float SideArea) {
	float area= Diogonal * calculateSquareRoot(pow(SideArea, 2)- pow(Diogonal, 2));
	return area;
}


//--------------------------------------------------------
// #17
//function:CaluculaterTriangleArea
//parameters:float Height, float Base
//return :this is a function that can you use to get Triangle Area
float CaluculaterTriangleArea(float Height, float Base) {
	return (Base/2) * Height;
 

}


//--------------------------------------------------------
// #18
//function:CalculateCircleArea
//parameters:float Radius
//return :this is a function that can you use to get Circle Area
const float PI = 3.14159;
float CalculateCircleArea(float Radius) {
	
	   return PI * pow(Radius, 2);
	 
}

//--------------------------------------------------------
//#19
//function:CalculateCircleByDiameter
//parameters:float Diameter
//return :this is a function that can you use to get Circle Area By Diameter
float CalculateCircleByDiameter(float Diameter) {

	return (PI*pow(Diameter,2))/4;
}

//--------------------------------------------------------
//#20
//function:CalculateCircleInsidSequare
//parameters:float AreaSequar
//return :this is a function that can you use to get Circle Insid Sequare
float CalculateCircleInsidSequare(float AreaSequar) {
	return (PI * pow(AreaSequar,2))/4 ;
}


//--------------------------------------------------------
//#21
//function:CalculateCircleByCircumference
//parameters:float Circumference
//return :this is a function that can you use to get Circle Area By Circumference
float CalculateCircleByCircumference(float Circumference) {
	return pow(Circumference , 2)/(4 * PI);
}


//--------------------------------------------------------
//#22
//function:CalculateCircleByIsoscelesTriangle
//parameters:float Base,float Height
//return :this is a function that can you use to get Circle Area By Isosceles Triangle
float CalculateCircleByIsoscelesTriangle(float Height, float Base) {
	float R = PI * (pow(Base, 2) / 4) * ((2 * Height - Base) / (2 * Height + Base));

	return R;
}

//--------------------------------------------------------
//#23
//function:CalculateCircleAreaByArbitraryTriangle
//parameters:float SideA,float SideB,float SideC
//return :this is a function that can you use to get Circle Area By Arbitrary Triangle
float CalculateCircleAreaByArbitraryTriangle(float SideA, float SideB, float SideC) {
	float s = (SideA + SideB + SideC) / 2; 
	float T = (SideA * SideB * SideC) / (4 * calculateSquareRoot(s * (s - SideA) * (s - SideB) * (s - SideC)));
	return PI * pow(T, 2);
}

//--------------------------------------------------------
//#24
//function:ValidateNumberInRange
//parameters:short Number,short From,short To
//return :this is a function that can you use to validate number in range
bool ValidateNumberInRange(short Number, short From, short To) {
	return (Number >= From && Number <= To);
}

//--------------------------------------------------------
//#25
//function:readNumberInLoop
//parameters:short From,short To,string Message
//return :this is a function that can you use to read number in range
short readNumberInLoop(string Message, short From, short To) {
	short Number;
	do {
		Number = ReadNumber(Message);
	} while (!ValidateNumberInRange(Number, From, To));
	return Number;
}
//--------------------------------------------------------
//#26
//function:PrintRangeFrom1toN
//parameters:short number
//return :this is a function that can you use to print range from 1 to N
void PrintRangeFrom1toN(short number)
{
	for (short i = 1; i <= number; i++) {
		cout << i << ",";
	}
	cout << endl;
}

//--------------------------------------------------------
//#27
//function:PrintRangeFromNto1
//parameters:short number
//return :this is a function that can you use to print range from N to 1
void PrintRangeFromNto1(short number)
{
	for (short i = number; i >= 1; i--) {
		cout << i << ",";
	}
	cout << endl;
}



//--------------------------------------------------------
//#28

enum enOddOrEven{Odd=1,Even=0};

//function:CheckOddorEven
//parameters:shrot number
//return :this is a function Check is it the Odd number or the Even nubmer
enOddOrEven CheckOddOrEven(short number) {
	if (number % 2 == 0)
		return enOddOrEven::Even;
	else
		return enOddOrEven::Odd;
}
//function:SumOddNumbersFrom1ToN
//parameters:short Number
//return :this is a function to calculate the sum of odd numbers from 1 to N
short SumOddNumbersFrom1ToN(short Number) {
	short sum = 0;
	for (int i = 1; i <= Number; i++) {
		if(CheckOddOrEven(i)==enOddOrEven::Odd)
		sum +=i;
	}
	return sum;
}


//--------------------------------------------------------
//#29
//function:SumEvenNumbersFrom1ToN
//parameters:short Number
//return :this is a function to calculate the sum of Even numbers from 1 to N
short SumEvenNumbersFrom1ToN(short Number) {
	short sum = 0;
	for (int i = 1; i <= Number; i++) {
		if (CheckOddOrEven(i) == enOddOrEven::Even)
			sum += i;
	}
	return sum;
}


//--------------------------------------------------------
//#30

//function:ReadPositiveNumber
//parameters:string Message
//return : this function is read positive number jsut
short ReadPositiveNumber(string Message) {
	short number;
	do
	{
		cout << Message;
		cin >> number;
	} while (number<0);
	return number;
}

//function:FactorialOfNumber
//parameters:short Number
//return : this function is give you factorial Number
short FactorialOfNumber(short Number)
{
	short sum = 1;
	for (int i = 1; i <= Number; i++) {
		sum *= i;
	}
	return sum;
}




//--------------------------------------------------------
//#32


//function:Power
//parameters:short Number,short NumberPow
//return : this function is Pow of Number
short Power(short Number, short NubmerPow) {
	if (NubmerPow == 0)
		//any number powered to zero gives 1
		return 1;

	
	short sum = 1;
	for (int i = 1; i <= NubmerPow; i++) {
		sum *=Number;
	}
	return sum;
}

//--------------------------------------------------------
//#33
//enum :enGrade
//parameters:A,B,C,D,E,F
//return :this is value are Grade
enum enGrade{A=90,B=80,C=70,D=60,E=50,F=0};


//function:PrintGrade
//Parameters:enGrade Grade
//return : this is print Grade 
void PrintGrade(enGrade Grade) {
	switch (Grade) {
	case enGrade::A:
	{
		cout << "A";
		break;
	}
	case enGrade::B:
	{
		cout << "B";
		break;
	}
	case enGrade::C:
	{
		cout << "C";
		break;
	}
	
	case enGrade::D:
	{
		cout << "D";
		break;
	}
	case enGrade::E:
	{
		cout << "E";
		break;
	}
	case enGrade::F:
	{
		cout << "F";
		break;
	}
	}
}

//function Grade
//parameters:short Grade
//return:this is give you the Grade A or D or B....
enGrade Grade(short Grade) {
	if (Grade >= 90) {
		return enGrade::A;
	}
	else if (Grade >= 80) {
		return enGrade::B;
	}
	else if (Grade >= 70) {
		return enGrade::C;
	}
	else if (Grade >= 60) {
		return enGrade::D;
	}
	else if (Grade >= 50) {
		return enGrade::E;
	}
	else
	{
		return enGrade::F;
	}
}


//function:ReadNumberInRange
//Parameters:string Massage , short From ,short to 
//return :This function displays a message to the user and takes values ​​from him within a specified range.
short ReadNumberInRange(string Massage, short From, short to) {
	short number;
	do
	{
		cout << Massage;
		cin >> number;

	} while (number>From||number<to);
	return number;
}

//--------------------------------------------------------
//#34

enum enPercentage { OnePercent = 1, TwoPercent = 2, TreePercent = 3, FivePercent = 5, ZeroPercent = 0 };

enPercentage enEmploysPercentage(int TatalSales) {
	if (TatalSales >= 1000000) 
	{
		return enPercentage::OnePercent;
	}
	else if (TatalSales >= 500000)
	{
		return enPercentage::TwoPercent;
	}
	else if(TatalSales>=100000)
	{
		return enPercentage::TreePercent;
	}
	else if (TatalSales >= 50000) 
	{
		return enPercentage::FivePercent; 
	}
	else
	{
		return enPercentage::ZeroPercent;
	}
}

float EmployeePercentage(int TatalSales) {
	switch (enEmploysPercentage(TatalSales)) {
	case enPercentage::OnePercent: {
		return  0.1;
	}
	case enPercentage::TwoPercent: {
		return 0.2;
	}
	case enPercentage::TreePercent: {
		return 0.3;
	}
	case enPercentage::FivePercent: {
		return 0.5;
	}
	case enPercentage::ZeroPercent: {
		return 0;
	}
	}
}

float EmployeeCommission(int TatalSales) {
	return EmployeePercentage(TatalSales) * TatalSales;
}


//--------------------------------------------------------
//#35
//this is my answer
// {
float Multiply(float num1, float num2) {
	return num1 * num2;
}

float CalculateTotalPennies(float Penny, float Nicke, float Dime, float Quarte, float Dollar)
{
	    float SumPenny = 0;

	    SumPenny += Penny;
		SumPenny += Multiply(Nicke, 5);
		SumPenny += Multiply(Dime, 10);
		SumPenny += Multiply(Quarte, 25);
		SumPenny += Multiply(Dollar, 100);
		return SumPenny;
}

float ConvertPenniesToDollars(float Pennys) {
	return Pennys / 100;
}
//}
//this is Ms.mohammed's answer


// Struct: stPiggyBankContent
// Purpose: Represents the different types of coins and dollar bills in the piggy bank.
struct stPiggyBankContent
{
	int Pennies, Nickels, Dimes, Quarters, Dollars;
};


// Function: ReadPiggyBankContent
// Purpose: Prompts the user to enter the number of different coins and dollar bills in the piggy bank.
// Returns: A struct containing the number of each type of coin/bill.
stPiggyBankContent ReadPiggyBankContent()
{
	stPiggyBankContent PiggyBankContent;  // Variable to store the piggy bank content.

	// Prompt the user to enter the quantity of each type of coin and dollar bill.
	cout << "Please enter the total number of Pennies: " << endl;
	cin >> PiggyBankContent.Pennies;
	cout << "Please enter the total number of Nickels: " << endl;
	cin >> PiggyBankContent.Nickels;
	cout << "Please enter the total number of Dimes: " << endl;
	cin >> PiggyBankContent.Dimes;
	cout << "Please enter the total number of Quarters: " << endl;
	cin >> PiggyBankContent.Quarters;
	cout << "Please enter the total number of Dollar bills: " << endl;
	cin >> PiggyBankContent.Dollars;

	return PiggyBankContent;  // Return the filled struct.
}

// Function: CalculateTotalPennies
// Purpose: Converts all coins and dollar bills in the piggy bank to the equivalent value in pennies.
// Parameter:
//   - PiggyBankContent: A struct containing the number of each type of coin/bill.
// Returns: The total value in pennies.
int CalculateTotalPennies(stPiggyBankContent PiggyBankContent)
{
	// Compute total pennies by converting each coin type to its equivalent in pennies.
	int TotalPennies = PiggyBankContent.Pennies * 1
		+ PiggyBankContent.Nickels * 5
		+ PiggyBankContent.Dimes * 10
		+ PiggyBankContent.Quarters * 25
		+ PiggyBankContent.Dollars * 100;

	return TotalPennies;  // Return the total value in pennies.
}



//--------------------------------------------------------
//#36
enum enOperationYpe{Add='+',Subtract='-',Mult };

float Calculater(char OperationType, float Number1, float Number2) {

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

	//this code calculate rctangl area by diagonal and Side 
	/*
	PrintNumber( "the calculat rctangl area by Diagonal and Side:",CaluculateRectangleAreaByDiagonalAndSideArea(5, 40));
	*/
	 
	//this code calculate triangle area by Height and Base
	/*
	PrintNumber("the calculat triangle area is :", CaluculaterTriangleArea(10, 8));
	*/

	//this code calculate circle area by Radius
	/*
	PrintNumber("the calculat circle area is :", CalculateCircleArea(5));
	*/


    //this code calculate circle area by Diameter
    /*
     PrintNumber("the calculat circle area by Diameter is :", CalculateCircleByDiameter(10));
    */

    //this code calculate circle insid squar area
    /*
    PrintNumber("the calculat circle insid squar area is :", CalculateCircleInsidSequare(10));
	*/

    //this code calculate circle area by Circumference
	/*
	PrintNumber("the calculat circle area by Circumference is :", CalculateCircleByCircumference(20));
	*/
	
	//this code calculate circle area by Isosceles Triangle
    /*
    PrintNumber("the calculat circle area by Isosceles Triangle is :", CalculateCircleByIsoscelesTriangle(20, 10));
	*/

	//this code calculate circle area by Arbitrary Triangle
    /*
    PrintNumber("the calculat circle area by Arbitrary Triangle is :", CalculateCircleAreaByArbitraryTriangle(5, 6, 7));
    */


	//this code validate number in range
    /*
    short number = ReadNumber("enter the number ?");
    if (ValidateNumberInRange(number, 10, 20))
    PrintNumber("", number);
	*/

	//this code read number in range
	/*
	short numberInRange = readNumberInLoop("enter the number between 10 and 20 ?", 10, 20);
	PrintNumber("the number in range is :", numberInRange);
	*/
     
	/*
    short Number = ReadNumber("enter the number ?");//this code read number in range
    PrintRangeFrom1toN(Number);//this code print range from 1 to N
	cout << "--------------------------------------" << endl;//فاصل بين الطباعة
	PrintRangeFromNto1(Number);//this code print range from N to 1
	*/
    



	/*
    short Number = ReadNumber("enter the number ?");//this code read number in range
    PrintNumber("the sum Odd Number is N to 0:",SumOddNumbersFrom1ToN(Number));
    */

    /*
	short Number = ReadNumber("enter the number ?");//this code read number in range
	PrintNumber("the sum Even Number is N to 0:", SumEvenNumbersFrom1ToN(Number));
	*/


     /*
     PrintNumber("the sum Even Number is N to 0:", FactorialOfNumber(ReadPositiveNumber("enter the number ?")));
     */



     /*
     PrintNumber("the Pow is number 2:",Power(ReadPositiveNumber("enther the number is Positive:"), ReadPositiveNumber("enter the Power:")));
     */


     //هذا الكود ياخذ الدرجه بين 0 الى 100 ويعطي المستخدم تقييم الدرجة 
	 /*
     short grade = ReadNumberInRange("enter a grade between 0 and 100 :",0,100);
     PrintNumber("the Grade is :");
     PrintGrade(Grade(grade));
	 */
	 

     /*
     int ToataSalary=ReadNumber("enter the Total Salary:");//قرائة اجمالي المبيعات للموظف
	 PrintNumber("The Percantage is :", EmployeePercentage(ToataSalary));//طباعة نسبة العموله للموظف
     PrintNumber("The Commission is :", EmployeeCommission(ToataSalary));//طباعة العموله للموضف بحسب اجمالي المبيعات التي ادخلت 
	 */

     /*
     float Pennies=CalculateTotalPennies(ReadPositiveNumber("how mach you have from the Pennies : "),
		 ReadPositiveNumber("how mach you have from the Nickels : "), 
		 ReadPositiveNumber("how mach you have from the Dimes : "), 
		 ReadPositiveNumber("how mach you have from the Quarters : "),
		 ReadPositiveNumber("how mach you have from the Dollars : "));//It takes all the denominations you collected in your piggy bank and gives you how many pennies they are worth.
	 //يأخذ التطبيق جميع الفئات النقدية التي جمعتها في حصالتك ويعطيك قيمة كل منها بالبنسات.

	 PrintNumber("the Pennies is : ", Pennies);
	 PrintNumber("the Dollars is : ", ConvertPenniesToDollars(Pennies));
    
	 //this is Ms.Mohammed's answer 
	 
	 // Read the piggy bank content and calculate the total value in pennies.
	 int TotalPennies = CalculateTotalPennies(ReadPiggyBankContent());

	 // Display the total amount in pennies.
	 cout << endl << "Total Pennies = " << TotalPennies << endl;

	 // Display the total amount in dollars by converting pennies to dollars.
	 cout << endl << "Total Dollars = $" << (float)TotalPennies / 100 << endl;
	 
	 */

	return 0;

}
