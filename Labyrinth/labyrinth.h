#ifndef LABYRINTH_H
#define LABYRINTH_H

#include <string>

using namespace std;

class Labyrinth
{
	char _labyrinth[30][30][30];
	char aktuelle_positionen[30][30][30];
	char naechste_positionen[30][30][30];
	unsigned int _L = NULL, _C = NULL, _R = NULL;

public:

	Labyrinth();
	~Labyrinth();

	void dimensionen_bestimmen(int anzahl_ebenen, int anzahl_reihen, int anzahl_spalten);
	bool pruefe_gefangen();
	void finde_startpunkt();
	bool naechster_schritt();
	bool pruefe_nachbarn(unsigned int l, unsigned int r, unsigned int c);
	pair<int, int> erstellen( pair<int, int> fortschritt, string const& zeile);
	int entkomme_labyrinth();

};

#endif //LABYRINTH_H
