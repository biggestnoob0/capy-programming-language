#pragma once
#include <fstream>
#include "Parser.h"
#include <string>
#include <vector>

using std::string;
using std::vector;



class Parser
{
private:
	vector<string> ParseIdentifier(string& statement);
public:
	vector<vector<string>> identifierData{};

	Parser(string file);
};

