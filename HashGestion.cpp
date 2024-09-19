#include "HashGestion.h"

/**
 * Brief Constructeur de la classe HashGestion
 *
 * Ne fait aucune acction
 *
 */
HashGestion::HashGestion()
{
	std::cout << "Constructeur par defautl du Hash" << std::endl;
}

/**
 * \brief Desctructeur de la classe HashGestion
 * 
 */
HashGestion::~HashGestion()
{
    std::cout << "Desctructeur par defautl du hasg" << std::endl;
}


/**
 * \brief Calcul le SHA256 d'une chaîne de caractère
 * 
 * \param input : chemin du nom du fichier
 * \return Empreinte de la chaine de caracètre sous forme d'une string
 */
std::string HashGestion::CalculateSHA256(const std::string& input)
{
    CryptoPP::SHA256 hash;
    std::string digest;

    CryptoPP::StringSource(input, true,
        new CryptoPP::HashFilter(hash,
            new CryptoPP::HexEncoder(
                new CryptoPP::StringSink(digest))));

    return digest;
}

/**
 * \brief Calcul le SHA256 d'un fichier en mettant en paramètre son chemin+nom.
 *
 * \param input : chemin du nom du fichier
 * \return Empreinte de la chaine de caracètre sous forme d'une string
 */
std::string  HashGestion::CalculateFileSHA256(const std::string& filename)
{
    CryptoPP::SHA256 hash;
    std::string hashFile;

    std::ifstream file(filename, std::ios::binary);

    if (!file)
    {
        std::cerr << "Impossible d'ouvrir le fichier." << std::endl;
        return "";
    }

    CryptoPP::HashFilter filter(hash, new CryptoPP::HexEncoder(new CryptoPP::StringSink(hashFile)));

    const size_t bufferSize = 4096; // Taille du bloc de lecture
    CryptoPP::byte buffer[bufferSize]{};

    while (file.good())
    {
        file.read(reinterpret_cast<char*>(buffer), bufferSize);
        const std::streamsize bytesRead = file.gcount();

        if (bytesRead > 0)
        {
            filter.Put(buffer, bytesRead);
        }
    }

    filter.MessageEnd();
    return hashFile;
}
