#include "matriz.hpp"

std::vector<std::vector<int>> matrizTransp(lin_fim, std::vector<int>(col_fim, 0));
std::vector<std::vector<int>> matrizMulti(lin_fim, std::vector<int>(col_fim, 0));

void Transposta()
{
    for (long unsigned int i = 0; i < matriz.size(); i++)
    {
        std::vector<int> lin;
        for (long unsigned int j = 0; j < matriz.size(); j++)
        {
            lin.push_back(matriz[j][i]);
        }
        matrizTransp.push_back(lin);
    }
}

void Multiplicacao()
{
    int soma;

    for (long unsigned int i = 0; i < matriz.size(); i++)
    {
        for (long unsigned int j = 0; j < matriz[i].size(); j++)
        {
            soma=0;
            for (long unsigned int k = 0; k < matrizTransp[i].size(); k++) // Para fazer multiplicações(X.Y) a matriz x tem que ter o mesmo num de colunas que a y tem de linhas, posso pegar col_fim ou lin_fim
            {
                soma += matriz[i][k] * matrizTransp[k][j];
            }
           matrizMulti[i][j] = soma;
        }
    }
}

void inicializaMatrizMulti() // Inicializa vector com 0 para manipulá-lo na multiplicação
{
    /// Na matriz transposta, o numero de linhas da original vira o numero de colunas da transposta.
    for (long unsigned int i = 0; i < matriz.size(); i++)
    {
        std::vector<int> lin;
        for (long unsigned int j = 0; j < matriz[i].size(); j++)
        {
            lin.push_back(0);
        }
        matrizMulti.push_back(lin);
    }
}