#ifdef official
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <math.h>
#include <sstream> 
using namespace std;

unsigned long long int Poteguj(long long int potega, long long  int powtorzenia) {
    unsigned long long int number = 1;
    for (unsigned long long int i = 0; i < powtorzenia; i++) number *= potega;
    return number;
}
unsigned long long int Binarna(unsigned long long int n) {
    unsigned long long int number = 0, potega = 0;

    unsigned long long int liczba[10];
    for (int i = 0; i < 10; i++)
        liczba[i] = 0;

    int kolejny = 10 - 1;
    while (n != 0) {
        if (n % 2 == 1) {
            number += Poteguj(10, potega);
            liczba[kolejny] = number;
        }
        kolejny = 9;
        potega++;
        n = n / 2;
    }
    return number;
}
unsigned long long int Lenght(unsigned long long int n) {
    if (n == 0) return 1;
    unsigned long long int len = 0;
    while (n != 0) {
        len++;
        n /= 10;
    }
    return len;
}

int main() {

    std::string line;
    while (std::getline(std::cin, line)) {

        unsigned long long int maksliczba, powtorzeniadowykonania, odejmowanie = 1, dlugosc, granica;

        stringstream geek(line);
        geek >> dlugosc;

        powtorzeniadowykonania = Poteguj(2, dlugosc) - 1;

        granica = pow(2, dlugosc);

        while (powtorzeniadowykonania != odejmowanie - 2) {
            maksliczba = Poteguj(2, dlugosc) - odejmowanie;
            maksliczba = Binarna(maksliczba);

            char liczba[20];
            unsigned long long int  b = 20 - 1;

            for (int i = 0; i < 20; i++)
                liczba[i] = 0;

            unsigned long long int  ilosc_znakow = Lenght(maksliczba);
            unsigned long long int  roznica = 0;

            if (ilosc_znakow != dlugosc)
                roznica = dlugosc - ilosc_znakow;

            //pierwsza czesc liczby
            for (int i = 0; i < roznica; i++)
                liczba[i] = '0';

            string s = std::to_string(maksliczba);
            char const* pchar = s.c_str();

            //dopiswanie drugiej czesci liczby
            unsigned long long int  rozmiar_pchar = s.length();
            int kolejna = 0;
            for (int i = roznica; i < rozmiar_pchar + roznica; i++) {
                liczba[i] = pchar[kolejna];
                kolejna++;
            }

            bool symetryczne = false;
            int polowa;

            if (dlugosc > 1) polowa = dlugosc / 2;
            else polowa = 1;

            for (int i = 0; i < polowa; i++) {
                if (liczba[i] == liczba[rozmiar_pchar + roznica - 1 - i])
                    symetryczne = true;
                else {
                    symetryczne = false;
                    break;
                }
            }

            //wypisz liczbę
            if (symetryczne) {
                for (int i = 0; i < dlugosc; i++) {
                    cout << liczba[i];
                }
            }

            if (odejmowanie == granica)
                cout << endl;

            odejmowanie++;
        }
    }
    return 0;
}
#endif