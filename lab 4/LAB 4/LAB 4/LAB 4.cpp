#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <bitset>
#define dlugoscintow 5
using namespace std;
#define MaksDlug 200

string addBinary(string a, string b)
{
    string result = ""; // Initialize result
    int s = 0;          // Initialize digit sum

    // Traverse both strings starting from last
    // characters
    int i = a.size() - 1, j = b.size() - 1;
    while (i >= 0 || j >= 0 || s == 1)
    {
        // Comput sum of last digits and carry
        s += ((i >= 0) ? a[i] - '0' : 0);
        s += ((j >= 0) ? b[j] - '0' : 0);

        // If current digit sum is 1 or 3, add 1 to result
        result = char(s % 2 + '0') + result;

        // Compute carry
        s /= 2;

        // Move to next digits
        i--; j--;
    }
    return result;
}

void IntDecToBinary(int n)
{
    // array to store binary number
    int binaryNum[dlugoscintow+1];

    // counter for binary array
    int i = 0;
    while (n > 0) {

        // storing remainder in binary array
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }

    // printing binary array in reverse order
    for (int j = i - 1; j >= 0; j--)
        cout << binaryNum[j];
}



string decToBinary(string num){
    
    
    int length = num.size();
    cout << "size: " << length << endl;
    
    int Clength = length;

    int size = 0;

    while (length > 0) {
        size++;
        length -= dlugoscintow;
    }

    //tworzenie tablicy intow
    int* liczby = new int[size];

    int iterator = 0;

    while (Clength > 0) {
        char* temp = new char[dlugoscintow + 1];
        int a = 0;
        for (int i = iterator; i < iterator + dlugoscintow; i++) {
            if (num[i] == '\0') break;
            temp[a] = num[i];
            a++;
        }

        sscanf(temp, "%d", &liczby[iterator]); //zamiana char array na int
        cout << liczby[iterator] << endl;
        iterator += dlugoscintow;
        Clength -= dlugoscintow;
    }

    string* liczbyBin = new string[size];

    //for (int i = 0; i < size; i++) {
    //    liczbyBin[i] = liczby[i];
    //}



    //int i = 0;
    //while (n > 0) {

    //    // storing remainder in binary array
    //    binaryNum[i] = n % 2;
    //    n = n / 2;
    //    i++;
    //}

    //// printing binary array in reverse order
    //for (int j = i - 1; j >= 0; j--)
    //    cout << binaryNum[j];


   /* char* end = str;
    while (*end) {
        int n = strtol(str, &end, 10);
        printf("%d\n", n);
        while (*end == ',') {
            end++;
        }
        str = end;
    }*/

    return num;
}

int main(){
    cout << "ilosc liczb:";
    int count; cin >> count;
    cout << endl;

    string* arr = new string[count];
    
    for (int i = 0; i < count; i++) {
        cout << "liczba " << i + 1 << ": ";
        cin >> arr[i];
        arr[i] = decToBinary(arr[i]);
        cout << endl;
    }

    string find;
    cout << "search for:";
    cin >> find;
    cout << endl;
    find = decToBinary(find);

    bool found = false;
    for (int i = 0; i < count; i++) {
        if (find == arr[i]) {
            found = true;
            break;
        }  
    }

    if (found)
        cout << "1\n";
    else
        cout << "0\n";


    delete[] arr;
    return 0;
}
