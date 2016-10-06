#pragma once
#include <vector>
#include <string>
#include "CTable.hpp"

namespace stub
{

std::vector<std::string> createDef = { "createDef", "0" };
std::vector<std::string> createDefs0 = { "createDefs", "0" };
std::vector<std::string> createDefs4 = { "createDefs", "4" };
std::vector<std::string> createDefs20 = { "createDefs", "20" };

//createDef <nrTablicy> -wywo�uje domy�lny konstruktor obiektu o podanym numerze.
//
//create <nrTablicy> <rozmiar> <nazwaTablicy> -wywo�uje parametryczny kontruktor
//
//createCopy <nrTablicy> <nrTablicyDoKopiowania> -wywo�uje kontruktor kopiuj�cy
//
//setValue <nrTablicy> <nrPozycji> <warto��>
//
//getValue <nrTablicy> <nrPozycji>
//
//setName <nrTablicy> <nazwaTablicy>
//
//getName <nrTablicy>
}

