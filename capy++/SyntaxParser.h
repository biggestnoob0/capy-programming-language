#pragma once
#include <string>
#include <vector>
#include "DataTypeEnums.h"
#include "Error.h"

using std::string;
using std::vector;
using namespace DataTypes;

class SyntaxParser
{
private:
	AllDataTypes CharSyntaxChecker(string &token, size_t &lineIndex);
	AllDataTypes StringSyntaxChecker(string &token, size_t &lineIndex);
public:
	void ParseAllIdentifiers(vector<vector<string>> &linesInFile);
};

