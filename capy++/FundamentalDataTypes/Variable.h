#pragma once
#include <string>

using std::string;

template <typename T>
struct Variable
{
	const string varName;
	T ValueHeld;

	Variable(string name, T value);
};