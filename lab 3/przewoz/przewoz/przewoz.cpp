#ifdef PRZEWOZ_FINAL
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

struct towar_t {
	double cena, waga, oplacalnosc;
};

void swap(towar_t* arr, int left, int right) {
	towar_t temp = arr[left];
	arr[left] = arr[right];
	arr[right] = temp;
}
int partition(towar_t* arr, int left, int right, towar_t pivot) {

	while (left <= right) {
		while (arr[left].oplacalnosc > pivot.oplacalnosc)
			left++;
		while (arr[right].oplacalnosc < pivot.oplacalnosc)
			right--;

		if (left <= right) {
			swap(arr, left, right);
			left++;
			right--;
		}
	}

	return left;
}
void QS(towar_t* arr, int left, int right) {
	if (left >= right) return;

	towar_t pivot = arr[left / 2 + right / 2];

	int index = partition(arr, left, right, pivot);

	QS(arr, left, index - 1);
	QS(arr, index, right);
}

int main() {

	int ilosc = 123;

	while (scanf("%d ", &ilosc) != EOF) {
		towar_t* towar = new towar_t[ilosc];

		for (int i = 0; i < ilosc; i++)
			cin >> towar[i].cena;
		for (int i = 0; i < ilosc; i++)
			cin >> towar[i].waga;

		double ladownosc = 0;
		cin >> ladownosc;

		for (int i = 0; i < ilosc; i++)
			towar[i].oplacalnosc = towar[i].cena / towar[i].waga;

		QS(towar, 0, ilosc - 1);

		double profit = 0;
		double zaladowane_masa = 0;

		for (int i = 0; i < ilosc; i++) {
			if (ladownosc - zaladowane_masa >= towar[i].waga) {
				profit += towar[i].cena;
				zaladowane_masa += towar[i].waga;
			}
		}

		cout << profit << endl;

		delete[] towar;
	}
	return 0;
}

#endif

