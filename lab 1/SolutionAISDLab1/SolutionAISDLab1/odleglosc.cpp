#ifdef ODL
#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <string>
using namespace std;

int bezwzgl(int liczba) {
	return (liczba < 0) ? -liczba : liczba;
}

int main()
{
	int wynik = 0;
	string a, b;
	cin >> a >> b;
	wynik = bezwzgl(a.length() - b.length());
	int najkrotsze = a.length();
	if (najkrotsze > b.length()) {
		najkrotsze = b.length();
	}
	for (int i = 0; i < najkrotsze; i++) {
		if (a[i] != b[i]) {
			wynik++;
		}
	}
	cout << wynik;
	return 0;
}
#endif