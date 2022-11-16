#include "hash.hpp"

void Insert(std::map<std::string, std::vector<std::vector<int>>> *tabela)
{
    std::ifstream co;

    co.open("Coordenadas.txt");

    if (co.fail())
    {
        std::cout << "Problemas na abertura do arquivo!" << std::endl;
    }

    std::string lineHash;

    while (!co.eof())
    {
        getline(co, lineHash);
        if (!Search(tabela, lineHash))
        {
            std::cout << "Não encontrou\n"<< std::endl;
            matriz.clear();
            matrizMulti.clear();
            matrizTransp.clear();

            getCoord(lineHash);
            LeMatriz();

            Transposta();

            inicializaMatrizMulti();
            Multiplicacao();

            tabela->insert({lineHash, matrizMulti});
            std::cout << lineHash << std::endl;
            printFinal(matrizMulti);
        }
    }

    co.close();
}

bool Search(std::map<std::string, std::vector<std::vector<int>>> *tabela, std::string key)
{
    std::map<std::string, std::vector<std::vector<int>>>::iterator itr;

    itr = tabela->find(key);

    if (itr != tabela->end())
    {
        std::cout << "Coordenada encontrada" << std::endl<< std::endl;
        std::cout << key << std::endl;

        printFinal(itr->second);
        return true;
    }
    return false;
}

void printFinal(std::vector<std::vector<int>> matrizFinal)
{
    for (auto li : matrizFinal)
    {
        for (auto coluna : li)
        {
            std::cout << coluna << " | ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}