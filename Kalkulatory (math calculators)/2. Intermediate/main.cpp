#include <iostream>
#include "kalkulator.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "");
    int counter = 0;
    kalkulator K;
    while(1){
            if(counter == 0) cin >> K.x;
            cin >> K.znak;
            if((K.znak=='+') || (K.znak=='-') || (K.znak=='*') || (K.znak=='/')){
            cin >> K.y;
            cout << endl << "----------------------" << endl << "'1' - zmiana 1 liczby" << endl <<  "'2' - zmiana 2 liczby" << endl << "'z' - zmiana znaku" << endl << "'S' - wynik" << endl << "----------------------" << endl  << endl;
            cin >> K.pom;
            if(K.pom=='1'){
                cin >> K.x;
                K.pom = 'S';
            }else if(K.pom=='2'){
                cin >> K.y;
                K.pom = 'S';
            }else if(K.pom=='z'){
                cin >> K.znak;
                K.pom = 'S';
            }
            if(K.pom=='S'){
                cout << "=" << endl;
                switch(K.znak){
                case '+':
                    K.x = K.dodawanie();
                    cout << K.x;
                    break;
                case '-':
                    K.x = K.odejmowanie();
                    cout << K.x;
                    break;
                case '*':
                    K.x = K.mnozenie();
                    cout << K.x;
                    break;
                case '/':
                    K.x = K.dzielenie();
                    cout << K.x;
                    break;
                }
            }else{
                cout << "Poda³eœ Ÿle!";
                return 0;
            }
            K.MR = K.x;
            cout << endl << "----------------------" << endl << "MR/MC/M+/M-/S" << endl << "----------------------" << endl;
            cin >> K.znak2;
            if(K.znak2=="MR")   cout << K.M << endl;
            if(K.znak2=="MC")   K.M = 0;
            if(K.znak2=="M+")   K.M+=K.MR;
            if(K.znak2=="M-"){
                    if(K.MR>K.M){
                        K.M = 0;
                    }else{
                        K.M -= K.MR;
                    }
            }
            counter++;
            cout << endl;
            }else{
                cout << "Poda³eœ Ÿle!";
                return 0;
            }
        }

    return 0;
}
