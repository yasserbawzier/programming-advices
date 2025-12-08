#include<iostream>
using namespace std;
const int Year = 12;
void PrintUserDataInMonter(string Name, short Age, string City ,string Country,float Monthly_Salary,int Yearly_Salary
,char Gender,bool isMarrid) {
	//the function to print the user data 
	cout << "******************************\n";
	cout << "Name:" << Name << "\n";
	cout << "Age :" << Age << "Years.\n";
	cout << "City:" << City << "\n";
	cout << "Country:" << Country << "\n";
	cout << "Monthly Salary :" << Monthly_Salary << "\n";
	cout << "Yearly Salary: " << Yearly_Salary << endl;
	cout << "Gender: " << Gender << "\n";
	cout << "Married : " << isMarrid << "\n";
	cout << "******************************\n";
}
int GetYearlySalary(float Monthly_Salary){
	//the function to calculate the yearly salary from the monthly salary 
	return Monthly_Salary * Year;
}
short GetUserNumber(string Masseg) {
	//the function to get the user any Number but type is short 
	short Number;
	cout << Masseg<<"\n";
	cin >> Number;
	return Number;
}
char GetUserChar(string Masseg) {
		//the function to get the user any Character
	char Character;
	cout << Masseg << "\n";
	cin >> Character;
	return Character;

}
string GetUserString(string Masseg) {
	//the functin to get the user any String
	string Text;
	cout << Masseg << "\n";
	cin >> Text;
	return Text;
}

int main() {
	//If you want to create any variables, you must name them with names that explain their function
	//إذا كنت تريد إنشاء أي متغيرات، يجب عليك تسميتها بأسماء تشرح وظيفتها
	
	string Name, City, Country;
	short Age ;
	float Monthly_Salary;
	int Yearly_Salary ;
	char Gender ;
	bool isMarrid ;

	Name=GetUserString("Enter the your Name ?");
	City = GetUserString("Enter the your City ?");
	Country = GetUserString("Enter the your Country ?");
	Age = GetUserNumber("How old are you ?");
	Monthly_Salary = GetUserNumber("How mush your Salary Month ?");
	Yearly_Salary=GetYearlySalary(Monthly_Salary);
	Gender = GetUserChar("Choose your gender?M/F");
	isMarrid = GetUserNumber("do you Marrid?(1=Marrid)or(0=Not Marrid)");
	system("cls");
	PrintUserDataInMonter(Name,Age,City,Country,Monthly_Salary,Yearly_Salary,Gender,isMarrid);


}