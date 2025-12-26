
#include <iostream>
#include<string>
using namespace std;
void Heder() {
    cout << "\t\t\tMultipliaction Table From 1 to 10\n\n";
    cout << "\t1\t2\t3\t4\t5\t6\t7\t8\t9\t10\n";
    cout << "-----------------------------------------------------------------------------------\n";
}
string speas(short number) {
    if (to_string(number).length() > 1) {
        return "  |";
    }
    else
        return "   |";
}
void Multipliaction() {
    for (short i = 1; i <= 10; i++) {
        cout << i << speas(i);
        for(short j=1;j<=10;j++){
            cout << "\t"<< i * j;
        }
        cout << "\n";
    }
}
int main()
{
    Heder();
    Multipliaction();
}
