#include<iostream>

using namespace std;

int horner(int wsp[], int s, int x){

	if(s==0){
		return wsp[0];
    }
	return x * horner(wsp,s-1,x) + wsp[s];
}

int main()
{
    setlocale(LC_ALL, "");

	int *w;
	int st, x;

	cout<<"Podaj stopieñ wielomianu: ";
	cin>>st;

	w = new int [st+1];

	for(int i=0; i<=st; i++){
		cout << "Podaj wspó³czynnik stoj¹cy przy potêdze " << st-i << ": ";
		cin >> w[i];
	}

	cout << "Podaj argument: ";
	cin >> x;

	cout << "W(" << x << ") = " << horner(w,st,x) << endl;

	delete [] w;

	return 0;
}
