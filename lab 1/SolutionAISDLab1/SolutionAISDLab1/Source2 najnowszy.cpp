#ifdef najnowszy 

#ifndef official
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <math.h>
#include <stdio.h>
#include <cstdlib>
using namespace std;

char* Binarna(unsigned long long int n, unsigned long long int* rozmiar) {

    int* arr = new int[20];

    //dec to bin
    for (int i = 0; n > 0; i++) {
        cout << n << " ";
        arr[i] = n % 2;

        n = n / 2;
        (*rozmiar)++;

    }

    char* liczba = new char[(*rozmiar)];

    //bin to char
    int k = 0;
    while (arr[k] != '\0') {
        liczba[k] = arr[k] + '0';
        k++;
    }
    cout << "A";
    delete[] arr;

    char* final = liczba;

    delete[] liczba;

    //return char arr
    return final;
}
unsigned long long int ilosc_cyfr(unsigned long long int n) {
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

        unsigned long long int maksliczba, powtorzeniadowykonania, odejmowanie = 1, rozmiar_czar = 0;

        powtorzeniadowykonania = pow(2, dlugosc) - 1;

        while (powtorzeniadowykonania != odejmowanie - 2) {
            maksliczba = pow(2, dlugosc) - odejmowanie;

            char* czar = Binarna(maksliczba, &rozmiar_czar);


            char* liczba = new char[20];
            unsigned long long int  b = 20 - 1;

            for (int i = 0; i < 20; i++)
                liczba[i] = 0;

            unsigned long long int ilosc_znakow = ilosc_cyfr(maksliczba);
            unsigned long long int roznica = 0;

            if (ilosc_znakow != dlugosc)
                roznica = dlugosc - ilosc_znakow;

            //pierwsza czesc liczby
            for (int i = 0; i < roznica; i++)
                liczba[i] = '0';



            //dopiswanie drugiej czesci liczby

            int kolejna = 0;
            for (int i = roznica; i < rozmiar_czar + roznica; i++) {
                liczba[i] = czar[kolejna];
                kolejna++;
            }

            bool symetryczne = false;
            int polowa;

            if (dlugosc > 1) polowa = dlugosc / 2;
            else polowa = 1;

            for (int i = 0; i < polowa; i++) {
                if (liczba[i] == liczba[rozmiar_czar + roznica - 1 - i])
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

            if (odejmowanie == powtorzeniadowykonania + 1)
                cout << endl;

            odejmowanie++;
            delete[] liczba;
        }
    }
    return 0;
}
#endif
#endif