
#include <iostream>
#include<string>
using namespace std;
//my answer Problem 1/2 {

//function:Heder
//Purpose:يقوم بطباعة راس جدول الضرب 
//                Multipliaction Table From 1 to 10
// 
//       1       2       3       4       5       6       7       8       9       10
//---------------------------------------------------------------------------------- 
void Heder() {
    cout << "\t\t\tMultipliaction Table From 1 to 10\n\n";
    cout << "\t1\t2\t3\t4\t5\t6\t7\t8\t9\t10\n";
    cout << "-----------------------------------------------------------------------------------\n";
}
//function:speas
//Purpose:
string speas(short number) {
    if (to_string(number).length() > 1) {
        return "  |";
    }
    else
        return "   |";
}
//function:Multipliaction
//Purpose:يعطيك جدول الضرب على شكل مربع 
//1  |  1   2   3   4   5   6   7   8   9   10
//2  |  2   4   6   8   10  12  14  16  18  20
//وهاكذا جميع الارقام الى 10
void PrintMultipliaction() {
    Heder();
    for (short i = 1; i <= 10; i++) {
        cout << i << speas(i);
        for (short j = 1; j <= 10; j++) {
            cout << "\t" << i * j;
        }
        cout << "\n";
    }
}
//}


//Answer's Ms.Moahmmed Problem 1/2 {

// Function: PrintTableHeader
// Purpose: Prints the header of the multiplication table, including the title and column labels.
void PrintTableHeader()
{
    // Print the title of the table with some formatting (new lines and tab spaces)
    cout << "\n\n\t\t\t Multiplication Table From 1 to 10\n\n";

    // Print a tab to align the column headers correctly
    cout << "\t";

    // Loop from 1 to 10 to print the column numbers for the header
    for (int i = 1; i <= 10; i++)
    {
        // Print the current number followed by a tab for spacing
        cout << i << "\t";
    }

    // Print a separator line to visually divide the header from the rest of the table
    cout << "\n___________________________________________________________________________________\n";
}
// Function: ColumSperator
// Purpose: Returns a string that acts as a separator between the row number and the multiplication values.
//          The spacing is adjusted based on whether the row number is a single-digit (less than 10) or not.
string ColumSperator(int i)
{
    // If the row number is less than 10, return a separator with three spaces before the pipe symbol
    if (i < 10)
        return "   |";
    else
        // For numbers 10 or greater, return a separator with two spaces before the pipe symbol
        return "  |";
}
// Function: PrintMultiplicationTable
// Purpose: Combines the header and the multiplication logic to print the full multiplication table.
void PrintMultiplicationTable()
{
    // First, print the header with the title and column numbers
    PrintTableHeader();

    // Loop through the rows of the multiplication table (from 1 to 10)
    for (int i = 1; i <= 10; i++)
    {
        // Print the row number, then a formatted column separator, and a tab for spacing
        cout << " " << i << ColumSperator(i) << "\t";

        // Inner loop to calculate and print the product for each column (from 1 to 10)
        for (int j = 1; j <= 10; j++)
        {
            // Calculate the product of the current row and column, then print it with a tab for spacing
            cout << i * j << "\t";
        }
        // After finishing one row, move to the next line
        cout << endl;
    }
}
//}


//My Answer Problem 2/2 {

// هذا الحل من المشكلة رقم 
//#38 في المستوى الاول من حل المشاكل 
//يتم اعطائك هل الرقم برايم نمبر او لا البرايم نمبر هو الرقم الذي لا يقبل القسمة إلا على نفسة او واحد
// enum :enPrimNumber
// Purpose: 
enum enPrimNumber { Prim = 1, notPrime = 0 };//حذفت الأي من برايم لانه في انم حل الاستاذ وتعارضت مسميات الانم
//Fanction:enCheckPrime
//Purpose:يتأكد لك هل الرقم برايم نمبر ام لا ويعطيك القيمة من نوع 
//enPrimNumber
enPrimNumber enCheckPrime(short number) {
    short num = round(number / 2);
    for (short Count = 2; Count <= num; Count++) {
        if (number % Count == 0)
            return enPrimNumber::notPrime;
    }
    return enPrimNumber::Prim;
}
//هذا حل المشكلة رقم 
//#14
//proseager:Swab
//Parameters:float num1,float num2
//Return: This is the code that can be used to switch between two numbers
void SwabNumber(short& num1, short& num2) {
    short swithc = num1;
    num1 = num2;
    num2 = swithc;


}
//Proseager:PrintPrimNumberFormTo
//Parameters:short From , short To
//Purpose:هذا البروسيجر يطبع لك الارقام البرايم من الرقم الذي تختارة الى الرقم الذي تختارة
void PrintPrimNumber(short From, short to) {
    if (From > to) {

        SwabNumber(From, to);
    }
    for (float i = From; i <= to; i++) {
        if (enCheckPrime(i) == enPrimNumber::Prim) {
            cout << i << " ";
        }
    }
}
//}


//Answer's Ms.Moahmmed Problem 1/2 {


// Define an enumeration to represent whether a number is prime or not.
// enPrimNotPrime::Prime has a value of 1 and enPrimNotPrime::NotPrime has a value of 2.
enum enPrimNotPrime { Prime = 1, NotPrime = 2 };

// Function: ReadPositiveNumber
// Purpose: Prompts the user with a message to enter a positive number.
//          It keeps asking until the user provides a number greater than 0.
int ReadPositiveNumber(string Message)
{
    int Number = 0;  // Variable to store the user's input, initialized to 0.
    do
    {
        // Display the prompt message to the user.
        cout << Message << endl;
        // Read the number entered by the user.
        cin >> Number;
    } while (Number <= 0);  // Continue prompting if the number is not positive.

    return Number;  // Return the valid positive number.
}

// Function: CheckPrime
// Purpose: Checks if a given number is prime.
// It does this by trying to divide the number by all integers from 2 up to half of the number.
enPrimNotPrime CheckPrime(int Number)
{
    // Calculate half of the number. 
    // The use of round() here ensures we work with an approximate half even though integer division could be used.
    int M = round(Number / 2);

    // Loop from 2 to M to check if any number divides Number evenly.
    for (int Counter = 2; Counter <= M; Counter++)
    {
        // If Number is divisible by Counter (remainder is 0), then it is not prime.
        if (Number % Counter == 0)
            return enPrimNotPrime::NotPrime;  // Return NotPrime if a divisor is found.
    }

    // If no divisors were found, the number is prime.
    return enPrimNotPrime::Prime;
}

// Function: PrintPrimeNumbersFrom1ToN
// Purpose: Prints all the prime numbers from 1 up to a given number.
// It first displays a header message and then checks each number in the range.
void PrintPrimeNumbersFrom1ToN(int Number)
{
    cout << "\n";  // Print a newline for better formatting.
    // Display a header indicating the range being considered.
    cout << "Prime Numbers from " << 1 << " To " << Number;
    cout << " are : " << endl;

    // Loop through all numbers from 1 to Number.
    for (int i = 1; i <= Number; i++)
    {
        // Use the CheckPrime function to determine if the current number i is prime.
        if (CheckPrime(i) == enPrimNotPrime::Prime)
        {
            // If i is prime, print it on a new line.
            cout << i << endl;
        }
    }
}
//}

//-------------------------------------------------
//Problem 3 / 2

//My Answer {

enum enPerfectNotPerfect { Perfect = 1, NotPerfect = 0 };
//فنكشن يقوم بفحص الرقم هل هو بيرفكت نمبر ام لا
//كيف تعرف ان هذا الرقم بيرفكت 
//تبدا من الواحد وتقسمه على الرقم ان كان الباقي صفر تجمعه مع الارقام التي ان قسمت على الرقم تساوي صفر 
//مثال الرقم 6
//6/1=6
//6/2=3
//6/3=2
//6/4=1.5
//6/5=1.2
//الناتج سيتم جمع الارقام التي قسمتها على سته عدد صحيح 1+2+3 تساوي 6 اذا 6 بيرفكت نمبر
enPerfectNotPerfect enCheckPerfect(short number) {
    short sum = 0;
    short num = number / 2;
    for (short i = num; i >= 1; i--) {
        if (number % i == 0) {
            sum += i;
        }
    }
    if (sum == number)
        return enPerfectNotPerfect::Perfect;
    else
        return enPerfectNotPerfect::NotPerfect;
}
//This procedure prints whether the number is perfect or not
void PrintIsPerfectNumber(short number) {

    if (enCheckPerfect(number) == enPerfectNotPerfect::Perfect)
        cout << "is Perfect";
    else
        cout << "is not Perfect";
}


//}

//Answer's Ms.Moahmmed Problem 3/2 {


// Function: isPerfectNumber
// Purpose: Determines if a given number is a perfect number.
// A perfect number is defined as a number that is equal to the sum of its proper divisors (excluding itself).
// Parameters: Number - the integer to check for perfection.
// Returns: true if the number is perfect; false otherwise.
bool isPerfectNumber(int Number)
{
    int Sum = 0; // Initialize the sum of divisors to 0.

    // Loop from 1 to Number - 1 to find all proper divisors.
    for (int i = 1; i < Number; i++)
    {
        // If i divides Number evenly, it is a divisor.
        if (Number % i == 0)
            Sum += i; // Add the divisor to the sum.
    }

    // Compare the sum of divisors to the original number.
    // Return true if they are equal (the number is perfect), or false if they are not.
    return Number == Sum;
}

// Function: PrintResults
// Purpose: Prints whether the provided number is a perfect number.
// Parameters: Number - the integer to check and display the result for.
void PrintResults(int Number)
{
    // Check if the number is perfect using the isPerfectNumber function.
    if (isPerfectNumber(Number))
        cout << Number << " Is Perfect Number.\n";  // If true, print that the number is perfect.
    else
        cout << Number << " Is NOT Perfect Number.\n"; // Otherwise, print that it is not perfect.
}


//-------------------------------------------------
//Problem 4 / 2
//بروسيجر يقوم بطباعة الارقام البيرفكت فقط 
void PrintPerfectNumber(short From, short to) {
    if (From > to) {

        SwabNumber(From, to);
    }
    for (float i = From; i <= to; i++) {
        if (enCheckPerfect(i) == enPerfectNotPerfect::Perfect) {
            cout << i << " ";
        }
    }
}


// Function: PrintPerfectNumbersFrom1ToN
// Purpose: Prints all perfect numbers between 1 and a given upper limit (inclusive).
// Parameter: Number - the upper limit for checking perfect numbers.
void PrintPerfectNumbersFrom1ToN(int Number)
{
    // Loop through each number from 1 to the given upper limit.
    for (int i = 1; i <= Number; i++)
    {
        // Check if the current number is a perfect number.
        if (isPerfectNumber(i))
        {
            // If it is perfect, output the number.
            cout << i << endl;
        }
    }
}


//-------------------------------------------------
//Problem 5 / 2

short lastNumber(short number) {
    return number % 10;
}
void Print(short number) {

    do
    {
        cout << lastNumber(number) << "\n";
        number = number / 10;

    } while (number != 0);
}
int main()
{
    //-------------------------------------------------
   //Problem 1/2
    //PrintMultiplicationTable();

    //-------------------------------------------------
    //Problem 2/2
     //PrintPrimNumber(1,50);
     //PrintPrimeNumbersFrom1ToN(10);//Answer's Mohammed 

     //-------------------------------------------------
    //Problem 3/2
    //PrintIsPerfectNumber(12);
    // Prompt the user to enter a positive number and then display whether it's a perfect number.
    //PrintResults(ReadPositiveNumber("Please enter a positive number?"));//Answer's Mohammed 


    //-------------------------------------------------
    //Problem 4 / 2
    //PrintPerfectNumber(1, 500);
    // Call ReadPositiveNumber with a prompt message to obtain a positive number from the user.
    // Then pass that number to PrintPerfectNumbersFrom1ToN to print all perfect numbers within the range.
    //PrintPerfectNumbersFrom1ToN(ReadPositiveNumber("Please enter a positive number?"));



    Print(1234);
}
