#include <iostream>
#include <math.h>

using namespace std;

class Dzialania{

public:

double a, b;
double wynik;

double dodawanie(){
    cout << "Podaj 1 liczbê: " << endl;
    cin >> a;
    cout << "Podaj 2 liczbê: " << endl;
    cin >> b;
    wynik = (a+b);
    return wynik;
}

double odejmowanie(){
    cout << "Podaj 1 liczbê: " << endl;
    cin >> a;
    cout << "Podaj 2 liczbê: " << endl;
    cin >> b;
    wynik = (a-b);
    return wynik;
}

double mnozenie(){
    cout << "Podaj 1 liczbê: " << endl;
    cin >> a;
    cout << "Podaj 2 liczbê: " << endl;
    cin >> b;
    wynik = (a*b);
    return wynik;
}

double dzielenie(){
    cout << "Podaj 1 liczbê: " << endl;
    cin >> a;
    cout << "Podaj 2 liczbê: " << endl;
    cin >> b;
    if(b==0){
        cout << "NIE DZIEL PRZEZ 0!" << endl << endl;
        wynik = 0;
        return wynik;
    }
    wynik = (a/b);
    return wynik;
}

int modulo(){
    cout << "Podaj 1 liczbê: " << endl;
    cin >> a;
    cout << "Podaj 2 liczbê: " << endl;
    cin >> b;
    int x = (int)a;
    int y = (int)b;
    wynik = (x%y);
    return wynik;
}

double pierwiastek(){
    cout << "Podaj liczbê: " << endl;
    cin >> a;
    if(a<0){
        cout << "MUSI BYÆ WIEKSZA/RÓWNA 0!" << endl << endl;
        wynik = 0;
        return wynik;
    }
    wynik = sqrt(a);
    return wynik;
}
};

int main()
{

setlocale(LC_ALL, "");

Dzialania *dzialanie = new Dzialania; // DEKLARACJA OBIEKTU "dzialanie"

char M;

while(1){ // NIESKONCZONA PETLA

    cout << "1 - Dodawanie" << endl;
    cout << "2 - Odejmwoanie" << endl;
    cout << "3 - Mno¿enie" << endl;
    cout << "4 - Dzielenie" << endl;
    cout << "5 - Modulo" << endl;
    cout << "6 - Pierwiastek" << endl;
    cout << "C - CZYŒÆ" << endl;
    cout << "E - WYJD" << endl << endl;
    cout << "Wybierz dzia³anie:" << endl;
    cin >> M;


    switch(M){
    case '1': (*dzialanie).dodawanie();
    cout << "Wynik: " << (*dzialanie).wynik << endl << endl;
    break;
    case '2': (*dzialanie).odejmowanie();
    cout << "Wynik: " << (*dzialanie).wynik << endl << endl;
    break;
    case '3': (*dzialanie).mnozenie();
    cout << "Wynik: " << (*dzialanie).wynik << endl << endl;
    break;
    case '4': (*dzialanie).dzielenie();
    cout << "Wynik: " << (*dzialanie).wynik << endl << endl;
    break;
    case '5': (*dzialanie).modulo();
    cout << "Wynik: " << (*dzialanie).wynik << endl << endl;
    break;
    case '6': (*dzialanie).pierwiastek();
    cout << "Wynik: " << (*dzialanie).wynik << endl << endl;
    break;
    case 'C': delete dzialanie; //  NIE WIEDZIALEM CZY WYCZYSCIC PAMIEC CZY WARTOSC WIEC WYBRALEM PAMIEC
    break;
    case 'E': return 0;
    break;
    case 'e': cout << "DU¯A LITERA!" << endl << endl;
    break;
    default: cout << endl << "Poda³eœ LE!" << endl << endl;
    break;
    }
}

    return 0;
}
