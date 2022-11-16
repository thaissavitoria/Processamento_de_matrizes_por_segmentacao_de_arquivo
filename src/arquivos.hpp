#ifndef ARQUIVOS_HPP
#define ARQUIVOS_HPP

#include <iostream> // Entrada e saída
#include <iomanip>  // Formatação de entrada e saída
#include <fstream>  // Fluxo de dados entre arquivo e programa
#include <string.h> // Manipular string
#include <vector>   // Manipular vectors
#include <stdio.h>
#include <sstream> 


// extern é usado para definição de variáveis globais
extern int lin_ini, lin_fim;
extern int col_ini, col_fim;
extern std::vector<std::vector<int>> matriz;

void getCoord(std::string lineHash);
void LeMatriz();

#endif