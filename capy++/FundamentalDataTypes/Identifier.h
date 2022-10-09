#pragma once
#include <string>
#include <vector>
#include "..\DataTypeEnums.h"

using std::string;
using std::vector;
using namespace DataTypes;

struct Identifier
{
private:
	vector<string> expressionParts{};
	vector<AllDataTypes> exprPartsDataTypes{};
public:
	AllDataTypes type{};
	string name{};
	void AddExpressionPart(string expressionPart, AllDataTypes dataType);
};