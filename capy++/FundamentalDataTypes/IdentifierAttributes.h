#pragma once
#include <string>
#include <vector>

using std::string;
using std::vector;

struct IdentifierAttributes
{
	vector<string> attributes{};
	bool initialised{};
	IdentifierAttributes(vector<string> _attributes, bool _initalised) : attributes(_attributes), initialised(_initalised) {};
};

