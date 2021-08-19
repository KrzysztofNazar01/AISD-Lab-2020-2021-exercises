#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

bool CzyJedenGraf(char** graph, int size) {
	int i = 0;
	for (int j = 0; j < size; j++) {
		if (graph[i][j] == '1') {
			graph[j][i] = graph[i][j] = '0';
			i = j;
			j = -1;
		}
	}
	bool czyWczystkieDrogiWykorzysatne = true;
	for (int k = 0; k < size; k++) {
		for (int j = 0; j < size; j++) {
			if (graph[k][j] == '1') {
				czyWczystkieDrogiWykorzysatne = false;
				break;
			}
		}
	}

	return czyWczystkieDrogiWykorzysatne;
}

bool CzySaDwieJedynki(char** temp, int size) {

	for (int i = 0; i < size; i++) {
		int jedynki = 0;
		for (int j = 0; j < size; j++) {
			if (temp[i][j] == '1')
				jedynki++;
		}

		if (jedynki != 2) {
			return false;
		}

	}
	return true;
}

int main() {
	int iloscGrafow = 0;
	cin >> iloscGrafow;

	for (int k = 0; k < iloscGrafow; k++) {
		int size;
		cin >> size;

		//tworzenie macierzy
		char** temp = new char*[size];
		for (int i = 0; i < size; i++)
			temp[i] = new char[size];

		//zapelnianie macierzy
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				cin >> temp[i][j];
			}
		}

		if (CzySaDwieJedynki(temp,size)) 
			cout << CzyJedenGraf(temp, size) << endl;
		else
			cout << "0\n";


		for (int i = 0; i < size; i++)
			delete[]temp[i];
		delete[]temp;
	}
	


	
	return 0;
}