#pragma once
#include <string>
#include "../TypeStructures.h"

using std::string;
using namespace DataTypes;

struct Variable
{
	string varName;
	string ValueHeldAsStr;
	AllTypes varType;

	Variable(string name, string valueAsStr, AllTypes type);
};