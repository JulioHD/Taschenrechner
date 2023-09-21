/*
    Projekt:            Taschenrechner
    Datei:              MainClass.hpp
    Autor:              <ommitted>
    Erstellungsdatum:   27.11.2018
    Letzte �nderung:    27.01.2019
    Beschreibung:       Header Datei die die MainClass enth�lt.
                        Ebenfalls inkludiert dieser Header alle genutzten Bibliotheken.
*/

#ifndef _MAINCLASS_HPP_INCLUDED
#define _MAINCLASS_HPP_INCLUDED

#include <iostream>
#include <cstdlib>
#include <vector>
#include <math.h>

using namespace std;

const unsigned char ss = static_cast<unsigned char>(225);
const unsigned char oe = static_cast<unsigned char>(148);
const unsigned char ue = static_cast<unsigned char>(129);
const unsigned char ae = static_cast<unsigned char>(132);

class MainClass {
    public:
        void open_menu();
        /** \brief L�sst den User die Entscheidung ob er eine Zahl umrechnen will oder ob er Rechnungen durchf�hren m�chte.
         *         Kann die Funktion "menu" oder "menu2" nach Wahl ausf�hren und bei Bedarf wiederholen.
         *
         * \return void
         *
         */
    protected:
        bool menu();
        /** \brief Funktioniert als Kopf des Taschenrechners.
         *         Fordert den User auf Eingaben zu machen.
         *         Bei fehlerhafter Eingabe wird der User aufgefordert die Eingabe korrekt zu wiederholen.
         *         Die Funktion kann einen bool zur�ckgeben um die Funktion neuzustarten oder das Programm zu beenden.
         *
         * \return bool
         *
         */
        bool menu2();
        /** \brief Funktioniert als Kopf des Umrechners, funktionsweise �hnlich der "menu" Funktion.
         *         Fordert den User auf Eingaben zu machen.
         *         Bei fehlerhafter Eingabe wird der User aufgefordert die Eingabe korrekt zu wiederholen.
         *         Die Funktion kann einen bool zur�ckgeben um die Funktion neuzustarten oder das Programm zu beenden.
         *
         * \return bool
         *
         */
    private:
        vector<int> ergebnis_vec;
        vector<int> zahl1;
        vector<int> zahl2;
        unsigned int base_1, base_2, base;
};

#endif // _MAINCLASS_HPP_INCLUDED
