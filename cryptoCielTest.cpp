// RsaCiel.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include "RsaGestion.h"
#include "Hashgestion.h"
#include "AesGestion.h"

using namespace std;

int main()
{
	HashGestion LM;
	string monMessageHash = "Super message superchouette";
	cout << LM.CalculateSHA256(monMessageHash) << endl;

	cout << "Fichier text :" << endl;
	cout << LM.CalculateFileSHA256("fichier.txt") << endl;

	cout << "-----------------------------------" << endl;

	cout << "Fichier binaire :" << endl;
	cout << LM.CalculateFileSHA256("binaire.txt") << endl;

}


