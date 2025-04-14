#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "");
    int a;
    int suma = 1;
    cout << "Podaj liczbê:" << endl;
    cin >> a;

    for(int i = 1 ; i <=a ; i++){
        suma*=i;
    }

    cout << "Silnia z " << a << ": "<< suma;

    return 0;
}
