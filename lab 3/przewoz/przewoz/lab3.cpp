#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <cstdlib>
using namespace std;
#define makslen 16
struct towar_t {
	int cena, waga;
};

int ilosc = 0;

int main() {

	towar_t* towar = new towar_t[20];

	while (scanf("%d ", &ilosc) != EOF) {

		int profit_final = 0;
		int powtorzeniadowykonania, odejmowanie = 1;
		powtorzeniadowykonania = pow(2, ilosc) - 1;

		for (int i = 0; i < ilosc; i++)
			cin >> towar[i].cena;
		for (int i = 0; i < ilosc; i++)
			cin >> towar[i].waga;

		int ladownosc = 0;
		cin >> ladownosc;


		int mliczba = 0;
		int ilosck = ilosc;
		while (ilosck >= 0) {
			mliczba += pow(2, ilosck-1);
			ilosck--;
		}
		
		int mliczbak = mliczba;
		int liczbabinarna[makslen] = { 0 };

			while (mliczba >= 0) {
				
				int liczbadec = mliczba;
				int profit_temp = 0;
				int zaladowane_masa = 0;


				for (int i = 0; liczbadec > 0; i++){
					liczbabinarna[i] = liczbadec % 2;

					if (liczbabinarna[i] == 1) {
						profit_temp += towar[i].cena;
						zaladowane_masa += towar[i].waga;
					}
					liczbadec /= 2;
				}

				if (profit_temp > profit_final && zaladowane_masa <= ladownosc)
					profit_final = profit_temp;

				mliczba--;

				for (int i = 0; i < makslen; i++)
					liczbabinarna[i] = 0;

			}


		printf("%d\n", profit_final);

		for (int i = 0; i < ilosc; i++)
			towar[i].cena = towar[i].waga = 0;

	}
		delete[] towar;
	
	return 0;
}


