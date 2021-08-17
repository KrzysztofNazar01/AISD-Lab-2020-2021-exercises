#ifdef probny
#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <string>
#include <math.h>
using namespace std;


int binlength(int a) {
    int l = 0;
    if (a == 0)return 1;
    while (a > 0) {
        a = a / 2;
        l++;
    }
    return l;
}

unsigned long long int decToBin(unsigned long long int dec)
{
    unsigned long long int bin = 0;
    unsigned long long int rem, next = 1;

    while (dec != 0){
        rem = dec % 2;
        dec >>= 1;
        bin += rem * next;
        next *= 10;
    }
    return bin;
}

int* toArr(unsigned long long int a, int l) {
    int* arr = new int[l];
    int k = 0;
    if (a != 0) {
        for (int i = l; i > 0; i--) {

            if (a >= pow(10, i)) {
                arr[k++] = 1;
                a -= pow(10, i);
            }
            else if (i != l) {
                arr[k++] = 0;
            }
        }

        if (a == 1) 
            arr[k] = 1;
        else 
            arr[k] = 0;
    }
    else {
        arr[k] = 0;
    }

    return arr;
}


int main() {
   
    unsigned long long int x=0;
    while (true) {
        cin >> x;
        int l = binlength(x);

        unsigned long long int a = decToBin(x);
        cout << endl;

        int* arr = toArr(a, l);

        for (int i = 0; i < l; i++) {
            cout << arr[i];
        }

        cout << endl << endl;

        delete[] arr;
    }

    return 0;
}
#endif