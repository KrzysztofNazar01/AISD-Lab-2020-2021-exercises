#ifdef ostrowski
#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <string>
using namespace std;
#define SIZE 100

int results[SIZE];
unsigned int next_result;


void szukaj(int to_be_found_count, int elements_count, int* searching_for, int* sequence) {
	for (int j = 0; j < to_be_found_count; j++) {
		bool found = false;
		for (int i = 0; i < elements_count; i++) {
			if (searching_for[j] == sequence[i]) {
				results[next_result] = i;
				next_result++;
				found = true;
			}
			else if (!found && i == elements_count - 1) {
				results[next_result] = -1;
				next_result++;
			}
		}
	}
}

void wypisz_wyniki() {
	int wypisz = 0;
	while (wypisz < next_result) {
		cout << results[wypisz] << endl;
		wypisz++;
	}
}
void oblsuz_scenariusze(int scenariusze) {
	for (int k = 0; k < scenariusze; k++) {

		int elements_count;
		cin >> elements_count;

		int* sequence = (int*)malloc(sizeof(int) * elements_count);
		for (int i = 0; i < elements_count; i++)
			cin >> sequence[i];

		int to_be_found_count = 0;
		cin >> to_be_found_count;

		int* searching_for = (int*)malloc(sizeof(int) * to_be_found_count);
		for (int i = 0; i < to_be_found_count; i++)
			cin >> searching_for[i];

		szukaj(to_be_found_count, elements_count, searching_for, sequence);

		free(sequence);
		free(searching_for);
	}
}

int main(){

	int scenariusze = 0;
	cin >> scenariusze;

	oblsuz_scenariusze(scenariusze);

	wypisz_wyniki();

	return 0;
}
#endif