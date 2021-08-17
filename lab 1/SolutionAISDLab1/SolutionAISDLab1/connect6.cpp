#ifndef connect

#define HEIGHT 15
#define WIDTH 15
#define IN_ROW 6

bool gameOver(char* znak, int x, int y) {
    static bool poziomo = true;
    static int iloscTakichSamychPol = 0;
    static char poprzedniZnak = '+';
    if (iloscTakichSamychPol == IN_ROW) {
        if (poziomo == true) {
            iloscTakichSamychPol = 0;
            if (x == WIDTH || (x < WIDTH && *znak != poprzedniZnak))
                return true;
            else
                return false;
        }
        if (poziomo == false) {
            iloscTakichSamychPol = 0;
            if (y == WIDTH || (y < WIDTH && *znak != poprzedniZnak))
                return true;
            else
                return false;
        }
    }
    else {
        if (*znak == '+') {
            iloscTakichSamychPol = 0;
            return false;
        }
        if (x > WIDTH || y > HEIGHT) {
            iloscTakichSamychPol = 0;
            return false;
        }
        if (iloscTakichSamychPol == 0) {
            //cout << x << " " << y << " " << *znak << "\n";
            poziomo = true;
            poprzedniZnak = *znak;
            iloscTakichSamychPol = 1;
            if (x == 0 || (x > 0 && *(znak - HEIGHT) != *znak)) {
                if (gameOver(znak + HEIGHT, x + 1, y) == true) {
                    iloscTakichSamychPol = 0;
                    return true;
                }
            }
            poziomo = false;
            poprzedniZnak = *znak;
            iloscTakichSamychPol = 1;
            if (y == 0 || (y > 0 && *(znak - 1) != *znak)) {
                if (gameOver(znak + 1, x, y + 1) == true) {
                    iloscTakichSamychPol = 0;
                    return true;
                }
            }
            poziomo = true;
            iloscTakichSamychPol = 0;
            poprzedniZnak = '+';
            return false;
        }
        else {
            //cout << "- " << x << " " << y << " " << *znak << " " << iloscTakichSamychPol << "\n";
            if (poziomo == true) {
                if (*znak == poprzedniZnak) {
                    iloscTakichSamychPol++;
                    return gameOver(znak + HEIGHT, x + 1, y);
                }
                else {
                    iloscTakichSamychPol = 0;
                    return false;
                }
            }
            else {
                if (*znak == poprzedniZnak) {
                    iloscTakichSamychPol++;
                    return gameOver(znak + 1, x, y + 1);
                }
                else {
                    iloscTakichSamychPol = 0;
                    return false;
                }
            }
        }
    }
    iloscTakichSamychPol = 0;
    return false;
}
#endif