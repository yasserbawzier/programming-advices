
#include <iostream>
using namespace std;
void PrintNumbers(short number) {
        for (int i = 1; i <= number; i++)
    {
        cout << i << endl;
    }

}
void PrintNumbersReverse(short number) {
    for (int i = number; i >= 1; i--)
    {
        cout << i << endl;


    }
}
short TotalOddNumbers(short Number) {
    int total = 0;
    for (int i = 1; i <= Number; i++)
    {

        if (i % 2 != 0) {
            total += i;



        }
    }
    return total;
}
short TotalEvenNumbers(short Number) {
    int total = 0;
    for (int i = 1; i <= Number; i++)
    {
        if (i % 2 == 0) {
            total += i;
        }
    }
    return total;
}
int TotalFactorial(short Number) {
    int total = 1;
    for (int i = Number; i >= 1; i--) {
        total *= i;
    }
    return total;
}
void PrintAllCaracters() {
    for (short i = 65; i <= 90; i++) {
        cout << (char)i << endl;
    }
  
}
void Print
int main()
{
    //PrintNumbers(10);
    // cout<<"-----------------------------------\n";
    //PrintNumbersReverse(10);
    // cout<<"-----------------------------------\n";
    //cout << TotalOddNumbers(10) << endl;
    // cout<<"-----------------------------------\n";
    //cout << TotalEvenNumbers(10) << endl;
    // cout<<"-----------------------------------\n";
    // cout << TotalFactorial(3) << endl;
    // cout<<"-----------------------------------\n";
    //PrintAllCaracters();

    return 0;
}
