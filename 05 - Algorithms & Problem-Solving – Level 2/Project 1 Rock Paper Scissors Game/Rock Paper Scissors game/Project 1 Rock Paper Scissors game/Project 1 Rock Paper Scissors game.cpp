// Project 1 Rock Paper Scissors game.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include<cstdlib>
using namespace std;
enum enGameTools { Stone = 1, Paper = 2, Scissors = 3 };
enum enWinner { Player = 0, Compeoter = 1, equal = 2 };



struct stRound
{
    int NumberRound;
    enWinner Winner;
    enGameTools usersChoice;
    enGameTools CompeoterChoice;


};




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

//function:ReadNumberInRange
//Parameters:string Massage , short From ,short to 
//return :This function displays a message to the user and takes values ​​from him within a specified range.
short ReadNumberInRange(string Massage, short From, short to) {
    short number;
    do
    {
        cout << Massage;
        cin >> number;

    } while (number<From || number>to);
    return number;
}







int RandomNumber(int From, int To)
{
    // Generate a random number between 0 and (To - From) using rand(),
    // then add From to shift the range to [From, To].
    int randNum = rand() % (To - From + 1) + From;
    return randNum;  // Return the generated random number.
}


enWinner ResaltRound(enGameTools UsersChoice, enGameTools CompeoterChoice) {
    if (UsersChoice == enGameTools::Stone && CompeoterChoice == enGameTools::Scissors)
        return enWinner::Player;
    else if (UsersChoice == enGameTools::Scissors && CompeoterChoice == enGameTools::Paper)
        return enWinner::Player;
    else if (UsersChoice == enGameTools::Paper && CompeoterChoice == enGameTools::Stone)
        return enWinner::Player;
    else if (CompeoterChoice == enGameTools::Stone && UsersChoice == enGameTools::Scissors)
        return enWinner::Compeoter;
    else if (CompeoterChoice == enGameTools::Scissors && UsersChoice == enGameTools::Paper)
        return enWinner::Compeoter;
    else if (CompeoterChoice == enGameTools::Paper && UsersChoice == enGameTools::Stone)
        return enWinner::Compeoter;
    else
        return enWinner::equal;
}

void PrintNumberRound(int numbersRound) {
    cout << "\nRound [" << numbersRound << "] begins :\n";
}
stRound Round(int NumberRound) {
    stRound Rounds;
    Rounds.NumberRound = NumberRound;
    PrintNumberRound(NumberRound);
    Rounds.usersChoice = enGameTools(ReadNumberInRange("Your Choice : [1]:Stone, [2]:Paper ,[3]:Scissors ?", 1, 3));
    Rounds.CompeoterChoice = enGameTools(RandomNumber(1, 3));
    Rounds.Winner = ResaltRound(Rounds.usersChoice, Rounds.CompeoterChoice);
    return Rounds;
}

void ChangMonter(enWinner Winner) {
    switch (Winner)
    {
    case enWinner::Player:
    {
        system("color 2F");
        break;
    }
    case enWinner::Compeoter:
    {
        system("color 4F");
        cout << "\a";        break;
    }
    default:
    {
        system("color 6F");        break;
    }
    }
}


string _PrintWinner(enWinner Winner) {
    system("color 07"); // إعادة الخلفية سوداء والنص أبيض
    switch (Winner)
    {
    case enWinner::Player:
    {
        ChangMonter(Winner);
        return "Player";
    }
    case enWinner::Compeoter:
    {
        ChangMonter(Winner);
        return "Computer";
    }
    default:
    {
        ChangMonter(enWinner::equal);
        return "equal";
    }
    }
}

string _PrintGameToole(enGameTools Tools) {
    switch (Tools)
    {
    case enGameTools::Paper:
        return "Paper";
    case enGameTools::Scissors:
        return "Scissors";
    case enGameTools::Stone:
        return "Stone";
    }
}
void PrintResiltRound(stRound Round) {

    cout << "\n-----------------------Round [" << Round.NumberRound << "] -----------\n";
    cout << "Player1  Choice : " << _PrintGameToole(Round.usersChoice) << endl;
    cout << "Computer Choice : " << _PrintGameToole(Round.CompeoterChoice) << endl;
    cout << "Round Winner    : " << _PrintWinner(Round.Winner) << endl;
    cout << "-------------------------------------------\n";
}


struct stGameOver
{
    int NumberRounds = 0;
    int NumberTimesUserWon = 0;
    int NumberTimesComputerWon = 0;
    int NumberTimesDraw = 0;
    enWinner FinalWineer;
};

enWinner FinalWineer(int NumberTimesUserWon, int NumberTimesComputerWon) {
    if (NumberTimesComputerWon > NumberTimesUserWon)
        return enWinner::Compeoter;
    else if (NumberTimesComputerWon < NumberTimesUserWon)
        return enWinner::Player;
    else
        return enWinner::equal;
}

stGameOver GameResults(stRound Round[10], int NumbersRound) {
    stGameOver GameOver;
    GameOver.NumberRounds = NumbersRound;
    for (int i = 0; i < NumbersRound; i++) {

        if (Round[i].Winner == enWinner::Player) {
            GameOver.NumberTimesUserWon++;
        }
        else if (Round[i].Winner == enWinner::Compeoter) {
            GameOver.NumberTimesComputerWon++;
        }
        else
        {
            GameOver.NumberTimesDraw++;
        }

    }
    GameOver.FinalWineer = FinalWineer(GameOver.NumberTimesUserWon, GameOver.NumberTimesComputerWon);

    return GameOver;

}

void PrintGameOver(stGameOver GameOver) {
    cout << "\t\t---------------------------------------------------------------\n";
    cout << "\t\t\t\t+++ G a m e  O v e r +++\n";
    cout << "\t\t---------------------------------------------------------------\n";
    cout << "\t\t-----------------------[ Game Results ]------------------------\n";
    cout << "\t\tGame Rounds       :" << GameOver.NumberRounds << endl;
    cout << "\t\tPlayer1 Won Times :" << GameOver.NumberTimesUserWon << endl;
    cout << "\t\tComputer won Times:" << GameOver.NumberTimesComputerWon << endl;
    cout << "\t\tDraw Timers       :" << GameOver.NumberTimesDraw << endl;
    cout << "\t\tFinal Winner      :" << _PrintWinner(GameOver.FinalWineer) << endl << endl;
}







char ReadChar(string text) {
    char c;
    cout << text << endl;
    cin >> c;
    return c;
}

void start() {
    char y;
    do
    {
        system("color 07"); // إعادة الخلفية سوداء والنص أبيض
        system("cls");

        int howManyGames = ReadNumberInRange("How Many Games 1 to 10:", 1, 10);
        stRound Rounds[10];
        for (int i = 0; i < howManyGames; i++) {

            Rounds[i] = Round(i + 1);
            PrintResiltRound(Rounds[i]);
        }
        PrintGameOver(GameResults(Rounds, howManyGames));
        y = ReadChar("do you wnats play agen[y] or [n]:");
    } while (y == 'Y' || y == 'y');
}

int main()
{

    srand((unsigned)time(NULL));
    start();


}