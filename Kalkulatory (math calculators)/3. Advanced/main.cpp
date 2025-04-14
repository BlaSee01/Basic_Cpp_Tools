#include <iostream>
#include <math.h>
#include <cstdio>
#include "kalkulator.h"

using namespace std;

int main()
{

    setlocale(LC_ALL, "");
    cout << "Q = EXIT" << endl;
    while(1){
    kalkulator k;
    k.dzialanie();
    cout << endl;
    }

    return 0;
}
