#include <iostream>
#include <string>
#include <tuple>

#include "Labyrinth.h"

using namespace std ;

int main()
{
	//Schleife, die ermoeglicht, ein neues Labyrinth einzufuegen ohne das Programm neu zu starten
	while (true)
	{
		Labyrinth labyrinth;
		//Initialisierung von Variablen
		int anzahl_ebenen, anzahl_reihen, anzahl_spalten;
		pair<int, int> ende;
		//Einlesen der Dimensionen
		cin >> anzahl_ebenen;
		ende.first = anzahl_ebenen;
		cin >> anzahl_reihen;
		ende.second = anzahl_reihen;
		cin >> anzahl_spalten;
		//Einzelnes getline um die Zeile abzuschliessen
		string zeile;
		getline(cin, zeile);
		//Ueberpruefen ob die Eingabe den erlaubten Dimensionen entspricht
		if (anzahl_ebenen >= 30 || anzahl_reihen >= 30 || anzahl_spalten >= 30) {
			cout << "Das Labyrinth darf in keine Dimension groesser als 30 sein!" << endl;
			break;
		}
		//Initialiserung des Labyrinths
		labyrinth.dimensionen_bestimmen(anzahl_ebenen, anzahl_reihen, anzahl_spalten);
		//Fortschritt wird gespeichert um zu erkennen, welche Eingabe die letzte ist
		pair<int, int> fortschritt;
		//Schleife, die laeuft bis Ziel erreicht ist oder kein Weg mehr moeglich ist
		while (true)
		{
			//Wenn Eingabe beendet ist den Weg aus dem Labyrinth suchen
			if (fortschritt.first + 1 >= ende.first && fortschritt.second >= ende.second) {
				//eigentlicher Algorithmus, gibt Laenge des kuerzesten Weges zurueck oder 0 wenn es keinen Weg gibt
				int kuerzester_weg = labyrinth.entkomme_labyrinth();
				//Ausgabe des Ergebnisses
				if (kuerzester_weg > 0) {
					cout << "Entkommen in " << kuerzester_weg << " Minute(n)!" << endl;
					break;
				} else {
					cout << "Gefangen :-(" << endl;
					break;
				}
			}
			//Wenn Eingabe noch nicht beendet ist die naechste Zeile einlesen und dem Labyrinth hinzufuegen
			getline(cin, zeile);
			fortschritt = labyrinth.erstellen(fortschritt, zeile);
		}  // while ( true )
	}
	return 0;

}  // main()