#include "Labyrinth.h"
#include <algorithm>

//Konstruktor
Labyrinth::Labyrinth()
{
	for (size_t l = 0; l < 30; l++)
	{
		for (size_t r = 0; r < 30; r++)
		{
			for (size_t c = 0; c < 30; c++)
			{
				_labyrinth[l][r][c] = NULL;
				aktuelle_positionen[l][r][c] = NULL;
				naechste_positionen[l][r][c] = NULL;			}
		}
	}
}
//Destruktor
	Labyrinth::~Labyrinth()
	{
		for (size_t l = 0; l < _L; l++)
		{
			for (size_t r = 0; r < _R; r++)
			{
				for (size_t c = 0; c < _C; c++)
				{
					_labyrinth[l][r][c] = NULL;
				}
			}
		}
	}
	//Startpunkt suchen und auf "aktuell"(A) stellen
	void Labyrinth::finde_startpunkt()
	{
		for (size_t l = 0; l < _L; l++)
		{
			for (size_t r = 0; r < _R; r++)
			{
				for (size_t c = 0; c < _C; c++)
				{
					if (_labyrinth[l][r][c] == 'S')
						aktuelle_positionen[l][r][c] = 'A';
				}
			}
		}
	} // Labyrinth::finde_startpunkt()

	//prueft ob noch ein aktives Feld vorhanden ist, wenn nicht gibt es keinen Weg, gibt zurueck, dass man gefangen ist
	bool Labyrinth::pruefe_gefangen()
	{
		for (size_t l = 0; l < _L; l++)
		{
			for (size_t r = 0; r < _R; r++)
			{
				for (size_t c = 0; c < _C; c++)
				{
					if (aktuelle_positionen[l][r][c] == 'A')
						return false;
				}
			}
		}
		return true;
	} // Labyrinth::pruefe_gefangen()

	//fuehrt den naechsten Schritt aus, ueberprueft fuer jedes Feld, ob Nachbarn vorhanden sind, die als weiterer Weg in Frage kommen
	bool Labyrinth::naechster_schritt()
	{
		//ueberprueft fuer jedes aktive Feld alle Nachbarn, gibt true zurueck wenn das Ziel erreicht wurd
		for (size_t l = 0; l < _L; l++)
		{
			for (size_t r = 0; r < _R; r++)
			{
				for (size_t c = 0; c < _C; c++)
				{
					if (aktuelle_positionen[l][r][c] == 'A') {
						bool ziel_erreicht = pruefe_nachbarn(l, r, c);
						if (ziel_erreicht == true) {
							return true;
						}
					}
					
				}
			}
		}
		//alle aktuellen Felder aus dem Schritt werden als Steine markiert, weil diese fuer den restlichen Algorithmus nicht mehr bentutzt werden duerfen
		for (size_t l = 0; l < _L; l++)
		{
			for (size_t r = 0; r < _R; r++)
			{
				for (size_t c = 0; c < _C; c++)
				{
					if (aktuelle_positionen[l][r][c] == 'A') {
						_labyrinth[l][r][c] = '#';
						aktuelle_positionen[l][r][c] = NULL;
					}

				}
			}
		}
		//alle gefundenen Felder mit moeglichem weiteren Weg werden als neue aktuelle Felder markiert
		for (size_t l = 0; l < _L; l++)
		{
			for (size_t r = 0; r < _R; r++)
			{
				for (size_t c = 0; c < _C; c++)
				{
					if (naechste_positionen[l][r][c] == 'A') {
						naechste_positionen[l][r][c] = NULL;
						aktuelle_positionen[l][r][c] = 'A';
					}
				}
			}
		}
		return false;
	} // Labyrinth::naechster_schritt()

	//ueberprueft fuer jedes Feld, ob Nachbarn vorhanden sind, die als weiterer Weg in Frage kommen
	//markiert moegliche Wege als "aktuell" (A), gibt true zurueck wenn das Ziel erreicht wurde
	bool Labyrinth::pruefe_nachbarn(unsigned int l, unsigned int r, unsigned int c)
	{
		//Oben
		if (l > 0) {
			if (_labyrinth[l - 1][r][c] == '.') {
				naechste_positionen[l - 1][r][c] = 'A';
			}
			if (_labyrinth[l - 1][r][c] == 'E') {
				return true;
			}
		}
		//Unten
		if (l < (_L-1)) {
			if (_labyrinth[l + 1][r][c] == '.') {
				naechste_positionen[l + 1][r][c] = 'A';
			}
			if (_labyrinth[l + 1][r][c] == 'E') {
				return true;
			}
		}
		//Norden
		if (r > 0) {
			if (_labyrinth[l][r - 1][c] == '.') {
				naechste_positionen[l][r - 1][c] = 'A';
			}
			if (_labyrinth[l][r - 1][c] == 'E') {
				return true;
			}
		}
		//Sueden
		if (r < (_R - 1)) {
			if (_labyrinth[l][r + 1][c] == '.') {
				naechste_positionen[l][r + 1][c] = 'A';
			}
			if (_labyrinth[l][r + 1][c] == 'E') {
				return true;
			}
		}
		//Westen
		if (c > 0) {
			if (_labyrinth[l][r][c - 1] == '.') {
				naechste_positionen[l][r][c - 1] = 'A';
			}
			if (_labyrinth[l][r][c - 1] == 'E') {
				return true;
			}
		}
		//Osten
		if (c < (_C - 1)) {
			if (_labyrinth[l][r][c + 1] == '.') {
				naechste_positionen[l][r][c + 1] = 'A';
			}
			if (_labyrinth[l][r][c + 1] == 'E') {
				return true;
			}
		}
		return false;
	} // Labyrinth::pruefe_nachbarn()

	//bestimmt die Dimensionen, die fuer den Algorithmus relevant sind
	void Labyrinth::dimensionen_bestimmen(int anzahl_ebenen, int anzahl_reihen, int anzahl_spalten)
	{
		_L = anzahl_ebenen;
		_R = anzahl_reihen;
		_C = anzahl_spalten;
	} // Labyrinth::Labyrinth()

	//schreibt die Labyrinth Quader in die _labyrinth Matrix, gibt den Fortschritt zurueck, je nachdem ob eine neue Zeile eingegeben wurde 
	//oder eine Leerzeile, was bedeutet, dass eine neue Ebene startet
	pair<int, int> Labyrinth::erstellen(pair<int, int> fortschritt, string const& zeile)
	{	
		if (zeile != " ") {
			for (size_t i = 0; i < size(zeile); i++) {
				_labyrinth[fortschritt.first][fortschritt.second][i] = zeile[i];
			}
			fortschritt.second = fortschritt.second + 1;
		} else {
			fortschritt.first = fortschritt.first + 1;
			fortschritt.second = 0;
		}
		return fortschritt;
	} // Labyrinth::erstellen()

	//Fuehrt die einzelnen Algorithmen aus, zaehlt wieviele Schritte benoetigt wurden und gibt diese zurueck (0 falls kein Weg gefunden wurde)
	int Labyrinth::entkomme_labyrinth()
	{
		finde_startpunkt();
		int anzahl_schritte = 0;
		bool ziel_erreicht = false;
		while (ziel_erreicht == false) {
			ziel_erreicht = naechster_schritt();
			anzahl_schritte++;
			if (pruefe_gefangen() == true)
				return 0;
		}
		return anzahl_schritte;
	} // Labyrinth::entkomme_labyrinth()