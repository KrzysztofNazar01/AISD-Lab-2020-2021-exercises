#ifdef lotek

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <algorithm>
using namespace std;

/*
5
1 3 2 4 5
2 3 1 5 4
7 8 9 10 11
6 7 8 11 13
1 2 3 4 5
2 3 4 5 1
7 8 9 11 10
*/

int n;
int wczytane[5];
int liczby[1000001];
int zgrupowane[1000001][2];
int ilosc = 0;
int licznik = 0;
bool ok = false;

void sortowanie(int* tablica, int lewy, int prawy) {
    int a = lewy, b = lewy;
    int srodek = (lewy + prawy) / 2;
    int piwot = tablica[srodek];
    tablica[srodek] = tablica[prawy];
    for (a = lewy; a < prawy; a++) {
        if (tablica[a] < piwot) {
            swap(tablica[a], tablica[b]);
            b++;
        }
    }
    tablica[prawy] = tablica[b];
    tablica[b] = piwot;
    if (lewy < b - 1) {
        sortowanie(tablica, lewy, b - 1);
    }
    if (b + 1 < prawy) {
        sortowanie(tablica, b + 1, prawy);
    }
}

int szukaj(int a, int b, int szukaneA) {
    int c = (a + b) / 2;
    while (a <= b) {
        c = (a + b) / 2;
        if (zgrupowane[c][0] == szukaneA) {
            break;
        }
        else if (zgrupowane[c][0] < szukaneA) {
            a = c + 1;
        }
        else {
            b = c - 1;
        }
    }
    return c;
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d %d %d", &wczytane[0], &wczytane[1], &wczytane[2], &wczytane[3], &wczytane[4]);
        sortowanie(wczytane, 0, 4);
        liczby[i] = wczytane[0] * 60 * 60 * 60 * 60 + wczytane[1] * 60 * 60 * 60 + wczytane[2] * 60 * 60 + wczytane[3] * 60 + wczytane[4];
    }
    sortowanie(liczby, 0, n - 1);
    int pozycja = 0;
    zgrupowane[pozycja][0] = liczby[0];
    zgrupowane[pozycja][1] = 1;
    for (int i = 1; i < n; i++) {
        if (liczby[i] == liczby[i - 1]) {
            zgrupowane[pozycja][1]++;
        }
        else {
            pozycja++;
            zgrupowane[pozycja][0] = liczby[i];
            zgrupowane[pozycja][1] = 1;
        }
    }
    pozycja++;
    while (scanf("%d %d %d %d %d", &wczytane[0], &wczytane[1], &wczytane[2], &wczytane[3], &wczytane[4]) != EOF) {
        sortowanie(wczytane, 0, 4);
        int liczba = wczytane[0] * 60 * 60 * 60 * 60 + wczytane[1] * 60 * 60 * 60 + wczytane[2] * 60 * 60 + wczytane[3] * 60 + wczytane[4];
        int miejsce = szukaj(0, pozycja, liczba);
        if (zgrupowane[miejsce][0] == liczba) {
            printf("%d\n", zgrupowane[miejsce][1]);
        }
        else {
            printf("*\n");
        }
    }
    return 0;
}


#endif