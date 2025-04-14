#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "");
    int a;
    int dzielniki = 0;
    cout << "Podaj liczbê: ";
    cin >> a;

    for(int i = 2; i <= a ; i++){
        if(a%i==0)  dzielniki++;
        if(dzielniki > 2){
        cout << "Nie jest liczb¹ pierwsz¹!";
        }
    }

    if(dzielniki > 2){
        cout << "Nie jest liczb¹ pierwsz¹!";
    }else{
        cout << "Jest liczb¹ peirwsz¹!";
    }

    return 0;
}
