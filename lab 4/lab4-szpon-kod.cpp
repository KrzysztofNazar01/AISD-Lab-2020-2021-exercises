#include <iostream>

using namespace std;
bool ContainClaw(bool** array, const int size) {
        for (int i = 0; i < size; i++) 
                for (int j = 0; j < size; j++) 
                        for (int k = j+1; k < size; k++) 
                                for (int l = k+1; l < size; l++) 
                                        if (array[i][j])
                                                if(array[i][k])
                                                        if(array[i][l])                                         
                                                                if (!array[j][l])
                                                                        if(!array[j][k])
                                                                                if(!array[k][l]) return 1;                                              
                                        
        return 0;
}
int main() {
        int size; 
        char input;
        bool** array;
        for (int z = 0; z < 20; z++) {
                cin >> size;
                array = new bool*[size];
                for (int i = 0; i < size; i++) array[i] = new bool[size];

                for (int i = 0; i < size; i++) {
                        for (int j = 0; j < size; j++) {
                                cin >> input;
                                if (input == '1') {
                                        array[i][j] = 1;
                                }
                                else if (input == '0') {
                                        array[i][j] = 0;
                                }
                        }
                }
                /*for (int i = 0; i < size; i++) {
                        for (int j = 0; j < size; j++) {
                                cout << array[i][j];
                        }
                        cout << endl;
                }*/
                cout << !ContainClaw(array, size) << endl;
                for (int i = 0; i < size; i++) delete[] array[i];
                delete[] array;


                
        }
        //system("pause");
        return 0;
}