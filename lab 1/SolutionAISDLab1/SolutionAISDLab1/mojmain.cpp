#ifndef official
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <math.h>
#include <sstream> 
#include <stdio.h>
#include <cstdlib>
using namespace std;

unsigned long long int Binarna(unsigned long long int n) {
    unsigned long long int number = 0, potega = 0;

    unsigned long long int liczba[10];
    for (int i = 0; i < 10; i++)
        liczba[i] = 0;

    int kolejny = 10 - 1;
    while (n != 0) {
        if (n % 2 == 1) {
            number += pow(10, potega);
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

    unsigned long long int dlugosc = 0;

    while (scanf("%lld", &dlugosc) != EOF) {

        unsigned long long int maksliczba, powtorzeniadowykonania, odejmowanie = 1;

        powtorzeniadowykonania = pow(2, dlugosc) - 1;

        while (powtorzeniadowykonania != odejmowanie - 2) {
            maksliczba = pow(2, dlugosc) - odejmowanie;
            maksliczba = Binarna(maksliczba);

            int* maksliczba_tab = new int[dlugosc];
            char* liczba = new char[20];

            for (int i = 0; i < 20; i++)
                liczba[i] = '0';

            unsigned long long int ilosc_znakow = Lenght(maksliczba);
            unsigned long long int roznica = 0;

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


            //wypisz liczbę
                for (int i = 0; i < dlugosc; i++) {
                    cout << liczba[i];
                }

                cout << endl;

            odejmowanie++;
            delete[] liczba;
            delete[] maksliczba_tab;
        }
    }
    return 0;
}
#endif