#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "");

    string slowo;

    cout << "Podaj s³owo do sprawdzenia: ";
    cin >> slowo;

    int length = slowo.length();

    for(int i = 0 ; i < length ; i++){
        if(slowo[i]!=slowo[length-i-1]){
            cout << "Nie jest palidromem!";
            return 0;
        }
    }
    cout << "Jest palidromem!";

    return 0;
}
