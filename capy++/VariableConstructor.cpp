#include "VariableConstructor.h"

void VariableConstructor::ConstructVars(Identifier& identifier)
{
	if (identifier.expressionParts.size() > 1) {
		switch (identifier.type) {
		case String:
			ConstructString(identifier);
			break;
		case Byte:
		case U_Byte:
		case Int16:
		case U_Int16:
		case Integer:
		case U_Integer:
		case Int64:
		case U_Int64:
		case FloatNumber:
		case U_FloatNumber:
		case DoubleNumber:
		case U_DoubleNumber:

			break;
		}
	}
	else if (identifier.expressionParts.size() == 1) {
		if (identifier.type == Character) {
			ConstructChar(identifier);
		}
		else if (identifier.type == Boolean) {
			ConstructBool(identifier);
		}

		switch (identifier.type) {
		case String:
			ConstructString(identifier);
			break;
		case Byte:
		case U_Byte:
		case Int16:
		case U_Int16:
		case Integer:
		case U_Integer:
		case Int64:
		case U_Int64:
		case FloatNumber:
		case U_FloatNumber:
		case DoubleNumber:
		case U_DoubleNumber:

			break;
		}
	}
}

Variable VariableConstructor::ConstructChar(Identifier& identifier)
{
	return Variable{ identifier.name, identifier.expressionParts.at(0), identifier.type };
}

Variable VariableConstructor::ConstructString(Identifier& identifier)
{
	string str{};
	for (int i{ (int)identifier.expressionParts.size() - 1}; i >= 0; i--) {
		if (identifier.exprPartsDataTypes.at(i) != Addition) {
			if (i == identifier.expressionParts.size() - 1) {
				str += identifier.expressionParts.at(i).substr(0, identifier.expressionParts.at(i).size() - 1);
			}
			else if (i == 0) {
				str += identifier.expressionParts.at(i).substr(1, identifier.expressionParts.at(i).size() - 1);
			}
			else {
				str += identifier.expressionParts.at(i).substr(1, identifier.expressionParts.at(i).size() - 2);
			}
		}
		else {
			continue;
		}
	}
	return Variable{ identifier.name, str, identifier.type };
}

Variable VariableConstructor::ConstructBool(Identifier& identifier)
{
	return Variable{ identifier.name, identifier.expressionParts.at(0), identifier.type };
}

Variable VariableConstructor::ConstructIntType(Identifier& identifier)
{
	long long numericalValue{};
	long long maxValue{};
	long long previousValue{};
	string maxValAsStr{};
	switch (identifier.type) {
	case Byte:
		maxValue = 127;
		break;
	case Int16:
		maxValue = 32767;
		break;
	case Integer:
		maxValue = 2147483647;
		break;
	case Int64:
		maxValue = 9223372036854775807;
		break;
	}
	maxValAsStr = std::to_string(maxValue);
	for (int i{ (int)identifier.expressionParts.size() - 1 }; i >= 0; i--) {
		if (identifier.exprPartsDataTypes.at(i) == Integer) {
			string token{ identifier.expressionParts.at(i) };
			if (token.size() >= maxValAsStr.size()) {
				if (token.size() == maxValAsStr.size()) {
					for (size_t i = 0; i < token.size(); i++)
					{
						if (token.at(i) < maxValAsStr.at(i)) 
						{ 
							break; 
						}
						else if (token.at(i) == maxValAsStr.at(i)) {
							continue;
						}
						else {
							Error error{ "Expression size is larger than max value of type", identifier.lineIdentified, "VALUE-OUT-OF-RANGE-ERROR" };
						}
					}
				}
				else {
					Error error{ "Expression size is larger than max value of type", identifier.lineIdentified, "VALUE-OUT-OF-RANGE-ERROR" };
				}
			}
		}
		else {
			switch (identifier.exprPartsDataTypes.at(i)) {

			}
		}
	}
}
