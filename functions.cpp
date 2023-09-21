/*
    Projekt:            Taschenrechner
    Datei:              functions.cpp
    Autor:              <ommitted>
    Erstellungsdatum:   27.11.2018
    Letzte Änderung:    27.01.2019
    Beschreibung:       Code Datei die die Funktionen der FunctionClass und MainClass enthält.
*/

#include "FunctionClass.hpp"

void MainClass::open_menu() {
    FunctionClass fclass;
    bool erneut = false;
    string dummy;

    do {
        cout << "Was m" << oe << "chten Sie tun ?" << endl
             << "   Taschenrechner  (A)" << endl
             << "   Umrechner       (B)" << endl
             << "Ihre Wahl : ";
        cin >> dummy;
        cout << endl;

        if (dummy.length() == 1) {
            switch((char)dummy[0]) {
                case 'A':
                case 'a':
                    cout << "Starte Taschenrechner Programm..." << endl << endl;
                    do {
                        erneut = menu();
                    }
                    while(erneut == true);
                    erneut = false;
                    break;
                case 'B':
                case 'b':
                    cout << "Starte Umrechner Programm..." << endl << endl;
                    do {
                        erneut = menu2();
                    }
                    while(erneut == true);
                    erneut = false;
                    break;
                default:
                    fclass.error("Wiederholen Sie Ihre Eingabe.");
                    cout << endl;
                    erneut = true;
                    break;
            }
        }
        else {
            system("CLS");
            cout << "Eingabe ung" << ue << "ltig !" << endl
                 << "Wiederholen Sie Ihre Eingabe." << endl;
            system("PAUSE");
            cout << endl;
            erneut = true;
        }
    }
    while(erneut == true);
}

bool FunctionClass::push_in(string numb_string, vector<int> &zahl, const unsigned int base_int) {
    int numb_int;
    char dummy;

    for (unsigned int i = 0; i < numb_string.length(); i++) {
        dummy = numb_string[i];
        numb_int = (int)dummy;

        if (((unsigned int)numb_int > 47 + base_int && base_int < 11) || ((unsigned int)numb_int > 54 + base_int && base_int > 10 && numb_int < 97) || ((unsigned int)numb_int > 86 + base_int && base_int > 10)) {
            system("CLS");
            cout << "Ihr verwendetes Zahlensystem stimmt nicht mit dem angegebenen Zahlensystem "<< ue <<"berein !" << endl
                 << "Zu verwendende Basis lautet " << base_int << " !" << endl;
            return true;
        }

        numb_int = value(dummy);

        if (numb_int == -1) {
            system("CLS");
            cout << "Verwendete Zahlen sind nicht positive ganze Zahlen !" << endl
                 << "Bitte wiederholen Sie Ihre Eingabe !" << endl;
            return true;
        }

        zahl.push_back(numb_int);
    }

    return false;
}

bool FunctionClass::is_zahl_bigger(vector<int> &zahl_1, vector<int> &zahl_2, const unsigned int base_1, const unsigned int base_2) {
    int zahl1 = hornerschema(zahl_1, base_1);
    int zahl2 = hornerschema(zahl_2, base_2);

    if (zahl1 >= zahl2) {
        return true;
    }

    return false;
}

unsigned int FunctionClass::value(char numb_char) {
    int numb = (int)numb_char;
    if (numb > 47 && numb < 58) {
        return numb - 48;
    }
    else if (numb > 64 && numb < 91) {
        return numb - 55;
    }
    else if (numb > 96 && numb < 123) {
        return numb - 87;
    }
    return -1;
}

void FunctionClass::equal_size(vector<int> &zahl_1, vector<int> &zahl_2) {
    if (zahl_1.size() < zahl_2.size()) {
        while (zahl_1.size() != zahl_2.size()) {
            zahl_1.insert(zahl_1.begin(),0);
        }
    }
    else if (zahl_2.size() < zahl_1.size()) {
        while (zahl_2.size() != zahl_1.size()) {
            zahl_2.insert(zahl_2.begin(),0);
        }
    }
}
bool FunctionClass::is_end(vector<int> &zahl, int pos) {
    if (zahl[pos] != 0) {
        return false;
    }

    if (pos != 0) {
        for (int i = pos - 1; i >= 0; i--) {
            if (zahl[i] != 0) {
                return false;
            }
        }
        return true;
    }
    else if (pos == 0) {
        return true;
    }
    /*
    if ((unsigned int)pos != zahl.size() - 1) {
        for (unsigned int i = pos + 1; i < zahl.size(); i++) {
            if (zahl[i] != 0) {
                return false;
            }
        }
    }
    else if ((unsigned int)pos == zahl.size() - 1) {
        return true;
    }
    */
    return false;
}

void FunctionClass::Addition(vector<int> &zahl_1, vector<int> &zahl_2, const unsigned int base_int) {
    zahl_1.insert(zahl_1.begin(),0);
    zahl_2.insert(zahl_2.begin(),0);

    for (int i = zahl_1.size() - 1; i >= 0; i--) {
        zahl_1[i] += zahl_2[i];
        if ((unsigned int)zahl_1[i] >= base_int) {
            zahl_1[i - 1] += floor((double)zahl_1[i] / base_int);
            zahl_1[i] = zahl_1[i] % base_int;
        }
    }
}
void FunctionClass::Subtraktion(vector<int> &zahl_1, vector<int> &zahl_2, const unsigned int base_int) {
    for (int i = zahl_1.size() - 1; i >= 0; i--) {

        zahl_1[i] -= zahl_2[i];
        if (zahl_1[i] < 0) {
            zahl_1[i - 1] += floor((double)zahl_1[i] / base_int);
            zahl_1[i] = (zahl_1[i] * -1) % base_int;
        }
    }
}
int FunctionClass::MultDiv(vector<int> &erg_zahl, vector<int> &zahl_1, vector<int> &zahl_2, const unsigned int base_1, const unsigned int base_2, const unsigned int base, const char type) {
    unsigned int Numb1, Numb2, Numb, rest_int = 0;

    if (zahl_1.size() == 1) {
        zahl_1.insert(zahl_1.begin(),0);
        zahl_2.insert(zahl_2.begin(),0);
    }

    Numb1 = hornerschema(zahl_1, base_1);
    Numb2 = hornerschema(zahl_2, base_2);

    switch (type) {
        case '+':
            Numb = Numb1 + Numb2;
            break;
        case '-':
            Numb = Numb1 - Numb2;
            break;
        case '*':
            Numb = Numb1 * Numb2;
            break;
        case '/':
            rest_int = Numb1 % Numb2;
            Numb = (Numb1 - rest_int) / Numb2;
            break;
    }

    while (erg_zahl.size() != zahl_1.size()) {
        erg_zahl.push_back(0);
    }

    restemethode(erg_zahl, Numb, base);

    return rest_int;
}

void FunctionClass::Umwandlung(vector<int> &erg_zahl, string &erg) {
    for (int i = 0; i <= (int)erg_zahl.size(); i++) {
        if (is_end(erg_zahl, i) == false) {
            erg.insert(erg.end(),ziffer(erg_zahl[i]));
        }
    }
    /*
    for (int i = erg_zahl.size() - 1; i >= 0; i--) {
        if (is_end(erg_zahl, i, type2) == false) {
            erg.insert(erg.begin(),ziffer(erg_zahl[i]));
        }
    }
    */
}

unsigned int FunctionClass::hornerschema(vector <int> &zahl, const int base_int) {
    int numb = zahl[0];

    for (unsigned int i = 1; i < zahl.size(); i++) {
        if (numb != 0) {
            numb *= base_int;
        }
        numb += zahl[i];
    }

    return numb;
}
vector<int> FunctionClass::reverse(vector<int> vec) {
    vector<int> dummy;
    for (int i = vec.size() - 1; i >= 0; i--) {
        dummy.push_back(vec[i]);
    }
    return dummy;
}
void FunctionClass::restemethode(vector <int> &zahl, int numb, const unsigned int base_int) {
    for (int i = 0; numb != 0; i++) {
        zahl[i] = numb % base_int;
        numb = (numb - zahl[i]) / base_int;
    }
    zahl = reverse(zahl);
}

char FunctionClass::ziffer(unsigned int numb) {
    if (numb >= 0 && numb < 10) {
        return (char)(numb + 48);
    }
    else if (numb > 9 && numb < 36) {
        return (char)(numb + 55);
    }
    cout << "#ERROR AT FUNCTION ZIFFER#" << endl
         << "NUMB = " << numb << endl;
    return '#';
}

unsigned int FunctionClass::max_size_list (unsigned int base) {
    unsigned int max_lines;

    switch (base) {
            case 2:
                max_lines = 31;
                break;
            case 3:
                max_lines = 20;
                break;
            case 4:
                max_lines = 16;
                break;
            case 5:
                max_lines = 13;
                break;
            case 6:
                max_lines = 12;
                break;
            case 7:
                max_lines = 11;
                break;
            case 8:
            case 9:
                max_lines = 10;
                break;
            case 10:
            case 11:
                max_lines = 9;
                break;
            case 12:
            case 13:
            case 14:
                max_lines = 8;
                break;
            case 15:
            case 16:
            case 17:
            case 18:
            case 19:
            case 20:
            case 21:
                max_lines = 7;
                break;
            case 22:
            case 23:
            case 24:
            case 25:
            case 26:
            case 27:
            case 28:
            case 29:
            case 30:
            case 31:
            case 32:
            case 33:
            case 34:
            case 35:
            case 36:
                max_lines = 6;
                break;
        }

    return max_lines;
}
bool FunctionClass::is_str_nmb(string str) {

    for (unsigned int i = 0; i < str.size(); i++) {
        if (value(str[i]) > 9) {
            return false;
        }
    }

    return true;
}
void FunctionClass::error(string err) {
    if (err.empty()) {
        cout << "Ihre Eingabe ist ung" << ue << "ltig !" << endl;
        system("PAUSE");
    }
    else {
        cout << "Ihre Eingabe ist ung" << ue << "ltig !" << endl
             << err << endl;
        system("PAUSE");
    }
}

bool MainClass::menu() {
    FunctionClass fclass;

    base_1 = 0;
    base_2 = 0;
    base = 0;
    zahl1.clear();
    zahl2.clear();
    ergebnis_vec.clear();

    int rest;
    char type_char;
    bool error, error_second;

    string Zahl1_string, Zahl2_string, Ergebnis;
    string base_str, base1_str, base2_str;
    string eig_str, eig_str_2, choice_str;

    do {
        error = false;

        cout << "Was wollen Sie rechnen ?" << endl
             << "   Addieren        (+)" << endl
             << "   Subtrahieren    (-)" << endl
             << "   Multiplikation  (*)" << endl
             << "   Division        (/)" << endl
             << "Ihre Wahl : ";
            cin >> eig_str;
            cout << endl;


        if (eig_str.length() == 1) {
            if (eig_str[0] != '+' && eig_str[0] != '-' && eig_str[0] != '*' && eig_str[0] != '/') {
                fclass.error("");
                error = true;
            }
        }
        else {
            error = true;
        }
    }
    while (error == true);

    do {
        error = false;

        cout << "W" << ae << "hlen Sie das Zahlensystemkonstrukt aus : " << endl
             << "   Selbe Basis                    (A)" << endl
             << "   Selbe Basis, Ergebnis          (B)" << endl
             << "   entspricht w" << ae << "hlbaren System" << endl
             << "   Verschiedene Basen, Ergebnis   (C)" << endl
             << "   entspricht Zahlensystem Erster" << endl
             << "   Verschiedene Basen, Ergebnis   (D)" << endl
             << "   entspricht w" << ae << "hlbaren System" << endl
             << "Ihre Wahl : ";
        cin >> eig_str_2;
        cout << endl;

        if (eig_str_2.length() == 1) {

            switch((char)eig_str_2[0]) {
                case 'A':
                case 'a':
                    do {
                        error = false;
                        if (eig_str[0] == '+' || eig_str[0] == '-') {
                            cout << "Bitte geben Sie das Zahlensystem an (2-36) : ";
                            cin >> base_str;
                            cout << endl;

                            if (!fclass.is_str_nmb(base_str)) {
                                fclass.error("");
                                error = true;
                            }
                            else {
                                if (base_str.size() == 1) {
                                    base = fclass.value(base_str[0]);
                                }
                                else if (base_str.size() == 2) {
                                    base = 10 * fclass.value(base_str[0]);
                                    base += fclass.value(base_str[1]);
                                }
                                if (base < 2 || base > 36) {
                                    fclass.error("Bewegen Sie sich im Bereich 2-36 !");
                                    error = true;
                                }
                            }
                            type_char = 'B';
                        }
                        else if (eig_str[0] == '*' || eig_str[0] == '/') {
                            cout << "Bitte geben Sie das Zahlensystem an (2-16) : ";
                            cin >> base_str;
                            cout << endl;

                            if (!fclass.is_str_nmb(base_str)) {
                                fclass.error("");
                                error = true;
                            }
                            else {
                                if (base_str.size() == 1) {
                                    base = fclass.value(base_str[0]);
                                }
                                else if (base_str.size() == 2) {
                                    base = 10 * fclass.value(base_str[0]);
                                    base += fclass.value(base_str[1]);
                                }
                                if (base < 2 || base > 16) {
                                    fclass.error("Bewegen Sie sich im Bereich 2-16 !");
                                    error = true;
                                }
                            }

                            type_char = 'A';
                        }
                    }
                    while (error == true);

                    base_1 = base;
                    base_2 = base;
                    break;
                case 'B':
                case 'b':
                    type_char = 'A';
                    do {
                        error = false;
                        cout << "Bitte geben Sie das Zahlensystem an (2-16) : ";
                        cin >> base1_str;
                        cout << endl;

                        if (!fclass.is_str_nmb(base1_str)) {
                            fclass.error("");
                            error = true;
                        }
                        else {
                            if (base1_str.size() == 1) {
                                base_1 = fclass.value(base1_str[0]);
                            }
                            else if (base1_str.size() == 2) {
                                base_1 = 10 * fclass.value(base1_str[0]);
                                base_1 += fclass.value(base1_str[1]);
                            }
                            if (base_1 < 2 || base_1 > 16) {
                                fclass.error("Bewegen Sie sich im Bereich 2-16 !");
                                error = true;
                            }
                        }
                    }
                    while (error == true);
                    base_2 = base_1;

                    do {
                        error = false;
                        cout << "Bitte geben Sie die Zielbasis an (2-16) : ";
                        cin >> base_str;
                        cout << endl;

                        if (!fclass.is_str_nmb(base1_str)) {
                            fclass.error("");
                            error = true;
                        }
                        else {
                            if (base_str.size() == 1) {
                                base = fclass.value(base_str[0]);
                            }
                            else if (base_str.size() == 2) {
                                base = 10 * fclass.value(base_str[0]);
                                base += fclass.value(base_str[1]);
                            }
                            if (base < 2 || base > 16) {
                                fclass.error("Bewegen Sie sich im Bereich 2-16 !");
                                error = true;
                            }
                        }
                    }
                    while (error == true);
                    break;
                case 'C':
                case 'c':
                    type_char = 'A';
                    do {
                        error = false;
                        cout << "Bitte geben Sie die Basis der ersten Zahl an (2-16) : ";
                        cin >> base1_str;
                        cout << endl;

                        if (!fclass.is_str_nmb(base1_str)) {
                            fclass.error("");
                            error = true;
                        }
                        else {
                            if (base1_str.size() == 1) {
                                base_1 = fclass.value(base1_str[0]);
                            }
                            else if (base1_str.size() == 2) {
                                base_1 = 10 * fclass.value(base1_str[0]);
                                base_1 += fclass.value(base1_str[1]);
                            }
                            if (base_1 < 2 || base_1 > 16) {
                                fclass.error("Bewegen Sie sich im Bereich 2-16 !");
                                error = true;
                            }
                        }
                    }
                    while (error == true);

                    do {
                        error = false;
                        cout << "Bitte geben Sie die Basis der zweiten Zahl an (2-16) : ";
                        cin >> base2_str;
                        cout << endl;

                        if (!fclass.is_str_nmb(base2_str)) {
                            fclass.error("");
                            error = true;
                        }
                        else {
                            if (base2_str.size() == 1) {
                                base_2 = fclass.value(base2_str[0]);
                            }
                            else if (base2_str.size() == 2) {
                                base_2 = 10 * fclass.value(base2_str[0]);
                                base_2 += fclass.value(base2_str[1]);
                            }
                            if (base_2 < 2 || base_2 > 16) {
                                fclass.error("Bewegen Sie sich im Bereich 2-16 !");
                                error = true;
                            }
                        }
                    }
                    while (error == true);

                    base = base_1;
                    break;
                case 'D':
                case 'd':
                    type_char = 'A';
                    do {
                        error = false;
                        cout << "Bitte geben Sie die Basis der ersten Zahl an (2-16) : ";
                        cin >> base1_str;
                        cout << endl;

                        if (!fclass.is_str_nmb(base1_str)) {
                            fclass.error("");
                            error = true;
                        }
                        else {
                            if (base1_str.size() == 1) {
                                base_1 = fclass.value(base1_str[0]);
                            }
                            else if (base1_str.size() == 2) {
                                base_1 = 10 * fclass.value(base1_str[0]);
                                base_1 += fclass.value(base1_str[1]);
                            }
                            if (base_1 < 2 || base_1 > 16) {
                                fclass.error("Bewegen Sie sich im Bereich 2-16 !");
                                error = true;
                            }
                        }
                    }
                    while (error == true);

                    do {
                        error = false;
                        cout << "Bitte geben Sie die Basis der zweiten Zahl an (2-16) : ";
                        cin >> base2_str;
                        cout << endl;

                        if (!fclass.is_str_nmb(base2_str)) {
                            fclass.error("");
                            error = true;
                        }
                        else {
                            if (base2_str.size() == 1) {
                                base_2 = fclass.value(base2_str[0]);
                            }
                            else if (base2_str.size() == 2) {
                                base_2 = 10 * fclass.value(base2_str[0]);
                                base_2 += fclass.value(base2_str[1]);
                            }
                            if (base_2 < 2 || base_2 > 16) {
                                fclass.error("Bewegen Sie sich im Bereich 2-16 !");
                                error = true;
                            }
                        }
                    }
                    while (error == true);

                    do {
                        error = false;
                        cout << "Bitte geben Sie die Zielbasis an (2-16) : ";
                        cin >> base_str;
                        cout << endl;

                        if (!fclass.is_str_nmb(base_str)) {
                            fclass.error("");
                            error = true;
                        }
                        else {
                            if (base_str.size() == 1) {
                                base = fclass.value(base_str[0]);
                            }
                            else if (base_str.size() == 2) {
                                base = 10 * fclass.value(base_str[0]);
                                base += fclass.value(base_str[1]);
                            }
                            if (base < 2 || base > 16) {
                                fclass.error("Bewegen Sie sich im Bereich 2-16 !");
                                error = true;
                            }
                        }
                    }
                    while (error == true);
                    break;
                default:
                    fclass.error("");
                    error = true;
                    break;
            }
        }
        else {
            error = true;
        }
    }
    while (error == true);

    do {
        zahl1.clear();
        zahl2.clear();
        error_second = false;

        do {
            zahl1.clear();
            error = false;
            cout << "Erste Zahl : ";
            cin >> Zahl1_string;

            if (type_char == 'A' && Zahl1_string.length() > fclass.max_size_list(base_1)) {
                system("CLS");
                cout << "Ihre Eingabe ist ung" << ue << "ltig !" << endl
                     << "Eine Zahl darf nicht mehr als " << fclass.max_size_list(base_1) << " Zeilen haben !" << endl;
                error = true;
            }
            else {
                error = fclass.push_in(Zahl1_string, zahl1, base_1);
            }
        }
        while (error == true);

        do {
            zahl2.clear();
            error = false;
            cout << "Zweite Zahl : ";
            cin >> Zahl2_string;

            if (type_char == 'A' && Zahl2_string.length() > fclass.max_size_list(base_2)) {
                system("CLS");
                cout << "Ihre Eingabe ist ung" << ue << "ltig !" << endl
                     << "Eine Zahl darf nicht mehr als " << fclass.max_size_list(base_2) << " Zeilen haben !" << endl;
                error = true;
            }
            else {
                error = fclass.push_in(Zahl2_string, zahl2, base_2);
            }
        }
        while (error == true);

        switch (eig_str[0]) {
            case '+':
                fclass.equal_size(zahl1,zahl2);
                if (base_1 == base_2 && base_1 == base) {
                    type_char = 'B';
                    fclass.Addition(zahl1, zahl2, base_1);
                    rest = 0;
                }
                else {
                    type_char = 'A';
                    rest = fclass.MultDiv(ergebnis_vec, zahl1, zahl2, base_1, base_2, base, eig_str[0]);
                }
                break;
            case '-':
                if (fclass.is_zahl_bigger(zahl2, zahl1, base_2, base_1) == true) {
                    system("CLS");
                    cout << "Erste Zahl ist kleiner als zweite Zahl !" << endl
                         << "Bitte verwenden Sie in der Subtraktion einen kleineren Subtrahenden !" << endl
                         << "Der Subtrahend darf nicht gr" << oe << ss << "er sein als der Minuend" << endl;
                    error_second = true;
                }
                fclass.equal_size(zahl1,zahl2);
                if (base_1 == base_2 && base_1 == base) {
                    type_char = 'B';
                    fclass.Subtraktion(zahl1, zahl2, base_1);
                    rest = 0;
                }
                else {
                    type_char = 'A';
                    rest = fclass.MultDiv(ergebnis_vec, zahl1, zahl2, base_1, base_2, base, eig_str[0]);
                }
                break;
            case '*':
            case '/':
                type_char = 'A';
                fclass.equal_size(zahl1,zahl2);
                rest = fclass.MultDiv(ergebnis_vec, zahl1, zahl2, base_1, base_2, base, eig_str[0]);
                break;
        }
    }
    while (error_second == true);

    if (base_1 == base_2 && base_1 == base) {
        fclass.Umwandlung(zahl1, Ergebnis);
    }
    else {
        fclass.Umwandlung(ergebnis_vec, Ergebnis);
    }

    if (Ergebnis.size() == 0) {
        Ergebnis = "0";
    }

    if (rest != 0) {
        cout << "Ihre Rechnung lautet : ( (" << Zahl1_string << ")" << base_1 << " " << eig_str[0] << " (" << Zahl2_string << ")" << base_2 << " = (" << Ergebnis << ")" << base << " Rest = " << rest << " )" << endl << endl;
    }
    else {
        cout << "Ihre Rechnung lautet : ( (" << Zahl1_string << ")" << base_1 << " " << eig_str[0] << " (" << Zahl2_string << ")" << base_2 << " = (" << Ergebnis << ")" << base << " )" << endl << endl;
    }

    do {
        error = false;
        cout << "M" << oe << "chten Sie erneut starten (j/n) : ";
        cin >> choice_str;

        if (choice_str.length() == 1) {
            switch ((char)choice_str[0]) {
                case 'j':
                    system("PAUSE");
                    system("CLS");
                    return true;
                    break;
                case 'n':
                    error = false;
                    break;
                default:
                    fclass.error("");
                    error = true;
                    break;
            }
        }
        else {
            error = true;
        }
    }
    while (error == true);

    cout << endl;

    system("PAUSE");
    system("CLS");

    return false;
}
bool MainClass::menu2() {
    FunctionClass fclass;
    base_1 = 0;
    base = 0;
    zahl1.clear();
    ergebnis_vec.clear();

    string zahl, ergebnis, choice_str, base_str, base1_str;

    bool error = false;

    do {
        error = false;

        cout << "Bitte nennen Sie die Basis der umzurechnenden Zahl (2-36) : ";
        cin >> base1_str;

        if (!fclass.is_str_nmb(base1_str)) {
            fclass.error("");
            error = true;
        }
        else {
            if (base1_str.size() == 1) {
                base_1 = fclass.value(base1_str[0]);
            }
            else if (base1_str.size() == 2) {
                base_1 = 10 * fclass.value(base1_str[0]);
                base_1 += fclass.value(base1_str[1]);
            }
            if (base_1 < 2 || base_1 > 36) {
                fclass.error("Bewegen Sie sich im Bereich 2-36 !");
                error = true;
            }
        }
    }
    while(error == true);

    do {
        error = false;

        cout << "Bitte nennen Sie die Zielbasis (2-36) : ";
        cin >> base_str;

        if (!fclass.is_str_nmb(base_str)) {
            fclass.error("");
            error = true;
        }
        else {
            if (base_str.size() == 1) {
                base = fclass.value(base_str[0]);
            }
            else if (base_str.size() == 2) {
                base = 10 * fclass.value(base_str[0]);
                base += fclass.value(base_str[1]);
            }
            if (base < 2 || base > 36) {
                fclass.error("Bewegen Sie sich im Bereich 2-36 !");
                error = true;
            }
        }
    }
    while (error == true);

    do {
        error = false;

        cout << "Bitte nennen Sie die umzurechnende Zahl (max. " << fclass.max_size_list(base_1) << " Stellen) : ";
        cin >> zahl;

        if (zahl.length() > fclass.max_size_list(base_1)) {
            system("CLS");
            cout << "Ihre Eingabe ist ung" << ue << "ltig !" << endl
                 << "Eine Zahl darf nicht mehr als " << fclass.max_size_list(base_1) << " Zeilen haben !" << endl;
            error = true;
        }
        else {
            error = fclass.push_in(zahl, zahl1, base_1);
        }
    }
    while (error == true);

    if (zahl1.size() == 1) {
        zahl1.insert(zahl1.begin(),0);
    }

    unsigned int dummy = fclass.hornerschema(zahl1, base_1);

    ergebnis_vec.push_back(0);
    while (ergebnis_vec.size() != zahl1.size()) {
        ergebnis_vec.insert(ergebnis_vec.begin(), 0);
    }

    fclass.restemethode(ergebnis_vec,dummy, base);
    ergebnis_vec = fclass.reverse(ergebnis_vec);
    fclass.Umwandlung(ergebnis_vec,ergebnis);

    cout << "( " << zahl << " )" << base_1 << " --> ( " << ergebnis << " )" << base << endl;

    do {
        error = false;
        cout << "M" << oe << "chten Sie erneut starten (j/n) : ";
        cin >> choice_str;

        if (choice_str.length() == 1) {
            switch ((char)choice_str[0]) {
                case 'j':
                    system("PAUSE");
                    system("CLS");
                    return true;
                    break;
                case 'n':
                    error = false;
                    break;
                default:
                    cout << "Ihre Eingabe ist ung" << ue << "ltig !" << endl;
                    system("PAUSE");
                    system("CLS");
                    error = true;
                    break;
            }
        }
        else {
            cout << "Ihre Eingabe ist ung" << ue << "ltig !" << endl;
            system("PAUSE");
            system("CLS");
            error = true;
        }
    }
    while (error == true);

    cout << endl;

    system("PAUSE");
    system("CLS");

    return false;
}
