#include <iostream>
#include "fibonacci.h"

using namespace std;

void berechne_Fibonacci(int eingabe)
{
    //Die maximale Anzahl an Stellen entspricht den Dezimalstellen der 5000. Fibonacci Zahl
    const int max_Stellen = 1045;
    //Zwei leere Arrays werden initialisiert, die jeweils eine bis zu 1045 stellige Zahl darstellen
    int f0[max_Stellen] = { 0 };
    int f1[max_Stellen] = { 0 };
    //der zweite Array wird auf Wert 1 gesetzt, da er die erste Fibonacci Zahl ist
    f1[max_Stellen-1] = 1;
    //leeres Array, in das die jeweils nächste Fibonacci Zahl gespeichert wird, wird initialisiert
    int fib[max_Stellen] = { 0 };
    //temporaerer Integer für Ergebnis der Addition.
    int temp_Ergebnis;
    //Boolean zur Überprüfung ob bei Addition ein Uebertrag entsteht
    bool uebertrag = false;
    //Falls Input kleiner gleich 1 ist wird der Input ausgegeben
    if (eingabe <= 1) {
        cout << "Die Fibonacci Zahl für " << eingabe << " ist: " << eingabe << endl;
    } else {
        //Dem Input entsprechende Anzahl an Fibonacci Iterationen
        for (size_t i = 1; i < eingabe; i++) {
            //Addition der beiden in den Arrays gespeicherten Zahlen
            for (int j = (max_Stellen-1); j >= 0; j--) {
                temp_Ergebnis = f0[j] + f1[j];
                //Falls bei der letzten Addition ein Uebertrag entstanden ist wird dieser zusaetzlich addiert
                if (uebertrag == true) {
                    temp_Ergebnis++;
                }
                //Falls Addition der beiden Ziffern groesser als 9 ist wird 10 subtrahiert und als Uebertrag gemerkt
                if (temp_Ergebnis > 9) {
                    uebertrag = true;
                    temp_Ergebnis = temp_Ergebnis - 10;
                }
                else {
                    uebertrag = false;
                }
                //Ergebnis wird in der jeweiligen Dezimalstelle gespeichert
                fib[j] = temp_Ergebnis;
            }
            //Die Zahlen werden fuer den naechsten Schritt ueberspeichert
            for (size_t j = 0; j < max_Stellen; j++)
                f0[j] = f1[j];
            for (size_t j = 0; j < max_Stellen; j++)
                f1[j] = fib[j];
        }
        //erste Stelle, die ungleich 0 ist, wird gesucht, da dort die eigentliche Zahl beginnt
        int erste_Dezimalstelle = distance(begin(fib), find_if(begin(fib), end(fib), [](auto x) { return x != 0; }));
        //Fibonacci Zahl wird ausgegeben
        cout << "Die Fibonacci Zahl für " << eingabe << " ist: ";
        for (size_t i = erste_Dezimalstelle; i < max_Stellen; i++)
            cout << fib[i]; 
        cout << endl;
    }
}
