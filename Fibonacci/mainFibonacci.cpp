#include <iostream>
#include <windows.h>
#include "fibonacci.h"
using namespace std;

int main() {
	
	//Umlaute in Konsole ermoeglichen
	SetConsoleOutputCP(1252);
	SetConsoleCP(1252);

	//permanente Schleife
	while (true)
	{
		//Input wird gespeichert
		int eingabe;
		cin >> eingabe;

		//Falls Input in dem vorgegebenen Bereich liegt wird die Fibonacci Zahl berechnet
		if (eingabe >= 0 && eingabe <= 5000) {
			berechne_Fibonacci(eingabe);
		} else {
			cout << "Eingabe muss eine natürlich Zahl kleiner gleich 5000 sein!" << endl;
		}

	}  // while ( true )

}