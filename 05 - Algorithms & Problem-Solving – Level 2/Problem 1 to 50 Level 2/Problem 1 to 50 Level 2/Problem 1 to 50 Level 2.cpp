
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

//Answer's Ms.Moahmmed Problem 4/2 {

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
//}

//-------------------------------------------------
//Problem 5 / 2
//{

short lastNumber(int number) {
    return number % 10;
}
void PrintNumbers(short number) {

    do
    {
        cout << lastNumber(number) << "\n";
        number = number / 10;

    } while (number != 0);
}
//}
//Answer's Ms.Moahmmed Problem 5/2 {

// Function: PrintDigits
// Purpose: Prints the digits of a given number in reverse order, one digit per line.
//          It extracts each digit from the number using the modulo operator and then reduces the number.
// Parameter: Number - the positive integer whose digits are to be printed.
void PrintDigits(int Number)
{
    int Sum = 0, Remainder = 0; // Initialize variables. Although 'Sum' is declared, it is not used in this function.

    // Continue looping while there are digits left in Number.
    while (Number > 0)
    {
        Remainder = Number % 10; // Extract the last digit of Number.
        Number = Number / 10;    // Remove the last digit from Number.
        cout << Remainder << endl;  // Print the extracted digit on a new line.
    }
}

//}

//-------------------------------------------------
//Problem 6 / 2
//{
//يجمع ارقام الرقم مثال لو ادخلت 1234 يقوم بجمع 1+2+3+4 يساوي 10 
short SumOfDigits(short number) {
    short Sum = 0;
    while (number != 0)
    {
        Sum += lastNumber(number);
        number = number / 10;

    } 
    return Sum;
}
//}




//-------------------------------------------------
//Problem 7 / 2
//{
//يعكس الرقم مثلا لو ادخلت 147 يقوم بعكسيه واعطائة لك 741
int ReverseNumber(int number) {
    int swap = 0;
    while (number != 0)
    {
        swap *= 10;
        swap += lastNumber(number);
        number = number / 10;

    } 
    return swap;
}
//}

//-------------------------------------------------
//Problem 8 / 2
//{

//في هذا الفنكشن يقوم بعد كم مره تم تكرار الرقم الذي يحدده المستخدم 
// مثلا لو ادخل 122322 وادخل 2 يعطيه 4 وهي عدد المرات التي تكرر فيها الرقم 2
short Frequency(double number, short digit) {
    short Digit = 0;
    short sum = 0;
    while (number != 0)
    {
        Digit= lastNumber(number);
        if (digit == Digit) {
            sum = sum + 1;;
        }
      
        number = number / 10;

    }
    return sum;
}
//}

//-------------------------------------------------
//Problem 9 / 2
//{
//هذا الفنكشن يقوم بحذف الرقم الذي يحدده العميل من الرقم المدخل 
//مثلا ادخل رقم 12428512 وادخل دجت 2 الناتج 15841المهم انه سحذف الدجت ويعطيك الرقم بالمعكوس من غير الدجت المحدد
int deleteDigit( int number,short digit) {
    
    double number2=0;
    short num;
    while (number != 0)
    {
        num=lastNumber(number);
        
        if ( num!= digit)
        {
            number2 = (number2*10)+num;

        }
        number = number / 10;
        
    }
    return number2;
}
//هذا الروسيجر يعطيك كم مرة تكرر كل رقم مكون منه هذا الرقم 
// مثلا لو ادخلت 11244466 الناتج 
//Digit 6 Frequency is 2
//Digit 1 Frequency is 2
//Digit 4 Frequency is 3
//Digit 2 Frequency is 1
void HowOftenEachNumberIsRepeatd( int number) {
    short num ;
   
    while (number != 0) {
        num=lastNumber(number);
        cout << "Digit " << num << " Frequency is " << Frequency(number, num) << endl;
        number=deleteDigit(number,num);

   }
}




// Function: CountDigitFrequency
// Purpose: Counts how many times a specific digit appears in the given number.
//          The function extracts each digit from the number and increments the count when a match is found.
// Parameters:
//    DigitToCheck - the digit (as a short) to look for.
//    Number - the main number in which the frequency of the digit is to be counted.
// Returns: The frequency (count) of the specified digit in the number.
int CountDigitFrequency(short DigitToCheck, int Number)
{
    int Freq = 0;       // Initialize frequency counter to zero.
    int Remainder = 0;  // Variable to store the digit extracted from the number.

    // Process each digit until the number becomes 0.
    while (Number > 0)
    {
        Remainder = Number % 10;  // Extract the last digit from the number.
        Number = Number / 10;     // Remove the last digit from the number.

        // If the extracted digit matches the digit we're checking, increment the frequency counter.
        if (DigitToCheck == Remainder)
        {
            Freq++;
        }
    }
    return Freq;  // Return the total count of the specified digit.
}

// Function: PrintAllDigitsFrequencey
// Purpose: Prints the frequency of each digit (0-9) present in the given number.
// Parameter: Number - the number for which digit frequencies are to be printed.
void PrintAllDigitsFrequencey(int Number)
{
    cout << endl;  // Print an empty line for formatting.

    // Loop through all digits from 0 to 9.
    for (int i = 0; i < 10; i++)
    {
        short DigitFrequency = 0;                         // Variable to hold frequency for the current digit.
        DigitFrequency = CountDigitFrequency(i, Number);    // Get the frequency of digit 'i' in the number.

        // Only print the result if the digit appears at least once.
        if (DigitFrequency > 0)
        {
            cout << "Digit " << i << " Frequencey is "  // Print the digit and its frequency.
                << DigitFrequency << " Time(s).\n";
        }
    }
}
//}



//-------------------------------------------------
//Problem 10 / 2
//{
//الحل موجود في المين 
//}

//-------------------------------------------------
//Problem 11 / 2
//{
//هذا بيتأكد ان الرقم بالندر نمبر او لا 
//البالندرم نمبر هو الرقم الذي تقراء من اليمن إلى اليسار ومن اليسار الى اليمن نفس الرقم 
bool IsPalindromeNumber(int number) {
    int number2 = ReverseNumber(number);
    if (number2 == number)
        return true;
    else
        return false;
}

//-------------------------------------------------
//Problem 12 / 2
//{
//مثلا لو ادخلت 5
//هاكذا ستكون النتيجه 
//55555
//4444
//333
//22
//1
void PrintInvertedPatternNumber(short number) {
    for (short i = number; i > 0; i--) {
        for (short j = 1; j <= i; j++) {
            cout << i  ;
        }
        cout << "\n";
    }
}


//-------------------------------------------------
//Problem 13 / 2
//{
//مثلا لو ادخلت 5
//هاكذا ستكون النتيجه 
//1
//22
//333
//4444
//55555
void PrintNumberPattern(short number) {
    for (short i = 1; i <= number; i++) {
        for (short j = 1; j <= i; j++) {
            cout << i;
        }
        cout << "\n";
    }
}


//-------------------------------------------------
//Problem 14 / 2


//{
//مثلا لو ادخلت 5
//هاكذا ستكون النتيجه 
//EEEEE
//DDDD
//CCC
//BB
//A
void PrintLetterPattern(short number) {
    
    for (short i = number; i >= 1; i--) {
        for (short j = 1; j <= i; j++) {
            char leter = 64 + i;
            
            cout << leter;
        }
        cout << "\n";
    }
}

//Answer's Ms.Moahmmed Problem 14/2 {
// Function: PrintInvertedLetterPattern
// Purpose: Prints an inverted letter pattern using uppercase letters.
//          The pattern starts with the letter corresponding to ASCII code (65 + Number - 1)
//          and decrements down to 'A' (ASCII 65). In each row, the letter is printed
//          a decreasing number of times, starting from 'Number' times on the first row,
//          down to 1 time on the last row.
// Parameter: Number - the positive integer that determines the height of the pattern
//                     and the number of times the first (highest) letter is printed.
void PrintInvertedLetterPattern(int Number)
{
    cout << "\n";  // Print an empty line for formatting.

    // Outer loop: 'i' represents the ASCII code for the current letter.
    // It starts at (65 + Number - 1) which is the highest letter to be printed,
    // and decrements down to 65 ('A').
    for (int i = 65 + Number - 1; i >= 65; i--)
    {
        // Calculate the number of times to print the current letter.
        // When i = 65 + Number - 1, (65 + Number - 1 - i) equals 0,
        // so the inner loop runs 'Number' times.
        // For each subsequent row, this value increases, reducing the count by 1 each time.
        for (int j = 1; j <= Number - ((65 + Number - 1) - i); j++)
        {
            cout << char(i);  // Print the current letter (converted from its ASCII code).
        }

        cout << "\n";  // After printing the current row, move to the next line.
    }
}

//}


//-------------------------------------------------
//Problem 15 / 2


//{
//مثلا لو ادخلت 5
//هاكذا ستكون النتيجه 
//A
//BB
//CCC
//DDDD
//EEEEE
void PrintLettersAscending(short number) {
    for (short i = 65; i <= 64+number; i++) {
        for (short j = 65; j <= i; j++) {
            cout << (char)i;
        }
        cout << "\n";
    }
}

//}


//-------------------------------------------------
//Problem 16 / 2
//{
//طباعة احتمالات 3 احرف من جميع احرف اللغة الانجليزيزة 
void PrintAllPossibleCharacters() {
    for (short i = 65; i <= 90; i++) {
        for (short u = 65; u <= 90; u++) {
            for (short j = 65; j <= 90; j++) {
                cout << (char)i << (char)u << (char)j;
                cout << "\n";
            }
        }
        cout << "\n***************************************\n";
    }
}
//}



//-------------------------------------------------
//Problem 17 / 2
//{
//هذا يقوم بادخال جميع حالات الأحرف الانجليزية حتى يصل الى الحالة المدخله له 
//الحالات مكونه من ثلاث احرف كبتل فقط 
bool GuessPassword(string Password) {
    string word = "";
    int trial = 0;
    for (short i = 65; i <= 90; i++) {
        for (short u = 65; u <= 90; u++) {
            for (short j = 65; j <= 90; j++) {
                word = word + char(i);
                word = word + char(u);
                word = word + char(j);
               if (word == Password) {
                   cout << "\nPasswoerd is " << word << endl;
                   cout << "found ofter " << trial << " Triall(s)\n";
                   return true;
               }
            
               trial++;
               cout << "Trial [" << trial << "]: " << word << endl;
               word = "";
            }
        }

    }
    return false;
}
//}

//-------------------------------------------------
//Problem 18 / 2
//{
// You can use this function to read any text
string ReadText(string text) {
    string textcin;
    cout << text << endl;
    getline(cin, textcin);
    return textcin;
}
// To encrypt any character
//enter : A
//Output : according to EncryptionKy
char encryptChar(char littel,short EncryptionKy) {
    return ((short)littel)+ EncryptionKy;
}
// يقوم الفنكشن بتجفير الجمله اتي يتم ادخالها له حسب النكربشن كي 
string Encryption(string Peasword,short EncryptionKey) {
    string Encryption = "";
 
    for (short i = 0; i < Peasword.length(); i++) {
    
        Encryption = Encryption + encryptChar(Peasword[i], EncryptionKey);
    }
    return Encryption;
}
// يقوم بفك شفرة اي جمله بحسب الانكربشن كي المدخل فيها 
string Decryption(string Peasword, short EncryptionKey) {
    string Encryption = "";
    for (short i = 0; i < Peasword.length(); i++) {
        Encryption = Encryption + encryptChar(Peasword[i], -EncryptionKey);
    }
    return Encryption;
}


//-------------------------------------------------
//Problem 19 / 2


int RandomNumber(int From, int To)
{
    // Generate a random number between 0 and (To - From) using rand(),
    // then add From to shift the range to [From, To].
    int randNum = rand() % (To - From + 1) + From;
    return randNum;  // Return the generated random number.
}

//-------------------------------------------------
//Problem 20 / 2
enum enCharType { Number = 0,CapitalLetters=1,SmallLetters=2,SpecialCharacters=3};

char GetRandomCharacter(enCharType random) {
    switch (random) {
    case enCharType::Number:
        return (char)RandomNumber(48, 57);
    case enCharType::CapitalLetters:
        return (char)RandomNumber(65, 90);
    case enCharType::SmallLetters:
        return (char)RandomNumber(97, 122);
    case enCharType::SpecialCharacters:
        return (char)RandomNumber(33, 47);
    }
}

//-------------------------------------------------
//Problem 21 / 2
string GenerateWord(enCharType charType,short Length  ) {
    string text = "";
    for (short i = 0; i < Length; i++) {
        text = text + GetRandomCharacter(charType);
    }
    return text;
}
string DeleteListChar(string text,short Index,short length) {
    short deleteChar = Index + length;
    if (Index<0 || Index>text.length()+1) {
        return "";
    }
    string t = "";
    for (short i = 0; i <= text.length(); i++) {
        if (i >= Index && i <= deleteChar-1) {

        }
        else {
            t = t + text[i];
        }
    }
    return t;
}
string GenerateKeys() {
    string Key = "";
    for (short i = 0; i < 4; i++) {
        Key = Key + GenerateWord(enCharType::CapitalLetters,4) + "-";
    }
    return DeleteListChar(Key,Key.length()-1,1);
}
void printKeys(short number) {
    for (short i = 1; i <= number; i++) {
        cout <<"Key ["<<i<<"] : " << GenerateKeys() << endl;
    }
}

//-------------------------------------------------
//Problem 22 / 2
void ReadArea(short Number[100],short repeated)
{
    short count = 0;
    do
    {
       
        cout << "Element [" << count+1 << "] :";
        cin >> Number[count];
        count++;

    } while ((count)!=repeated);
}
short getHowNumberRepeated(short number, short Number[100]) {
    short count = 0;
    for (short i = 0; i < 100; i++) {
        if (Number[i] == number)
        {
            count++;
        }
   }
    return count;
}
void printArray(short Arr[100],short numberCheck) {
    for (short i = 0; i < numberCheck; i++) {
        cout << Arr[i] << " ";
    }
}


// Function: ReadArray
// Purpose: Reads an array of integers from the user.
//          First, it asks for the number of elements, then it reads each element.
// Parameters:
//   - arr: An integer array (with a maximum capacity of 100 elements) to store user inputs.
//   - arrLength: A reference variable to hold the number of elements entered by the user.
void ReadArray(int arr[100], int& arrLength)
{
    cout << "\nEnter number of elements:\n";
    cin >> arrLength;  // Read the total number of elements the user wishes to input.

    cout << "\nEnter array elements: \n";
    // Loop from 0 to arrLength - 1 to read each array element.
    for (int i = 0; i < arrLength; i++)
    {
        cout << "Element [" << i + 1 << "] : ";  // Display a prompt for each element (using 1-based indexing for clarity).
        cin >> arr[i];                           // Read the current element into the array.
    }
    cout << endl;  // Print an extra newline for formatting.
}

// Function: PrintArray
// Purpose: Prints the elements of an integer array separated by spaces.
// Parameters:
//   - arr: The array to print.
//   - arrLength: The number of elements in the array.
void PrintArray(int arr[100], int arrLength)
{
    // Loop through the array and print each element followed by a space.
    for (int i = 0; i < arrLength; i++)
        cout << arr[i] << " ";

    cout << "\n";  // Print a newline after all elements are printed.
}

// Function: TimesRepeated
// Purpose: Counts how many times a specified number appears in the array.
// Parameters:
//   - Number: The number to search for in the array.
//   - arr: The array in which to count occurrences.
//   - arrLength: The number of elements in the array.
// Returns: The count of occurrences of the specified number in the array.
int TimesRepeated(int Number, int arr[100], int arrLength)
{
    int count = 0;  // Initialize a counter to zero.
    // Loop through the array indices from 0 to arrLength - 1.
    for (int i = 0; i <= arrLength - 1; i++)
    {
        if (Number == arr[i])  // If the current element equals the number we're checking,
        {
            count++;  // Increment the counter.
        }
    }
    return count;  // Return the total count.
}

//-------------------------------------------------
//Problem 23 / 2
void AddRandemNumArray(int arr[100],int &Length) {
    cout << "enter the length to array:";
    cin >> Length;
    for (int i = 0; i < Length; i++)
    {
       
        arr[i] = RandomNumber(0, 100);
    }

}
//-------------------------------------------------
//Problem 24 / 2
int MaxNumberInArray(int arr[100],int Length) {
    int MaxNum = 0;
    for (int i = 0; i < Length; i++) {
        
            if (MaxNum < arr[i])
            {
                MaxNum = arr[i];
            }
    }
    return MaxNum;
   
}
//-------------------------------------------------
//Problem 25 / 2
int MinNumberInArray(int arr[100], int Length) {
    int MinNum = arr[0];
    for (int i = 0; i < Length; i++) {

        if (MinNum > arr[i])
        {
            MinNum = arr[i];
        }
    }
    return MinNum;

}
//-------------------------------------------------
//Problem 26 / 2
float TotalNumberInArray(int arr[100], int Length) {
    int total = 0;
    for (int i = 0; i < Length; i++) {

        total = total + arr[i];
    }
    return total;

}
//-------------------------------------------------
//Problem 27 / 2
float ArrAverge(int Arr[100], int Length) {

    return TotalNumberInArray(Arr, Length) / Length;
}
//-------------------------------------------------
//Problem 28 / 2
void CodeArr1TOArr2(int Arr1[100], int Arr2[100], int Length) {
    for (int i = 0; i < Length; i++) {
        Arr2[i] = Arr1[i];
    }
}
//-------------------------------------------------
//Problem 29 / 2

void CodePrimNumberFromArr1TOArr2(int Arr1[100], int Arr2[100], int Length,int &Arr2Length) {
    int index = 0;
    for (int i = 0; i < Length; i++) {
        if (CheckPrime(Arr1[i]) == enPrimNumber::Prim)
        {
            Arr2[index] = Arr1[i];
            index++;
        }
    }
    Arr2Length = index;
   
}
//-------------------------------------------------
//Problem 30 / 2
void FillArrayWithRandomNumbers(int arr[100], int Length) {
    for (int i = 0; i < Length; i++) {

        arr[i] = RandomNumber(1, 100);

    }
}
void SumTowArry(int Arr1[100], int Arr2[100], int Arr3[100], int Length) {
    int index = 0;
    for (int i = 0; i < Length; i++) {
     
            Arr3[i] = Arr1[i] + Arr2[i];
        
    }


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



    //-------------------------------------------------
    //Problem 5 / 2
    //PrintNumbers(1234);
    // Call ReadPositiveNumber to get a positive integer from the user and pass it to PrintDigits.
    //PrintDigits(ReadPositiveNumber("Please enter a positive number?"));


    //-------------------------------------------------
    //Problem 6 / 2
    //cout<<SumOfDigits(1265);




    //-------------------------------------------------
    //Problem 7 / 2
    //cout<< ReverseNumber(1234);


    //-------------------------------------------------
    //Problem 8 / 2
    //cout<<  Frequency(12221222,2);

    //-------------------------------------------------
    //Problem 9 / 2
    
    //HowOftenEachNumberIsRepeatd(11244466);
    
    //Answer's Mohammed {
    // Prompt the user to enter a number.
    //int Number = ReadPositiveNumber("Please enter the a number?");
    // Print the frequency of each digit (0-9) in the entered number.
    //PrintAllDigitsFrequencey(Number);
    //}

     //-------------------------------------------------
    //Problem 10 / 2
    //PrintDigits(ReverseNumber(123456));

     //-------------------------------------------------
    //Problem 11 / 2
    /*
    if (IsPalindromeNumber(ReadPositiveNumber("please enter a Positive number?")))
        cout<<"\nYes ,it is a palindrom number.\n";
    else
        cout<<"\nNo , it is Not a Palindrome number.\n";
    */



    //-------------------------------------------------
    //Problem 12 / 2
    //PrintInvertedPatternNumber(ReadPositiveNumber("please enter a positive number?"));

    //-------------------------------------------------
    //Problem 13 / 2
    // PrintNumberPattern(5);


    //-------------------------------------------------
    //Problem 14 / 2
    //PrintLetterPattern(7);
    
    // Prompt the user to enter a positive number and use it to print the inverted letter pattern.
    //PrintInvertedLetterPattern(ReadPositiveNumber("Please enter a positive number?"));//Answer's Mohammed 


    //-------------------------------------------------
    //Problem 15 / 2
   // PrintLettersAscending(5);
  
    

    //-------------------------------------------------
    //Problem 16 / 2
    //PrintAllPossibleCharacters();
    
    //-------------------------------------------------
    //Problem 17 / 2
    //GuessPassword("FFA");



    //-------------------------------------------------
    //Problem 18 / 2
    /*
    string name = ReadText("neter your name:");
    const short EncryptionKey=2;
    cout << "\nText Before Encryption :" << name << endl;
    cout <<"Text After Encryption :"<< Encryption(name, EncryptionKey) << endl;
    cout <<"Text After Decryption :" << Decryption(Encryption(name, EncryptionKey), EncryptionKey) << endl;
    */

srand((unsigned)time(NULL));
    //-------------------------------------------------
    //Problem 19 / 2
    /*   
  
    cout<<RandomNumber(50, 80);
    */

    //-------------------------------------------------
    //Problem 20 / 2
    /*
    srand((unsigned)time(NULL));
    cout << GetRandomCharacter(enCharType::SmallLetters) << endl;
    cout << GetRandomCharacter(enCharType::CapitalLetters) << endl;
    cout << GetRandomCharacter(enCharType::SpecialCharacters) << endl;
    cout << GetRandomCharacter(enCharType::Number) << endl;
    */
    
    
    //-------------------------------------------------
    //Problem 21 / 2
    //printKeys(5);
     

    //-------------------------------------------------
    //Problem 22 / 2
    //this my answer 
    //
    //    short number[100];
    //    short sizeArry = ReadPositiveNumber("how many times do you want to enter number?");
    //    ReadArea(number, sizeArry);
    //short numberCheck = ReadPositiveNumber("Enter the number you want to check : ");
    //cout << "Original array:";
    //printArray(number, sizeArry);
    //
    //    cout<<"\n"<<numberCheck<<" is repeated "<< getHowNumberRepeated(numberCheck, number)<<" time(s)";
    
    //this answer's 
    //
    //int arr[100];      // Declare an array to hold up to 100 integers.
    //int arrLength;     // Variable to store the number of elements in the array.
    //int NumberToCheck; // The number whose frequency will be checked in the array.
    //
    //// Read array elements from the user.
    //ReadArray(arr, arrLength);
    //
    //// Prompt the user to enter the number for which frequency is to be checked.
    //NumberToCheck = ReadPositiveNumber("Enter the number you want to check: ");
    //
    //// Display the original array.
    //cout << "\nOriginal array: ";
    //PrintArray(arr, arrLength);
    //
    //// Display the frequency count for the specified number.
    //cout << "\nNumber " << NumberToCheck;
    //cout << " is repeated ";
    //cout << TimesRepeated(NumberToCheck, arr, arrLength) << " time(s)\n";

    //-------------------------------------------------
    //Problem 23 / 2
    /*int arr[100];
    int lenthe;
    AddRandemNumArray(arr, lenthe);
    cout << "Array Elements : ";
    PrintArray(arr,lenthe);  */


    //-------------------------------------------------
   //Problem 24 / 2
    /*int arr[100];
    int lenthe;
    AddRandemNumArray(arr, lenthe);
    cout << "Array Elements : ";
    PrintArray(arr, lenthe);
    cout << "\nMax Number is : ";
   cout<< MaxNumberInArray(arr, lenthe);*/



   //-------------------------------------------------
  //Problem 25 / 2
  //int arr[100];
  //int lenthe;
  //AddRandemNumArray(arr, lenthe);
  //cout << "Array Elements : ";
  //PrintArray(arr, lenthe);
  //cout << "\nMin Number is : ";
  //cout<<MinNumberInArray(arr, lenthe);


   //-------------------------------------------------
  //Problem 26 / 2
  /*int  arr[100];
  int lenthe;
  AddRandemNumArray(arr, lenthe);
  cout << "Array Elements : ";
  PrintArray(arr, lenthe);
  cout << "\nTotal Number is : ";
  cout<<TotalNumberInArray(arr, lenthe);*/



  //-------------------------------------------------
//Problem 27/ 2
  //int  arr[100];
  //int lenthe;
  //AddRandemNumArray(arr, lenthe);
  //cout << "Array Elements : ";
  //PrintArray(arr, lenthe);
  //cout << "\nAverg Number is : ";
  //cout << ArrAverge(arr, lenthe);

  
 

  //-------------------------------------------------
//Problem 28/ 2
 /* int  arr1[100],arr2[100];
  int lenthe;
  AddRandemNumArray(arr1, lenthe);
  cout << "Array1 Elements : ";
  PrintArray(arr1, lenthe);

  cout << "Array2 Elements : ";
  PrintArray(arr2, lenthe);

  cout << "\nCody Arr1 to Arr2   : ";
  CodeArr1TOArr2(arr1, arr2, lenthe);
  cout << "\nArray2 Elements : ";
  PrintArray(arr2, lenthe);*/



  //-------------------------------------------------
  //Problem 29/ 2
  /*int  arr1[100],arr2[100];
  int lenthe;
  AddRandemNumArray(arr1, lenthe);
  cout << "Array1 Elements : ";
  PrintArray(arr1, lenthe);

  cout << "Array2 Elements : ";
  PrintArray(arr2, lenthe);
  int LentheArr2;
  cout << "\nCody PrimNumber Arr1 to Arr2   : ";
 CodePrimNumberFromArr1TOArr2(arr1, arr2, lenthe, LentheArr2);
  cout << "\nArray2 Elements : ";
  PrintArray(arr2, LentheArr2);*/


  //-------------------------------------------------
  //Problem 30/ 2
  /*int  arr1[100],arr2[100],arr3[100];
  int lenthe=ReadPositiveNumber("How many elements :");
  FillArrayWithRandomNumbers(arr1, lenthe);
  FillArrayWithRandomNumbers(arr2, lenthe);
  cout << "Array1 Elements : ";
  PrintArray(arr1, lenthe);

  cout << "Array2 Elements : ";
  PrintArray(arr2, lenthe);

  SumTowArry(arr1, arr2, arr3, lenthe);

  cout << "Array3 Elements : ";
  PrintArray(arr3, lenthe);*/


}
