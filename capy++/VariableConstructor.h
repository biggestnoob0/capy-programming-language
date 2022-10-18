#pragma once
#include <string>
#include <vector>
#include "FundamentalDataTypes/Identifier.h"
#include "FundamentalDataTypes/Variable.h"

using std::vector;
using std::string;
class VariableConstructor {
private:
	static Variable ConstructChar(Identifier &identifier);
	static Variable ConstructString(Identifier &identifier);
	static Variable ConstructBool(Identifier &identifier);
	static Variable Construct(vector<string> expressionParts);
public:

	static void ConstructVars(Identifier &identifiers);
};