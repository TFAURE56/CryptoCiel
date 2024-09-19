// RsaCiel.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include "RsaGestion.h"
#include "Hashgestion.h"
#include "AesGestion.h"

int main()
{
	HashGestion LM;
	std::string monMessageHash = "Super message superchouette";
	std::cout << LM.CalculateSHA256(monMessageHash) << std::endl;

	/**
	 * \brief Generation d'une classe de gestion AES
	 * 
	 * \return 
	 */
	AesGestion aesGestion;
	aesGestion.GenerateAESKey();

	//Sauvegarde la clef AES dans un fichier
	aesGestion.SaveAESKeyToFile("clefAES.txt");

	//Chargement de la clef AES depuis un fichier
	aesGestion.LoadAESKeyFromFile("clefAES.txt");

	//Chiffre un message
	aesGestion.EncryptFileAES256("messageDeBase.txt", "messageChiffre.txt");

	//Dechiffre le message
	aesGestion.DecryptFileAES256("messageChiffre.txt", "messageDechiffre.txt");

	std::cout << LM.CalculateFileSHA256("./messageDechiffre.txt") << std::endl;

}


