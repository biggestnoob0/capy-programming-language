#include "Identifier.h"

void Identifier::AddExpressionPart(string expressionPart, AllTypes type)
{
	this->expressionParts.push_back(expressionPart);
	this->exprPartsDataTypes.push_back(type);
}

/// <summary>
/// use when all expressions have been added
/// </summary>
void Identifier::CompleteIdentifier(string name, AllTypes userDefinedType, int lineIdentified)
{
	this->name = name;
	this->userDefinedType = userDefinedType;
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

}