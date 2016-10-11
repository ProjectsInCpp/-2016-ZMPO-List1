#pragma once

#include <vector>
#include "CTable.hpp"
#include <limits>

namespace flag
{
constexpr bool printOn = true;
constexpr bool isRepl = true;
}

enum class ERROR_CODE : int
{
    SEEMS_LEGIT = 0, // when all is good(probably)
    UNDEFINED_OBJECT = 1, // when isProperIdx(idx) == true, situation when vector has allocated memory
    INDEX_OUT_OF_BOUNDS = 2, // when isProperIdx(idx) == false
    ERROR_COMMAND_PARSING = 3, // it will be used when parsing has errors or undefined command
    NOT_HANDLED_ERROR_REPORTING = 4,
    INITIAL_VAL = 5,
    WRONG_AMOUNT_OF_ARGS = 6,
    ERROR_ARGS_PARSING = 7, // when args amount is proper, but type is wrong
    WRONG_VALUE = 8, // when new size must be minus
    CLOSE = 10 // when new size must be minus
};

namespace defaultVals
{
constexpr const char* BASH_DOLAR = "$ ";
constexpr const char* PRE_PRINT = "   ";
constexpr const char* POST_PRINT = "\n";
constexpr const char* SEPARATOR = ": ";
constexpr const char* BRACKET_OPEN = "( ";
constexpr const char* BRACKET_CLOSE = " )";
constexpr const char* LEN = "len";
constexpr const char* VALUES = "values";
constexpr const char* SPACE = " ";
constexpr const char* COMMA_SPACE = ", ";
constexpr const char* DEFAULT_TABLE_NAME = "KORYTKO_TABLE";
constexpr const char* POST_COPIED_NAME = "_copy";
constexpr const char* DTOR_PRE_PRINT = "usuwam: ";
constexpr const char* CTOR_COPY_PRE_PRINT = "kopiuj: ";
constexpr const char* CTOR_DEFAULT_PRE_PRINT = "bezp: ";
constexpr const char* CTOR_DEFAULT_MOVE_PRINT = "przenoszenie: ";
constexpr const char* CTOR_ARG1_PRE_PRINT = "parametr: ";
constexpr int INITIAL_FLYWEIGHT_CACHE_SIZE = 5;
constexpr int ZERO = 0;
constexpr int MINUS_ONE = -1;
constexpr int ONE = 1;
constexpr int TWO = 2;
constexpr int FIVE = 5;
constexpr int TEN = 10;
constexpr long MAX_INT_VAL = (std::numeric_limits<int>::max)();
constexpr int DEFAULT_IN_TABLE_SIZE = TWO;
constexpr const char* string999 = "999";
constexpr const char* erroredCommandIdx = "Errored command idx";
constexpr char intType = 'i';
constexpr char stringType = 's';
}

namespace funs
{
bool isProperIdx(int idxOrAmount, std::vector<CTable*>& inCache);
bool isProperIdx(int idx, int size);
std::string toString(ERROR_CODE inCode);
bool isProperAmmountOfArgs(std::vector<std::string>& inCommand, int inProperAmountOfArgs);
bool isNumber(std::string inChain);
bool isProperTypeOfArgs(std::vector<std::string>& inCommand, std::string inProperTypeOfArgs);
bool isVectorEmpty(std::vector<CTable*>& inCache);
int toInt(char inChar);
}

namespace logLiterals
{
constexpr const char* undefinedCommand = "Nie znam takiej komendy";
constexpr const char* undefinedObject = "Nie znam takiego obiektu";
constexpr const char* indexOutOfBound = "Index poza obszarem pamieci";
constexpr const char* nullPointerDetected = "Object";
}

namespace idxOf
{
constexpr int command = 0;
constexpr int idOfCTable = 1;
constexpr int amount = 1;
constexpr int newName = 2;
constexpr int newSize = 2;
constexpr int goalId = 2;
constexpr int newVal = 3;
constexpr int initialName = 3;
}

namespace messageLiterals
{
constexpr char* create = "create"; // <nrTablicy> <rozmiar> <nazwaTablicy> - wywo�uje parametryczny kontruktor
constexpr char* createDef = "createDef"; // calls default ctor for obj with number 
constexpr char* createDefs = "createDefs"; // calls default ctor for number of obj
constexpr char* createCopy = "createCopy"; // <nrTablicy> <nrTablicyDoKopiowania> -wywo�uje kontruktor kopiuj�cy
constexpr char* getName = "getName"; // getName of CTable on idx
constexpr char* getSize = "getSize"; // getSize of CTable on idx
constexpr char* getValue = "getValue"; // getValue from table in CTable <nrTablicy> <nrPozycji>
constexpr char* remove = "remove"; // remove CTable on idx
constexpr char* removeAll = "removeAll"; // remove CTable on idx
constexpr char* setName = "setName"; // set name of CTable on idx
constexpr char* setValue = "setValue"; // set value of CTable <nrTablicy> on <nrPozycji> onto <warto��>
constexpr char* print = "print"; // <nrTablicy> <nrTablicyDoKopiowania> -wywo�uje kontruktor kopiuj�cy
constexpr char* printAll = "printAll"; // <nrTablicy> <nrTablicyDoKopiowania> -wywo�uje kontruktor kopiuj�cy
constexpr char* changeSize = "changeSize"; // <nrTablicy> <nrTablicyDoKopiowania> -wywo�uje kontruktor kopiuj�cy
constexpr char* close = "close"; // <nrTablicy> <nrTablicyDoKopiowania> -wywo�uje kontruktor kopiuj�cy
constexpr char* help = "help"; // <nrTablicy> <rozmiar> <nazwaTablicy> - wywo�uje parametryczny kontruktor
}

namespace commandArgs
{
constexpr char* IDX = "<idx>";
constexpr char* SIZE = "<size>";
constexpr char* NAME = "<name>";
constexpr char* VALUE = "<value>";

}

namespace fullCommands
{
extern std::string createArgs;
extern std::string createDefArgs;
extern std::string createDefsArgs;
extern std::string createCopyArgs;
extern std::string getNameArgs;
extern std::string getSizeArgs;
extern std::string getValueArgs;
extern std::string setValueArgs;
extern std::string setNameArgs;
extern std::string printArgs;
extern std::string printAllArgs;
extern std::string removeArgs;
extern std::string removeAllArgs;
extern std::string changeSizeArgs;
extern std::string closeArgs;
extern std::string helpArgs;
extern std::vector<std::string> allCommands;
}



