// RsaCiel.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include "RsaGestion.h"
#include "Hashgestion.h"
#include "AesGestion.h"

using namespace std;

int main()
{
	/**
	 * \brief Constructeur de la classe RsaGestion
	 *
	 * \return
	 */
	RsaGestion RsaGestion;

	/**
	 * \brief Charger la clef a partir du fichier
	 * 
	 * \return 
	 */
	RsaGestion.chargementClefs("PublicKey.pem", "PrivateKey.pem");

	/**
	 * \brief chiffrer text dans un fichier
	 * 
	 * \return 
	 */
	RsaGestion.chiffreDansFichier("T'es bete Leo", "donnees_chiffrees.txt");

	/**
	 * \brief Dechiffrer fichier et save dans un autre fichier
	 * 
	 * \return 
	 */
	RsaGestion.dechiffrementFichier("donnees_chiffrees.txt", "donnees_dechiffrees.txt", 1);


	return 0;
}



