
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
void PrintMultiplicationTable() {
    for (int i = 1; i <= 10; i++) {
        cout << "Number :" << i << endl;
        for (int j = 1; j <= 10; j++) {
                        cout<<i<<" * "<<j<<" = "<<i*j<<endl;
        }
        cout << "---------------\n";
    }
}
void PrintEachLetterWithAllLetters() {
    //this function prints each letter with all letters from A to Z
    for (char i = 'A'; i <= 'Z'; i++) {
        cout << "Character :" << i << endl;
        for (char j = 'A'; j <= 'Z'; j++) {
            cout << i << j  << endl;
        }
        cout << "---------------\n";
    }
}
void PrintInvertedPyramid() {
    for (short i = 1; i <= 7; i++) {
        for (short j = 7; j >= i; j--) {
            cout << "*";
        }
        cout << "\n";
    }
}
void PrintPyramid() {
    for (short i = 1; i <= 7; i++) {
        for (short j = 1; j <= i; j++) {
            cout << "*";
        }
        cout << "\n";
    }
}
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
    // cout<<"-----------------------------------\n";
    //PrintMultiplicationTable();
    // cout<<"-----------------------------------\n";
    //PrintEachLetterWithAllLetters();
    // cout<<"-----------------------------------\n";
    //PrintInvertedPyramid();
    // this print inverted pyramid like this:
	//*******
    //******
    //*****
    //****
    //***
    //**
    //*
    // cout<<"-----------------------------------\n";
    //PrintPyramid();
    // this print pyramid like this:
    // *
    // **
    // ***
    // ****
    // *****
    // ******
    // *******
    // cout<<"-----------------------------------\n";
    
    
    
    
    return 0;
}
