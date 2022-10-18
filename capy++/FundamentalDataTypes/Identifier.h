#pragma once
#include <string>
#include <vector>
#include "..\TypeStructures.h"
#include "..\ExpressionParser.h"
#include "..\Error.h"
#include "..\TypeParser.h"

using std::string;
using std::vector;
using namespace DataTypes;
/// <summary>
/// the data to build a variable
/// </summary>
struct Identifier
{
private:
public:
	vector<AllTypes> exprPartsDataTypes{};
	AllTypes expressionType{};
	vector<string> expressionParts{};
	AllTypes userDefinedType{};
	/// <summary>
	/// the overall type of the data
	/// </summary>
	AllTypes type{};
	string name{};
	Identifier(vector<string> expressionParts, vector<AllTypes> exprPartsDataTypes, string name, AllTypes userDefinedType, int lineIdentified);
};