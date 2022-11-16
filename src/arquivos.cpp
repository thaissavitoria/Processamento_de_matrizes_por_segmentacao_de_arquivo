#include "arquivos.hpp"

int lin_ini, lin_fim, col_ini, col_fim;
std::vector<std::vector<int>> matriz;

void getCoord(std::string lineHash)
{
    std::string name;
    std::vector<int> coorde;
    std::stringstream sstream(lineHash);
    while (getline(sstream, name, ','))
    {
        coorde.push_back(std::stoi(name));
    }
    lin_ini = coorde[0];
    col_ini = coorde[1];
    lin_fim = coorde[2];
    col_fim = coorde[3];
}

void LeMatriz()
{
    // Criando variável (handle) pela qual será possível manipular os arquivos
    std::ifstream matriz_arq;

    /// Abrindo o arquivo Matriz
    matriz_arq.open("Matriz.txt");

    if (matriz_arq.fail())
    {
        std::cout << "Problemas na abertura do arquivo!" << std::endl;
    }

    int j = 0, num;
    int current_line = 0; /// controle de qual linha do arquivo a leitura está
    std::string line;
    /// Lendo no arquivo "Matriz.txt"
    while (!matriz_arq.eof())
    {
        std::vector<int> linha;
        getline(matriz_arq, line);
        if (current_line >= lin_ini && current_line <= lin_fim) /// Confere se a linha está entre o intervalo que desejamos
        {
            std::string name;
            std::stringstream sstream(line);
            j = 0;
            while (getline(sstream, name, ' '))
            {
                if (j >= col_ini && j <= col_fim)
                {
                    num = stoi(name);
                    linha.push_back(num);
                }
                j++;
            }
            matriz.push_back(linha);
        }
        current_line++;
    }

    ////Fechando o arquivo
    matriz_arq.close();
}
