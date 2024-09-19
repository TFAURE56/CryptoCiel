/*****************************************************************//**
 * \file   HashGestion.h
 * \brief  Classe permettant de faire du SHA256 sur des fichiers ou des chaines de caractères
 * 
 * \author Pierre
 * \date   July 2024
 *********************************************************************/
#pragma once

#include <iostream>
#include <sha.h>
#include <hex.h>
#include <fstream>


class HashGestion
{

public : 

	

	HashGestion();
	~HashGestion();

	std::string CalculateSHA256(const std::string& input);
	std::string CalculateFileSHA256(const std::string& filename);

	
};

