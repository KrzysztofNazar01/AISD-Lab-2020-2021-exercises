#ifdef podciag
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <stdio.h>
#include <string>
using namespace std;

int main(int argc, const char* argv[]) {
    char slowoA[2001];
    char slowoB[2001];
    string najdluzszy;
    int dlugoscPierwszego = 0;
    int dlugoscDrugiego = 0;
    scanf("%s", slowoA);
    scanf("%s", slowoB);
    for (int i = 0; i < 2001; i++) {
        if (slowoA[i] == 0) break;
        dlugoscPierwszego++;
    }
    for (int i = 0; i < 2001; i++) {
        if (slowoB[i] == 0) break;
        dlugoscDrugiego++;
    }

    int** tablica = new int* [dlugoscPierwszego + 1];
    for (int i = 0; i <= dlugoscPierwszego; i++) {
        tablica[i] = new int[dlugoscDrugiego + 1];
    }

    for (int x = 0; x <= dlugoscPierwszego; x++) {
        tablica[x][0] = 0;
    }
    for (int y = 0; y <= dlugoscDrugiego; y++) {
        tablica[0][y] = 0;
    }
    for (int x = 0; x < dlugoscPierwszego; x++) {
        for (int y = 0; y < dlugoscDrugiego; y++) {
            if (slowoA[x] == slowoB[y]) {
                tablica[x + 1][y + 1] = tablica[x][y] + 1;
            }
            else {
                tablica[x + 1][y + 1] = max(tablica[x + 1][y], tablica[x][y + 1]);
            }
        }
    }

    int x = dlugoscPierwszego - 1;
    int y = dlugoscDrugiego - 1;
    while ((x >= 0) && (y >= 0)) {
        if (slowoA[x] == slowoB[y]) {
            najdluzszy = slowoA[x] + najdluzszy;
            x--;
            y--;
        }
        else if (tablica[x + 1][y] > tablica[x][y + 1]) {
            y--;
        }
        else {
            x--;
        }
    }
    printf("%s", najdluzszy.c_str());
    return 0;
}
#endif
