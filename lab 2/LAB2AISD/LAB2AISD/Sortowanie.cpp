#define _CRT_SECURE_NO_WARNINGS
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
    else  if(d1 == d2){
        for (int i = 0; i < d1; i++) {
            if (w1[i] > w2[i])
                return true;
            else
                return false;
        }
        return false;
    }
    else
		return false;
}

void Merge(string left[], string right[], string arr[], int size) {
	int half_left = size / 2;
	int half_right = size - half_left;

	int i = 0, l = 0, r = 0;

	while (l < half_left && r < half_right) {
		if (!porownaj(&left[l],&right[r])) { 
			arr[i++] = left[l++];
		}
		else {
			arr[i++] = right[r++];
		}
	}
	while (l < half_left) {
		arr[i++] = left[l++];
	}
	while (r < half_right) {
		arr[i++] = right[r++];
	}
}

void MergeSort(string arr[], int size) {
	if (size < 2) return;

	int half_left = size / 2;
	int half_right = size - half_left;

    string* left = new string[half_left];
    string* right = new string[half_right];

	for (int i = 0; i < half_left; i++) {
		left[i] = arr[i];
	}

	int kolejny = 0;
	for (int i = half_left; i < size; i++) {
		right[kolejny] = arr[i];
		kolejny++;
	}

	MergeSort(left, half_left);
	MergeSort(right, half_right);

	Merge(left, right, arr, size);

	delete[] left;
	delete[] right;
}

int rozmiar;

int main() {
    while (scanf("%d", &rozmiar) != EOF) {

        string* tab = new string[rozmiar];

        for (int i = 0; i < 100; i++)
            tab[i] =i;

	    MergeSort(tab, rozmiar);

        for (int i = 0; i < rozmiar; i++)
            cout << tab[i] << endl;
        
        delete[] tab;
    }
    return 0;
}