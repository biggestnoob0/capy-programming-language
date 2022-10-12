#pragma once
#include <fstream>
#include "Parser.h"
#include "FundamentalDataTypes/IdentifierAttributes.h"
#include <string>
#include <vector>

using std::string;
using std::vector;



class Parser
{
private:
	IdentifierAttributes ParseIdentifier(string& statement);
public:
	vector<IdentifierAttributes> identifierData{};

	Parser(string file);
};

