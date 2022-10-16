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