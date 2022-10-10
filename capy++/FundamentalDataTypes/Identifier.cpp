#include "Identifier.h"

void Identifier::AddExpressionPart(string expressionPart, AllTypes type)
{
	this->expressionParts.push_back(expressionPart);
	this->exprPartsDataTypes.push_back(type);
}

/// <summary>
/// use when all expressions have been added
/// </summary>
void Identifier::CompleteIdentifier(string name, AllTypes userDefinedType)
{
	this->name = name;
	this->userDefinedType = userDefinedType;

}