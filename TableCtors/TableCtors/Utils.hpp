#pragma once

namespace defaultVals
{
constexpr char* SEPARATOR = " ";
constexpr char* TABLE_NAME = "KORYTKO_TABLE";
constexpr char* POST_COPIED_NAME = "_copy";
constexpr char* DTOR_PRE_PRINT = "usuwam: ";
constexpr char* CTOR_COPY_PRE_PRINT = "kopiuj: ";
constexpr char* CTOR_DEFAULT_PRE_PRINT = "bezp: ";
constexpr char* CTOR_ARG1_PRE_PRINT = "parametr: ";
constexpr char* POST_PRINT = "\n";
constexpr int INITIAL_FLYWEIGHT_CACHE_SIZE = 10;
constexpr int ZERO = 0;
}

namespace idxOf
{
constexpr int command = 0;
constexpr int idOrAmmount = 1;
}

namespace messageLiterals
{
constexpr char* createDef = "createDef"; // calls default ctor for obj with number 
constexpr char* createDefs = "createDefs"; // calls default ctor for number of obj
//createDef <nrTablicy> -wywo�uje domy�lny konstruktor obiektu o podanym numerze.
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

