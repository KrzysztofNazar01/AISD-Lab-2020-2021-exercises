#include <iostream>
using namespace std;

bool ChceckForTrap(char** edge_array, int num) {
	int* check_in = new int[num];
	int newly = 0;
	for (int i = 0; i < num; i++) {
		check_in[i] = 0;
	}
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++) {
			if (edge_array[i][j] == '1' && check_in[j] == 0) {
				check_in[j] = 1;
				newly++;
			}
		}
		if (i <= num / 2) {
			if (((i + 1) - newly) >= 0) {
				return false;
			}
		}
	}
	return true;
}



int main() {
	int how_many_graphs;
	bool cycle = true;
	cin >> how_many_graphs;
	for (int i = 0; i < how_many_graphs; i++) {
		int num;
		cin >> num;
		cycle = true;
		char** cycle_tab = new char*[num];
		if (cycle_tab != NULL) {
			char edge = _getchar_nolock();
			for (int j = 0; j < num; j++) {
				cycle_tab[j] = new char[num];
				if (cycle_tab[j] != NULL) {
					for (int k = 0; k < num; k++) {
						edge = _getchar_nolock();
						cycle_tab[j][k] = edge;
					}
				}
			}
			for (int k = 0; k < num; k++) {
				int edge_num = 0;
				for (int j = 0; j < num; j++) {
					if (cycle_tab[j][k] == '1') {
						edge_num++;
					}
				}
				if (edge_num != 2) {
					cycle = false;
				}
			}
			if (cycle == true) {
				cout << ChceckForTrap(cycle_tab, num) << endl;
			}
			else
				cout << "0" << endl;

			for (int k = 0; k < num; k++) {
				free(cycle_tab[k]);
			}
			free(cycle_tab);
			cycle_tab = NULL;
		}
	}

	return 0;
}