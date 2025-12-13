
//the Procedures it is does not return example : void
//the functions it is returns example : int , string ,char , float , double etc
#include <iostream>
#include <string>
using namespace std;
bool isAgeValid(short age)
{
	if (age >= 21)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool chisHave(char anser){

	if (anser == 'Y'||anser=='y')
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool canDrive(bool ageValid , bool haveLicense){
	
	return (ageValid && haveLicense);
}
int ingetInput(string Massege){
	int input;
	cout << Massege << endl;
	cin >> input;

	return input;
}
char chgetInput(string Massege) {
	char Input;
	cout << Massege << endl;
	cin >> Input;
	return Input;
}
bool ishaveRecommendation(char anser) {
	if (anser == 'Y' || anser == 'y')
	{
		return true;
	}
	else
	{
		return false;
	}
}
void PrintCanDrive(bool IsCan) {
	if (IsCan)
		cout << "you can drive\n";
	else
		cout << "you can not drive\n";
}
void SwapNamber(int& Numbe1, int& Numbe2) {
	int temp;
	temp = Numbe1;
	Numbe1 = Numbe2;
	Numbe2 = temp;
}
int secondsInHours(short hours) {
	return hours * 3600;
}
short secondsInMinutes(short minutes) {
	return minutes * 60;
}
int SecondsInDays(short days) {
		return days * 24 * 3600;

}
int TotalSecondsOfWork(short days, short hours, short minutes, short seconds) {
	return SecondsInDays(days) + secondsInHours(hours) + secondsInMinutes(minutes) + seconds;
}
int ConvertSecodsToDay(int Seconds) {
	return Seconds / (24 * 60 * 60);
}
int ConvertSecodsToHours(int Seconds) {
	return Seconds / (60*60);
}
int ConvertSecondsToMinuts(int Seconds) {
	return Seconds / 60;
}
void TotalSecondsOfDays_Hours_minutes(int seconds) {
	short days = ConvertSecodsToDay(seconds);
	seconds -= SecondsInDays(days);
	short Hours = ConvertSecodsToHours(seconds);
	seconds -= secondsInHours(Hours);
	short minuts = ConvertSecondsToMinuts(seconds);
	seconds -= secondsInMinutes(minuts);
	cout << days << ":" << Hours << ":" << minuts << ":" << seconds << endl;

}
int main()
{
	//this is the proplem hire a drive - case 1
    /*
	char ishaveLicens;
	short Age;

	Age=ingetInput("please enter the Age?");
	ishaveLicens = chgetInput("do you have a Licens?");
	PrintCanDrive(canDrive(chisHave(ishaveLicens), isAgeValid(Age)));
	*/


	//this is the proplem #5 - Hire a Driver Case 2
	/*
	char Recommendation;
	char ishaveLicens;
	short Age;

	Recommendation = chgetInput("do you have Recommendation?Y,N");
	if (ishaveRecommendation(Recommendation)) {
		cout << "you can Drive";
	}
	else
	{
		Age = ingetInput("please enter Age?");
		ishaveLicens = chgetInput("do you have a Licen ?Y,N");
		PrintCanDrive(canDrive(isAgeValid(Age), chisHave(ishaveLicens)));
	}
	*/
	
	//this is the proplem #14 - Swap Numbers
	/*int Number1, Number2;
	cout << "please enter Number 1:";
	cin >> Number1;
	cout << "please enter Number 2:";
	cin >> Number2;
	SwapNamber(Number1, Number2);
	cout << "Number 1 after swap is :" << Number1 << endl;
	cout << "Number 2 after swap is :" << Number2 << endl;
	*/

	//this is the proplem #42 - Task Duration in Seconds

	/*short days, hours, minutes, seconds;
	cout << "please enter days:";
	cin >> days;
	cout << "Please enter hours:";
	cin >> hours;
	cout << "please enter minutes:";
	cin >> minutes;
	cout << "please enter seconds:";
	cin >> seconds;
	system("cls");
	cout<<"the Total Seconds of Werk is :"<<TotalSecondsOfWork(days, hours, minutes, seconds);
	*/

	//this is Problem #43 - Seconds to days hours minutes seconds
	/*
	TotalSecondsOfDays_Hours_minutes(10000);
	*/
	
	return 0;


}
