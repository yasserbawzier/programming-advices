#include <string>
#include<cstdlib>
#include <iostream>
using namespace std;
enum enWinner{Player=1,Computer=2,Draw=3};//انم يساعد في التعامل على تقييم الفائزين في اللعبة 
enum enGameChoice{Stone = 1, Paper = 2, Scissors = 3};//انم يساعد في التعامل مع خيارات اللعبة 
//استركت فيه معلومات الجولة 
struct stRoundInfo  {

    int NumberRound;
    enWinner Winner;
    enGameChoice usersChoice;
    enGameChoice CompeoterChoice;

};
//ستركت فيه معلومات القيم كاملا 
struct stGameResult
{
    int NumberRounds = 0;
    int NumberTimesUserWon = 0;
    int NumberTimesComputerWon = 0;
    int NumberTimesDraw = 0;
    enWinner FinalWineer;
};



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
//هذا فنكشن يعطيك اسم الفائز في الجولة 
enWinner WhoIsRoundWinner(stRoundInfo RoundInfo) {
    if (RoundInfo.CompeoterChoice == RoundInfo.usersChoice) {
        return enWinner::Draw;
    }
    switch (RoundInfo.usersChoice) {
    case enGameChoice::Stone:
    {
        if (RoundInfo.CompeoterChoice == enGameChoice::Paper) {
            return enWinner::Computer;
        }
    }
    case enGameChoice::Paper:
    {
        if (RoundInfo.CompeoterChoice == enGameChoice::Scissors) {
            return enWinner::Computer;
        }
    }
    case enGameChoice::Scissors:
    {
        if (RoundInfo.CompeoterChoice == enGameChoice::Stone) {
            return enWinner::Computer;
        }
    }
    }

    return enWinner::Player;
}
//هذا فنكشن يعطيك اسم الفائز النهائي في القيم 
enWinner WhoIsGameWinner(stGameResult GameResult) {
    if (GameResult.NumberTimesComputerWon > GameResult.NumberTimesUserWon)
        return enWinner::Computer;
    else if (GameResult.NumberTimesComputerWon < GameResult.NumberTimesUserWon)
        return enWinner::Player;
    else
        return enWinner::Draw;
}
//هذا الفنكشن يقوم بتحميل البيانات الي الستركشر نتائج القيم 
stGameResult GameResult(short NumberOfGameRounds, short NumberTimesUserWon, short NumberTimesComputerWon, short NumberTimesDraw) {
    stGameResult GameResult;
    GameResult.NumberRounds = NumberOfGameRounds;
    GameResult.NumberTimesComputerWon = NumberTimesComputerWon;
    GameResult.NumberTimesUserWon = NumberTimesUserWon;
    GameResult.NumberTimesDraw = NumberTimesDraw;
    GameResult.FinalWineer = WhoIsGameWinner(GameResult);
    return GameResult;
}
//يقوم هذا البروسيجر بتغير لون الشاشة حسب الفائز او التعادل
void ChangMonter(enWinner Winner) {
    switch (Winner)
    {
    case enWinner::Player:
    {
        system("color 2F");
        break;
    }
    case enWinner::Computer:
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
//يعطيك هذا الفنكشن اسم الفائز في استرنق
string _PrintWinner(enWinner Winner) {
   
    switch (Winner)
    {
    case enWinner::Player:
    {
        return "Player";
    }
    case enWinner::Computer:
    {
        return "Computer";
    }
    default:
    {
        return "equal";
    }
    }
}
//يعطيك هذا الفنشكن اسم الخيار الذي تم اختياره كنص استرنق سواء حجر او ورقة او مقص
string _PrintGameToole(enGameChoice Tools) {
    switch (Tools)
    {
    case enGameChoice::Paper:
        return "Paper";
    case enGameChoice::Scissors:
        return "Scissors";
    case enGameChoice::Stone:
        return "Stone";
    }
}
//هنا يتم تغير لون الشاشة حسب الفائز وطباعة معلومات الجولة 
void PrintResiltRound(stRoundInfo Round) {
    ChangMonter(Round.Winner);
    cout << "\n-----------------------Round [" << Round.NumberRound << "] -----------\n";
    cout << "Player1  Choice : " << _PrintGameToole(Round.usersChoice) << endl;
    cout << "Computer Choice : " << _PrintGameToole(Round.CompeoterChoice) << endl;
    cout << "Round Winner    : " << _PrintWinner(Round.Winner) << endl;
    cout << "-------------------------------------------\n";
}

//هنا تبداء اللعبة ويلعب معك الكمبيوتر حسب المرات التي ادخلتها ثم يعطيك ستركتر فيه معلومات القيم كامل 
stGameResult Playing(short NumberOfGameRounds) {
    stRoundInfo Round;
    short NumberTimesUserWon = 0, NumberTimesComputerWon = 0, NumberTimesDraw = 0;
    for (short GameRounds = 1; GameRounds <= NumberOfGameRounds; GameRounds++) {
        cout << "\nRound [" << GameRounds << "] Begins :\n";
        Round.NumberRound = GameRounds;
        Round.usersChoice =(enGameChoice) ReadNumberInRange("Your Choice : [1] : Stone, [2] : Paper, [3] : Scissors ? ", 1, 3);
        Round.CompeoterChoice = (enGameChoice)RandomNumber(1, 3);
        Round.Winner = WhoIsRoundWinner(Round);
        PrintResiltRound(Round);


        if (Round.Winner == enWinner::Computer)
            NumberTimesComputerWon++;
        else if (Round.Winner == enWinner::Player)
            NumberTimesUserWon++;
        else
            NumberTimesDraw;

    }
    return GameResult(NumberOfGameRounds, NumberTimesUserWon, NumberTimesComputerWon, NumberTimesDraw);

}
void PrintGameOver() {
    cout << "\t\t---------------------------------------------------------------\n";
    cout << "\t\t\t\t+++ G a m e  O v e r +++\n";
    cout << "\t\t---------------------------------------------------------------\n";
}
//هذا البروسيجر يقوم بتغير لون الشاشه حسب الفائز ثم طباعة معلومات القيم كاملا 
void PrintGameOver(stGameResult GameOver) {
    
    ChangMonter(GameOver.FinalWineer);//تغيير الشاشة 
    PrintGameOver();//طباعة الراس
    cout << "\t\t-----------------------[ Game Results ]------------------------\n";
    cout << "\t\tGame Rounds       :" << GameOver.NumberRounds << endl;
    cout << "\t\tPlayer1 Won Times :" << GameOver.NumberTimesUserWon << endl;
    cout << "\t\tComputer won Times:" << GameOver.NumberTimesComputerWon << endl;
    cout << "\t\tDraw Timers       :" << GameOver.NumberTimesDraw << endl;
    cout << "\t\tFinal Winner      :" << _PrintWinner(GameOver.FinalWineer) << endl << endl;
}
//يتم اعادة الكنسل الى البداية مع تغيير اللون الشاشة الى الاسود 
void ResetScreen() {

    system("color 07"); // إعادة الخلفية سوداء والنص أبيض
    system("cls");
}
void start() {
    char ch = 'y';
    stGameResult GameResult;
    do
    {
        ResetScreen();
        short NumberOfGameRound = ReadNumberInRange("How wants Number Of Game Rounds :",1,10);
        GameResult= Playing(NumberOfGameRound);
        PrintGameOver(GameResult);
        cout << "do you wnats playing agen:[y] or [n] :";
        cin >> ch;
    } while (ch=='y'||ch=='Y');

 
}

int main()
{
    srand((unsigned)time(NULL));
    start();
}
