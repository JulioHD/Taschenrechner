/*
    Projekt:            Taschenrechner
    Datei:              FunctionClass.hpp
    Autor:              <ommitted>
    Erstellungsdatum:   27.11.2018
    Letzte Änderung:    27.01.2019
    Beschreibung:       Header Datei die die FunctionClass enthält welche alle Funktionen des
                        Programmes umfasssen.
*/

#ifndef _FUNCTIONCLASS_HPP_INCLUDED
#define _FUNCTIONCLASS_HPP_INCLUDED

#include "MainClass.hpp"

class FunctionClass {
    friend class MainClass;
    private:
        bool push_in(string, vector<int> &, const unsigned int);
        /** \brief Wandelt mithilfe der Funktion "asciitoint" einen String in einen Vektor mit Integer Werten um.
         *
         * \param string
         * \param vector<int>
         * \param const int
         * \return bool
         *
         */

        bool is_zahl_bigger(vector<int> &, vector<int> &, const unsigned int, const unsigned int);
        /** \brief  Prüft ob angegebener Vektor größer ist als der zweite angegebene Vektor.
         *          Dabei wird berücksichtigt das der Vektor eine Zahl aus einem beliebigen Zahlensystem beinhaltet.
         *          Er gibt als bool zurück ob der erste Vektor eine größere Zahl beinhaltet.
         *
         * \param vector<int> &
         * \param vector<int> &
         * \param const unsigned int
         * \param const unsigned int
         * \return bool
         *
         */

        unsigned int value(char);
        /** \brief Wandelt Ascii Wert in eine Zahl ein.
         *         Gibt Zahl zurück oder -1 was bedeutet das der Ascii Code auf keine Ziffer und keinen Buchstaben hindeutet.
         *
         * \param char
         * \return unsigned int
         *
         */

        void equal_size(vector<int> &, vector<int> &);
        /** \brief Passt Größe der beiden übergebenen Vektoren aneinander an.
         *
         * \param vector<int> &
         * \param vector<int> &
         * \return void
         *
         */

        bool is_end(vector<int> &, int);
        /** \brief Benötigt integer als Angabe der momentanen Position im angegebenen Vektor.
         *         Gibt als bool zurück ob die Position die letzte nennenswerte Position im Vektor ist.
         *         Wird benutzt um nicht nennenswerte Nullen zu erkennen.
         *
         * \param vector<int> &
         * \param int
         * \return bool
         *
         */


        void Addition(vector<int> &, vector<int> &, const unsigned int);
        /** \brief Addiert übergebene Vektoren. Kann nur mit gemeinsamer Basis rechnen
         *         Wird nur im Fall benutzt das Basis beider Zahlen dieselbe ist.
         *         Anders als in der Funktion "MultDiv" wird hier nicht mit der Restemethode oder Hornerschema gearbeitet.
         *         Ebenfalls wird das Ergebnis nicht in einem seperaten Vektor gespeichert, sondern im ersten Zahlenvektor.
         *         Die Funktion beruht auf einem Zählsystem, was ihm die Möglichkeit bietet mit sehr großen Zahlen zu arbeiten.
         *
         * \param vector<int> &
         * \param vector<int> &
         * \param const unsigned int
         * \return void
         *
         */

        void Subtraktion(vector<int> &, vector<int> &, const unsigned int);
        /** \brief Subtrahiert übergebene Vektoren. Kann nur mit gemeinsamer Basis rechnen.
         *         Wird nur im Fall benutzt das Basis beider Zahlen dieselbe ist.
         *         Anders als in der Funktion "MultDiv" wird hier nicht mit der Restemethode oder Hornerschema gearbeitet.
         *         Ebenfalls wird das Ergebnis nicht in einem seperaten Vektor gespeichert, sondern im ersten Zahlenvektor.
         *         Die Funktion beruht auf einem Zählsystem, was ihm die Möglichkeit bietet mit sehr großen Zahlen zu arbeiten.
         *
         * \param vector<int> &
         * \param vector<int> &
         * \param const unsigned int
         * \return void
         *
         */

        int MultDiv(vector<int> &, vector<int> &, vector<int> &, const unsigned int, const unsigned int, const unsigned int, const char);
        /** \brief Kann übergebene Vektoren addieren, subtrahieren, multiplizieren oder dividieren.
         *         Findet nur Anwendung in der Multiplikation und Division.
         *         Sonderfall in der Addition und Subtraktion falls Basen der Zahlen verschieden sind.
         *         Bei allen Rechenarten dieser Funktion kommen die Funktionen "HornerSchema" und "ResteMethode" zum Einsatz.
         *         Die Division findet als Ganzzahldivision statt.
         *         Als Eingabe wird die gewünschte Rechenart als char erwartet.
         *         Gibt Rest zurück, wenn die Rechenart nicht Division ist gibt die Funktion 0 zurück.
         *
         * \param vector<int> &
         * \param vector<int> &
         * \param vector<int> &
         * \param const unsigned int
         * \param const unsigned int
         * \param const unsigned int
         * \param const char
         * \return int
         *
         */


        void Umwandlung(vector<int> &, string &);
        /** \brief Wandelt übergebenen Vector in einen String um welcher das Ergebnis der vorheringen Rechnung beinhaltet.
         *         Benötigt char welcher angibt um welche Rechenart sich handelt um das Ergebnis korrekt zu sortieren.
         *
         * \param vector<int> &
         * \param string&
         * \return void
         *
         */


        unsigned int hornerschema(vector<int> &, const int);
        /** \brief Wandelt Vektor der eine Zahl aus einem beliebigen Zahlensystem beinhaltet in einen Integer um.
         *
         * \param vector <int> &
         * \param vector <int> &
         * \return unsigned int
         *
         */

        vector<int> reverse(vector<int>);
        /** \brief Dreht Werte des übergebenen Vektors um und gibt den umgedrehten Vektor zurück.
         *         Wird nur im Umrechner (menu2) verwendet.
         *
         * \param vector<int>
         * \return vector<int>
         *
         */


        void restemethode(vector<int> &, int, const unsigned int);
        /** \brief Wandelt Integer in eine Zahl aus einem beliebigen Zahlensystem um und speichert die Zahl in den Vektor "Zahl1".
         *
         * \param vector<int> &
         * \param int
         * \param const unsigned int
         * \return void
         *
         */

        char ziffer(unsigned int);
        /** \brief Wandelt Zahl in Asciicode um.
         *
         * \param unsigned int
         * \return char
         *
         */

        unsigned int max_size_list(unsigned int);
        /** \brief Enthält eine Tabelle welche Basen maximale Zeilenlängen zuordnet.
         *         Wird verwendet um Fehler zu vermeiden, die mit der maximalen Größe eines Integers zu tun haben.
         *
         * \param unsigned int
         * \return unsigned int
         *
         */

         bool is_str_nmb(string);
         /** \brief Prüft ob string nur Zahlen enthält.
          *
          * \param string
          * \return bool
          *
          */

          void error(string);
          /** \brief Gibt Fehlermeldung aus.
           *         Übergebener string wird ausgegeben.
           *
           * \param string
           * \return void
           *
           */
};

#endif // _FUNCTIONCLASS_HPP_INCLUDED
