#pragma once
#include <string>
#include <vector>
#include "TypeEnums.h"
#include "Error.h"
#include "FundamentalDataTypes/Identifier.h"

using std::string;
using std::vector;
using namespace DataTypes;

class SyntaxParser
{
private:
	AllTypes CharSyntaxChecker(string &token, size_t &lineIndex);
	AllTypes StringSyntaxChecker(string &token, size_t &lineIndex);
	AllTypes NumberSyntaxChecker(string& token, int &dots, size_t& lineIndex);
	AllTypes BoolTrueSyntaxChecker(string& token, size_t& lineIndex);
	AllTypes BoolFalseSyntaxChecker(string& token, size_t& lineIndex);
public:
	void ParseAllIdentifiers(const vector<vector<string>> &linesInFile);
};

