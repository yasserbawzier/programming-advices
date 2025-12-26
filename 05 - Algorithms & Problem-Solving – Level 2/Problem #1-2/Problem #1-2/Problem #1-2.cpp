
#include <iostream>
#include<string>
using namespace std;
//my answer Problem 1/2 {

//function:Heder
//Purpose:íŞæã ÈØÈÇÚÉ ÑÇÓ ÌÏæá ÇáÖÑÈ 
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
//Purpose:íÚØíß ÌÏæá ÇáÖÑÈ Úáì Ôßá ãÑÈÚ 
//1  |  1   2   3   4   5   6   7   8   9   10
//2  |  2   4   6   8   10  12  14  16  18  20
//æåÇßĞÇ ÌãíÚ ÇáÇÑŞÇã Çáì 10
void PrintMultipliaction() {
    Heder();
    for (short i = 1; i <= 10; i++) {
        cout << i << speas(i);
        for(short j=1;j<=10;j++){
            cout << "\t"<< i * j;
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

// åĞÇ ÇáÍá ãä ÇáãÔßáÉ ÑŞã 
//#38 İí ÇáãÓÊæì ÇáÇæá ãä Íá ÇáãÔÇßá 
//íÊã ÇÚØÇÆß åá ÇáÑŞã ÈÑÇíã äãÈÑ Çæ áÇ ÇáÈÑÇíã äãÈÑ åæ ÇáÑŞã ÇáĞí áÇ íŞÈá ÇáŞÓãÉ ÅáÇ Úáì äİÓÉ Çæ æÇÍÏ
// enum :enPrimNumber
// Purpose: 
enum enPrimNumber { Prime = 1, NotPrime = 0 };
//Fanction:enCheckPrime
//Purpose:íÊÃßÏ áß åá ÇáÑŞã ÈÑÇíã äãÈÑ Çã áÇ æíÚØíß ÇáŞíãÉ ãä äæÚ 
//enPrimNumber
enPrimNumber enCheckPrime(short number) {
    short num = round(number / 2);
    for (short Count = 2; Count <= num; Count++) {
        if (number % Count == 0)
            return enPrimNumber::NotPrime;
    }
    return enPrimNumber::Prime;
}
//åĞÇ Íá ÇáãÔßáÉ ÑŞã 
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
//Purpose:åĞÇ ÇáÈÑæÓíÌÑ íØÈÚ áß ÇáÇÑŞÇã ÇáÈÑÇíã ãä ÇáÑŞã ÇáĞí ÊÎÊÇÑÉ Çáì ÇáÑŞã ÇáĞí ÊÎÊÇÑÉ
void PrintPrimNumber(short From, short to) {
    if (From > to) {
        
        SwabNumber(From, to);
    }
    for (float i = From; i <= to; i++) {
        if (enCheckPrime(i)==enPrimNumber::Prime) {
            cout << i << " ";
        }
    }
}
//}
int main()
{
   //Problem 1/2
    //PrintMultiplicationTable();

    PrintPrimNumber(1,50);
}
