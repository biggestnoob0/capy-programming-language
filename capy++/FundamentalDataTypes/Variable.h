#pragma once
#include <string>
#include "../TypeStructures.h"

using std::string;
using namespace DataTypes;

template <typename T>
struct Variable
{
	const string varName;
	T ValueHeld;
	AllTypes varType;

	Variable(string name, T value, AllTypes type);
};