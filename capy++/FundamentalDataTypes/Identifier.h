#pragma once
#include <string>
#include <vector>
#include "..\TypeStructures.h"
#include "..\ExpressionParser.h"
#include "..\Error.h"

using std::string;
using std::vector;
using namespace DataTypes;

struct Identifier
{
private:
	vector<string> expressionParts{};
	vector<AllTypes> exprPartsDataTypes{};
	AllTypes expressionType{};
public:
	AllTypes userDefinedType{};
	/// <summary>
	/// the definitive type of the data
	/// </summary>
	AllTypes type{};
	string name{};
	void AddExpressionPart(string expressionPart, AllTypes dataType);
	void CompleteIdentifier(string name, AllTypes userDefinedType, int lineIdentified);
};