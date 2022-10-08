#include "DataTypeFinder.h"
using namespace DataTypes;

AllDataTypes DataTypes::FindTokenDataType(const std::string& token, const int& line)
{
	if (token.at(0) == '\'') {
		if (token.size() == 3)
		{
			return Character;
		}
		else {
			if (token.size() == 2 && token == "\'\'") {
				return Character;
			}
			else {
				Error error{ "Expected a single character", line, "SYNTAX-ERROR" };
			}
		}
	}
}
