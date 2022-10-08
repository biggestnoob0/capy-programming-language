#pragma once
#include <string>
#include <vector>

using std::string;
using std::vector;

struct Identifier
{
	string type{};
	string name{};
	vector<string> expressionParts{};
	string evaluatedValue{};

	Identifier(string type, string name, vector<string> expressionParts);
	Identifier(string type, string name, string expression);
};

