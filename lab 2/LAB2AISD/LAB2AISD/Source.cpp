#ifdef test2
#include <iostream>
#include <string>
#include <string.h>
#include <cstdlib>
#include <stdio.h>
using namespace std;

bool porownaj(string* w1, string* w2) {
    long int d1 = w1->length();
    long int d2 = w2->length();
    if (d1 < d2)
        return false;
    else if (d1 > d2)
        return true;
    else  if (d1 == d2) {
        for (int i = 0; i < d1; i++) {
            if (w1[i] > w2[i])
                return true;
            else
                return false;
        }
        return false;
    }
    else return false;

}

bool posortuj(string* tab, int size) {
    string save;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - 1; j++) {
            if (porownaj(&tab[j], &tab[j + 1])) {
                save = tab[j];
                tab[j] = tab[j + 1];
                tab[j + 1] = save;
            }
        }
    }
    return true;
}

int rozmiar;

int main() {
    while (scanf("%d", &rozmiar) != EOF) {

        string* tab = new string[rozmiar];

        for (int i = 0; i < rozmiar; i++)
            cin >> tab[i];

        if (posortuj(tab, rozmiar)) {

            for (int i = 0; i < rozmiar; i++)
                cout << tab[i] << endl;
        }
        else {
            cout << "BLAD SORTOWANIA" << endl;
        }
        delete[] tab;
    }
    return 0;
}

#endif