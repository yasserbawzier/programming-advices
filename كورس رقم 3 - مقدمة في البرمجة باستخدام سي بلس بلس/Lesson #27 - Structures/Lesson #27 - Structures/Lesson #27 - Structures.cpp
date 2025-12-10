
#include <iostream>
using namespace std;

struct AddressInfo{

    string Country;
    string City;
    string Street;
};
struct ContactInfo
{
    string Email;
    string Phone;
    string Fesbook;
};
struct CompanyInfo{
    string CompanyName;
    double Monthly_Salary;
    double Yearly_Salary() {
        return Monthly_Salary * 12;}
};
struct PersonInfo {
    string Name;
    int Age;
    bool IsMarried;
    char Gender;
    ContactInfo Contact;
    AddressInfo Address;
    CompanyInfo Company;
};
void PrintUserDataInMonter(PersonInfo Person) {
    //the function to print the user data 
    cout << "******************************\n";
    cout << "Person Information:\n";
    cout << "Name:" << Person.Name << "\n";
    cout << "Age :" << Person.Age << "Years.\n";
    cout << "Gender: " << Person.Gender << "\n";
    cout << "Married : " << Person.IsMarried << "\n\n";

	cout << "Address Information:\n";
    cout << "City:" << Person.Address.City << "\n";
    cout << "Country:" << Person.Address.Country << "\n";
    cout << "Street:" << Person.Address.Street << "\n\n";
    
	cout << "Company Information:\n";
    cout << "Company Name :" << Person.Company.CompanyName << "\n";
    cout << "Monthly Salary :" << Person.Company.Monthly_Salary << "\n";
    cout << "Yearly Salary: " << Person.Company.Yearly_Salary() << endl << endl;
   
    cout << "Contact Information:\n";
	cout << "Email :" << Person.Contact.Email << "\n";
	cout << "Phone :" << Person.Contact.Phone << "\n";
    cout << "Fesbook :" << Person.Contact.Fesbook << "\n";
    cout << "******************************\n";
}
int main()
{
    PersonInfo Person1;

       Person1.Name = "Ahmed";
	   Person1.Age = 25;
       Person1.IsMarried = true;
       Person1.Gender = 'M';

	   Person1.Address.City = "Monter";
	   Person1.Address.Country = "Mexico";
	   Person1.Address.Street = "Street 123";
       
	   Person1.Company.CompanyName = "Google";
	   Person1.Company.Monthly_Salary = 5000.50;
     

       Person1.Contact.Email = "yaseer.bawzier@gmail.com";
       Person1.Contact.Phone = "776813282";
       Person1.Contact.Fesbook = "yaseer";

       PrintUserDataInMonter(Person1);

}
