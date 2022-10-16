#pragma once
#include <string>
#include <vector>
#include "TypeStructures.h"
#include "Error.h"
using std::string;
using std::vector;
using namespace DataTypes;

/// <summary>
/// used for parsing expression and user defined or actual types
/// </summary>
class TypeParser
{
public:
	static AllTypes IdentifierOverallType(const AllTypes& expressionType, const AllTypes& userType);
private:
	static AllTypes CaseString(const AllTypes& userType);
	static AllTypes CaseChar(const AllTypes& userType);
	static AllTypes CaseBoolean(const AllTypes& userType);
	static AllTypes CaseInteger(const AllTypes& userType);
	static AllTypes CaseDouble(const AllTypes& userType);
};