#include "Identifier.h"

void Identifier::AddExpressionPart(string expressionPart, AllDataTypes dataType)
{
	this->expressionParts.push_back(expressionPart);
	this->exprPartsDataTypes.push_back(dataType);
}
