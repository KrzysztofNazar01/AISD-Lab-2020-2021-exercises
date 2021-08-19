#include <iostream>

using namespace std;

void print(char** graph, int size) {
    for (int i = 0; i < size; i++) {
        for (int k = 0; k < size; k++) {
            cout << graph[i][k];
        }
        cout << endl;
    }
    cout << endl;
}
bool CzyJedenGraf(char** graph, int size) {
    bool* visited = new bool[size];
    for (int i = 0; i < size; i++) visited[i] = false;
    int last = 0;
    int i = 0;
    for (int j = 0; j < size; j++) {
        if (graph[i][j] == '1') {
            graph[i][j] = '0';
            graph[j][i] = '0';
            //cout << i << " " << j << endl;
            i = j;
            j = -1;
            //cout << i << " " << j << endl;
            //print(graph, size);
        }

    }

    for (int k = 0; k < size; k++) {
        for (int j = 0; j < size; j++) {
            if (graph[k][j] == '1') return false;
        }
    }
    return true;
}
int main() {
    int ammount;
    cin >> ammount;
    bool notCycle;
    for (int z = 0; z < ammount; z++) {
        notCycle = false;
        char** graph;
        int size;
        cin >> size;
        graph = new char* [size];
        int degree;
        for (int i = 0; i < size; i++) graph[i] = new char[size];
        for (int i = 0; i < size; i++) {
            degree = 0;
            for (int j = 0; j < size; j++) {
                cin >> graph[i][j];
                if (graph[i][j] == '1')degree++;
            }
            if (degree != 2) {
                notCycle = true;
            }
        }
        if (notCycle) {
            cout << 0 << endl;
            continue;
        }
        else {
            //print(graph, size);
            cout << CzyJedenGraf(graph, size) << endl;

        }
    }
    return 0;
}