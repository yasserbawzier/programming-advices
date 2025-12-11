
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
bool canDrive(bool ageValid , bool haveLicense,bool IsHaveRecommendation=false){
	
	return ((ageValid && haveLicense) || IsHaveRecommendation);
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
void PrintCanDrive(bool IsCan) {
	if (IsCan)
		cout << "you can drive\n";
	else
		cout << "you can not drive\n";
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
	if (canDrive(0, 0, chisHave(Recommendation))) {
		cout << "you can Drive";
	}
	else
	{
		Age = ingetInput("please enter Age?");
		ishaveLicens = chgetInput("do you have a Licen ?Y,N");
		PrintCanDrive(canDrive(isAgeValid(Age), chisHave(ishaveLicens)));
	}
	*/


}
