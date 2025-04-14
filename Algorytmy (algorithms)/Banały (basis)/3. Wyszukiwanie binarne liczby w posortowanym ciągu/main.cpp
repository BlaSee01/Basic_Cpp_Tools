#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "");
    int n;
    cout << "Podaj ilos� element�w tablicy: ";
    cin >> n;

    int tab[n];

    for(int i = 0 ; i <= n-1 ; i++){
        if(i==0){
            cout << "Podaj " << i+1 << " element tablicy: ";
            cin >> tab[i];
        }else{
            cout << "Podaj " << i+1 << " element tablicy (wi�kszy od " << tab[i-1] << "): ";
            cin >> tab[i];
            if (tab[i] < tab[i-1]){
                cout << "Oszust!";
                return 0;
            }
        }
        cout << endl;
    }

    int l = 0;
    int p = n-1;
    int s;
    int liczba;

    cout << "Jak� liczb� ca�kowit� odnale��: ";
    cin >> liczba;
    cout << endl;

    while(true){
        if (l <= p){
            s = (l+p)/2;
            if(tab[s] == liczba){
                cout << "Znaleziono liczb� " << liczba << " pod indexem: " << s+1 << endl;
                break;
            }else if(tab[s] < liczba){
                l = s+1;
            }else{
                p = s-1;
            }
        }
    }

    return 0;
}
