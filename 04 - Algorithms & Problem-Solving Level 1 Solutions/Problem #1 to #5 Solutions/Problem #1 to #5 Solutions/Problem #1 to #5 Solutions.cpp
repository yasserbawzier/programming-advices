#include <iostream>   // Include iostream for input/output operations.
#include <string>     // Include string to work with std::string.

using namespace std;  // Use the standard namespace to avoid prefixing std:: to standard functions.

// Function: ReadName
// Purpose: Prompts the user to enter their name and reads it from the input.
// Returns: A string containing the user's entered name.
string ReadName()
{
    string Name;  // Declare a string variable to store the user's name.

    // Prompt the user to enter their name.
    cout << "Please enter your name? " << endl;
	  // Use getline to read the full name, including spaces.
    getline(cin, Name);

    return Name;  // Return the entered name.
}

// Function: PrintName
// Purpose: Displays the entered name with a formatted message.
// Parameter: Name - a string containing the name to be displayed.
void PrintName(string Name)
{
    // Print the user's name with a message, adding a newline for formatting.
    cout << "\nYour Name is: " << Name << endl;
}

// Enum: enNumberType
// Purpose: Defines two possible types of numbers: Odd (1) and Even (2).
enum enNumberType { Odd = 1, Even = 2 };

// Function: ReadNumber
// Purpose: Prompts the user to enter an integer and reads it from input.
// Returns: The entered integer value.
int ReadNumber()
{
    int Num;  // Variable to store the user's input.

    // Prompt the user to enter a number.
    cout << "Please enter a number? " << endl;

    cin >> Num;  // Read the number entered by the user.

    return Num;  // Return the entered number.
}

// Function: CheckNumberType
// Purpose: Determines whether a given number is even or odd.
// Parameter: Num - the integer number to be checked.
// Returns: enNumberType::Even if the number is even, enNumberType::Odd if the number is odd.
enNumberType CheckNumberType(int Num)
{
    int Result = Num % 2;  // Compute the remainder when dividing by 2.

    if (Result == 0)  // If remainder is 0, the number is even.
        return enNumberType::Even;
    else  // Otherwise, the number is odd.
        return enNumberType::Odd;
}

// Function: PrintNumberType
// Purpose: Displays whether the given number type is even or odd.
// Parameter: NumberType - the type of the number (Even or Odd).
void PrintNumberType(enNumberType NumberType)
{
    // Print whether the number is even or odd based on the given type.
    if (NumberType == enNumberType::Even)
        cout << "\n Number is Even. \n";
    else
        cout << "\n Number is Odd. \n";
}

// Struct: stInfo
// Purpose: Stores candidate information including age, driving license status, and recommendation status.
struct stInfo
{
    int Age;                  // Stores the candidate's age.
    bool HasDrivingLicense;   // Stores whether the candidate has a driving license (true/false).
    bool HasRecommendation;   // Stores whether the candidate has a recommendation (true/false).
};

// Function: ReadInfo
// Purpose: Prompts the user to enter their age, driving license status, and recommendation status.
// Returns: A struct containing the entered candidate information.
stInfo ReadInfo()
{
    stInfo Info;  // Declare a variable of type stInfo to store user input.

    // Prompt the user to enter their age and store it in the struct.
    cout << "Please Enter Your Age?" << endl;
    cin >> Info.Age;

    // Prompt the user to enter whether they have a driver's license (expects 1 for true, 0 for false).
    cout << "Do you have a driver’s license? (1 for Yes, 0 for No)" << endl;
    cin >> Info.HasDrivingLicense;

    // Prompt the user to enter whether they have a recommendation (expects 1 for true, 0 for false).
    cout << "Do you have a recommendation? (1 for Yes, 0 for No)" << endl;
    cin >> Info.HasRecommendation;

    return Info;  // Return the filled struct.
}

// Function: IsAccepted
// Purpose: Determines if the candidate is accepted based on age, license, and recommendation status.
// Parameter: Info - struct containing the candidate's details.
// Returns: true if the candidate meets the criteria, otherwise false.
bool IsAccepted(stInfo Info)
{
    // If the candidate has a recommendation, they are automatically accepted.
    if (Info.HasRecommendation)
    {
        return true;
    }
    else
    {
        // Otherwise, the candidate must be older than 21 and have a driving license.
        return (Info.Age > 21 && Info.HasDrivingLicense);
    }
}

// Function: PrintResult
// Purpose: Prints whether the candidate is hired or rejected based on eligibility.
// Parameter: Info - struct containing the candidate's details.
void PrintResult(stInfo Info)
{
    // Check eligibility using IsAccepted function and print the corresponding message.
    if (IsAccepted(Info))
        cout << "\n Hired" << endl;
    else
        cout << "\n Rejected" << endl;
}
// Main function: Program entry point.
int main()
{
    // Call ReadName to get the user's input and pass it to PrintName for display.
  //  PrintName(ReadName());


    // Read a number from the user, determine its type, and print the result.
  //  PrintNumberType(CheckNumberType(ReadNumber()));


    // Read candidate information, check eligibility, and print the result.
    PrintResult(ReadInfo());

    return 0;  // Return 0 to indicate successful execution.
}
