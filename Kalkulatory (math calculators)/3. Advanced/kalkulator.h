#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <conio.h>
#include <string.h>
#include <math.h>
#include <vector>

using namespace std;

class kalkulator{

public:

    string x;
    double wynik = 0;

    void dzialanie(){
        int i = 0;
        while(x[i-1]!='='){ //  WYPELNIENIE TABLICY STRINGOW
            x += getch();
            cout << x[i];
            if(x[i]=='Q' || x[i]=='q')   exit(0);
            i++;
        }
        int l = x.length();
        string y = x;
        vector <char> t;    //   WEKTOR ZE ZNAKAMI
        int pom;
        vector <double> t2;    //   WEKTOR Z LICZBAMI
        int counter = 0;
        for(int j = 0 ; j < l ; j++){
            if(x[j]=='+' || x[j]=='-' || x[j]=='*' || x[j]=='/' || x[j]=='^' || x[j]=='p' || x[j]=='%' || x[j]=='='){   // TABLICA Y = TABLICA X (ZNAKI ZASTAPIONE SEPARATOREM 'N')
                y[j]='N';
                t.push_back(x[j]);
                pom = stod(x.substr(counter,j-counter));
                t2.push_back(pom);
                counter=j+1;
            }else if(x[j]=='1' || x[j]=='2' || x[j]=='3' || x[j]=='4' || x[j]=='5' || x[j]=='6' || x[j]=='7' || x[j]=='8' || x[j]=='9'){
            }else{
                cout << endl << "Z³e znaki...";
                exit(0);
            }
        }

        for(int i = 0 ; i < t.size() ; i++){    // DLA NAJWYZSZEGO PRIORYTETU DZIALAN
            if(t[i]=='%' || t[i]=='p' || t[i]=='^'){
                switch(t[i]){
                case '^':
                wynik += pow(t2[i],t2[i+1]);
                t2[i] = pow(t2[i],t2[i+1]);
                t2.erase(t2.begin()+(i+1));
                t.erase(t.begin()+i);
                i = 0;
                break;
                case '%':
                wynik += (t2[i+1]/100*t2[i]);
                t2[i] = (t2[i+1]/100*t2[i]);
                t2.erase(t2.begin()+(i+1));
                t.erase(t.begin()+i);
                i = 0;
                break;
                case 'p':
                wynik += pow(t2[i],1/t2[i+1]);
                t2[i] = pow(t2[i],1/t2[i+1]);
                t2.erase(t2.begin()+(i+1));
                t.erase(t.begin()+i);
                i = 0;
                break;
                }
            }
        }

        for(int i = 0 ; i < t.size() ; i++){    // DLA SREDNIEGO PRIORYTETU DZIALAN
            if(t[i]=='*' || t[i]=='/'){
                switch(t[i]){
                case '*':
                wynik += (t2[i]*t2[i+1]);
                t2[i] = (t2[i]*t2[i+1]);
                t2.erase(t2.begin()+(i+1));
                t.erase(t.begin()+i);
                i = 0;
                break;
                case '/':
                if(t2[i+1]==0){
                    cout << "NIE DZIEL PRZEZ 0!";
                    return;
                }
                wynik += (t2[i]/t2[i+1]);
                t2[i] = (t2[i]/t2[i+1]);
                t2.erase(t2.begin()+(i+1));
                t.erase(t.begin()+i);
                i = 0;
                break;
                }
            }
        }

        for(int i = 0 ; i < t.size() ; i++){    // DLA NISKIEGO PRIORYTETU DZIALAN
            if(t[i]=='+' || t[i]=='-'){
                switch(t[i]){
                case '+':
                wynik += (t2[i]+t2[i+1]);
                t2[i] = (t2[i]+t2[i+1]);
                t2.erase(t2.begin()+(i+1));
                t.erase(t.begin()+i);
                i = 0;
                break;
                case '-':
                wynik += (t2[i]-t2[i+1]);
                t2[i] = (t2[i]-t2[i+1]);
                t2.erase(t2.begin()+(i+1));
                t.erase(t.begin()+i);
                i = 0;
                break;
                }
            }
        }
        switch(t[0]){   // PO PRZEJSCIU Z PETLI ZOSTAJA ELEMENTY T2[0] I T2[1] - OSTATECZNE DZIALANIE
            case '+':
            t2[0] = t2[0]+t2[1];
            break;
            case '-':
            t2[0] = t2[0]-t2[1];
            break;
        }
        cout << endl << "Wynik: " << t2[0];
    }

};
