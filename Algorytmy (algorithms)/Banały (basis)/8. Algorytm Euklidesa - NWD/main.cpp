#include <iostream>

using namespace std;

int main()
{
    int a, b, iloczyn;
    cout << "Podaj pierwsza liczbe: ";
    cin >> a;
    cout << "Podaj druga liczbe: ";
    cin >> b;

    if(a <= 0 || b <= 0){
        cout << "OCZUST!";
        return 0;
    }

    int x = a;
    int y = b;

    iloczyn = a * b;

    while(a != b)
    {
        if(a > b) {
            a = a - b;
        } else {
            b = b - a;
        }
    }

    cout << "NWD(" << x << "," << y << "): " << a << endl;

    return 0;
}
