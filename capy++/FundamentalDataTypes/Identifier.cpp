#include "Identifier.h"

Identifier::Identifier(string type, string name, vector<string> expressionParts) {
	this->name = name;
	this->type = type;
	this->expressionParts = expressionParts;
}

Identifier::Identifier(string type, string name, string expression) {
	this->name = name;
	this->type = type;
	this->expressionParts.push_back(expression);
}