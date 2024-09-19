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

	/**
	 * \brief Chiffrer string avec la clef publique
	 * 
	 * \return 
	 */
	string texteChiffrer = "Texte a chiffrer";

	string texteChiffre = RsaGestion.chiffrementRsa(texteChiffrer);
	cout << "Texte chiffrer : " << texteChiffre << endl;

	/**
	* \brief D?chiffrer string avec la clef privee
	*
	* \return
	*/
	string texteDechiffre = RsaGestion.dechiffrementRsa(texteChiffre);
	cout << "Texte dechiffre : " << texteDechiffre << endl;

	return 0;
}



