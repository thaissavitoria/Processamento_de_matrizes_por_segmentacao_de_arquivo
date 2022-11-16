#ifndef HASH_HPP
#define HASH_HPP

#include "matriz.hpp"
#include <map>

void Insert(std::map<std::string, std::vector<std::vector<int>>> *tabela);
bool Search(std::map<std::string, std::vector<std::vector<int>>> *tabela,std::string key);
void printFinal(std::vector<std::vector<int>>matrizFinal);

#endif