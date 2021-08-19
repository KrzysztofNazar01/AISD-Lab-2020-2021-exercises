#include <iostream>
#include <string>
using namespace std;
 
void czytopalindrom(string s) {
        bool jest = true;
        for (int i = 0; i < s.length() / 2; i++) {
                if (s[i] != s[s.length() - 1 - i])
                        jest = false;
        
}
        if (jest)
                cout << s;
}
void przerzucenie(unsigned long int i,int n,char* znakitrzynastkowe) {
        string pusty = "";
        while (i != 0) {
                pusty.push_back(znakitrzynastkowe[i % 13]);
                i /= 13;
        
}
        while (pusty.length() < n)
                pusty.push_back('0');
        czytopalindrom(pusty);
 
}
 
 
int main() {
        long int x;
        int n;
        int ilosctestow;
        char znakitrzynastkowe[] = { '0','1','2','3','4','5','6','7','8','9','a','b','c' 
};
        cin >> ilosctestow;
        for (int i = 0; i < ilosctestow; i++) {
                cin >> n;
                x = pow(13.0, n) - 1;
                for (long int i = 0; i <= x; i = i + 2) {
                        przerzucenie(i,n,znakitrzynastkowe);
                
}
                cout << endl;
        
}
        return 0;
		}