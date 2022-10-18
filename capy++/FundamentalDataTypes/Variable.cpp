#include "Variable.h"
Variable::Variable(string name, string valueAsStr, AllTypes type) {
	this->varName = name;
	this->ValueHeldAsStr = valueAsStr;
	this->varType = type;
}