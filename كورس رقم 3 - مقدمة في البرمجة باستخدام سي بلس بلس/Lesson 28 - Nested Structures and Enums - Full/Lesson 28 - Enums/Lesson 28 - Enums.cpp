
#include <iostream>
using namespace std;
enum enGender  { Male, Female };
enum  enStatus { Single, Marrid };
struct stAddressInfo {

    string Country;
    string City;
    string Street;
};
struct stContactInfo
{
    string Email;
    string Phone;
    string Fesbook;
};
struct stCompanyInfo {
    string CompanyName;
    double Monthly_Salary;
    double Yearly_Salary() {
        return Monthly_Salary * 12;
    }
};
struct stPersonInfo {
    string Name;
    int Age;
    enStatus IsMarried;
    enGender Gender;
    stContactInfo Contact;
    stAddressInfo Address;
    stCompanyInfo Company;
};
void PrintUserDataInMonter(stPersonInfo Person) {
    //the function to print the user data 
    cout << "******************************\n";
    cout << "Person Information:\n";
    cout << "Name:" << Person.Name << "\n";
    cout << "Age :" << Person.Age << "Years.\n";
    if (Person.Gender == enGender::Female)
        cout << "Gender: F\n";
    else
        cout << "Gender: M\n";
  
    if (Person.IsMarried == enStatus::Marrid)
        cout << "Gender: YES\n\n";
    else
        cout << "Gender: NO\n\n";



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
   stPersonInfo Person1;

    Person1.Name = "Ahmed";
    Person1.Age = 25;
    Person1.IsMarried = enStatus::Marrid;
    Person1.Gender = enGender::Male;

    Person1.Address.City = "Monter";
    Person1.Address.Country = "Mexico";
    Person1.Address.Street = "Street 123";

    Person1.Company.CompanyName = "Google";
    Person1.Company.Monthly_Salary = 5000.50;


    Person1.Contact.Email = "yaseer.bawzier@gmail.com";
    Person1.Contact.Phone = "776813282";
    Person1.Contact.Fesbook = "yaseer";

    PrintUserDataInMonter(Person1);

    return 0;
}
