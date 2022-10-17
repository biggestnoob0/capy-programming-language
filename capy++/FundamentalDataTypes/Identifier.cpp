#include "Identifier.h"

/// <summary>
/// use when all expressions have been added
/// </summary>
Identifier::Identifier(vector<string> expressionParts, vector<AllTypes> exprPartsDataTypes, string name, AllTypes userDefinedType, int lineIdentified)
{
	this->expressionParts = expressionParts;
	this->exprPartsDataTypes = exprPartsDataTypes;
	this->name = name;
	this->userDefinedType = userDefinedType;

	// evalutes the expression type depending on itiitaliser specified
	if (expressionParts.size() > 1) {
		this->expressionType = EvaluateExpressionType(this->exprPartsDataTypes);
	}
	else if(expressionParts.size() == 1) {
		this->expressionType = this->exprPartsDataTypes.at(0);
	}
	else {
		this->expressionType = NO_TYPE;
	}

	if (this->expressionType == ERROR_TYPE) {
		Error error{ "Invalid expression, types do not match",  lineIdentified, "TYPE-COMPATIBILITY-ERROR"};
	}

	//evaluates the overall type of the identifier
	this->type = TypeParser::IdentifierOverallType(expressionType, userDefinedType);
	if (this->type == ERROR_TYPE) {
		Error error{ "Expression type and user type do not match",  lineIdentified, "TYPE-COMPATIBILITY-ERROR" };
	}
}