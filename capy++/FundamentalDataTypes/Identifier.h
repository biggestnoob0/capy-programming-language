#pragma once
#include <string>
#include <vector>

using std::string;
using std::vector;

struct Identifier
{
private:
	vector<string> expressionParts{};
	vector<string> exprPartsDataTypes{};
public:
	string type{};
	string name{};

	Identifier(string type, string name, vector<string> expressionParts);
	Identifier(string type, string name, string expression);

	void AddExpressionPart(string expressionPart, string dataType);
};

