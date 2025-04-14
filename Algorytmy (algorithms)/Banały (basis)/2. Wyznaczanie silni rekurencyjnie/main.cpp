#include <iostream>

using namespace std;

int silnia(int a){

    if(a==0 || a==1)     return 1;
    if(a>0)     return a*silnia(a-1);

}

int main()
{
    setlocale(LC_ALL, "");

    int x;
    cout << "Podaj liczbê: ";
    cin >> x;
    cout << "Silnia z " << x << ": " << silnia(x);

    return 0;
}
