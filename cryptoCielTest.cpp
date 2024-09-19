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
	 * \brief création variable pour generation clefs RSA
	 *
	 * \return
	 */

	string clefPublique = "PublicKey.pem";
	string clefPrivee = "PrivateKey.pem";

	/**
	 * \brief Generation d'une paire de clefs (public et privee)
	 *
	 * \return
	 */
	RsaGestion.generationClef(clefPublique, clefPrivee, 1028);

	return 0;
}



