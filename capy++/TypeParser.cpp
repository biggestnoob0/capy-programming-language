#include "TypeParser.h"

AllTypes TypeParser::IdentifierOverallType(const AllTypes& expressionType, const AllTypes& userType)
{
	switch (expressionType) {
	case NO_TYPE:
		return userType;
		break;
	case Character:
		return CaseChar(userType);
		break;
	case String:
		return CaseString(userType);
		break;
	case Boolean:
		return CaseBoolean(userType);
		break;
	case Integer:
	case Int64:
		return CaseInteger(userType);
		break;
	case DoubleNumber:
		break;
	default:
		Error error{ "TYPE ASSIGNED UNKNKOWN", -1, "COMPILER-ERROR" };


	}
}

AllTypes TypeParser::CaseString(const AllTypes& userType)
{
	if (userType == String) {
		return userType;
	}
	return ERROR_TYPE;
}

AllTypes TypeParser::CaseChar(const AllTypes& userType)
{
	switch (userType)
	{
	case Character:
	case String:
	case U_Byte:
		return userType;
	default:
		return ERROR_TYPE;
	}
}

AllTypes TypeParser::CaseBoolean(const AllTypes& userType)
{
	if (userType == Boolean) {
		return Boolean;
	}
	return ERROR_TYPE;
}

AllTypes TypeParser::CaseInteger(const AllTypes& userType)
{
	switch (userType) {
	case Byte:
	case Int16:
	case Integer:
	case Int64:
	case FloatNumber:
	case DoubleNumber:
	case U_Byte:
	case U_Int16:
	case U_Integer:
	case U_Int64:
	case U_FloatNumber:
	case U_DoubleNumber:
		return userType;
	}
	return ERROR_TYPE;
}

AllTypes TypeParser::CaseDouble(const AllTypes& userType)
{
	switch (userType) {
	case FloatNumber:
	case DoubleNumber:
	case U_FloatNumber:
	case U_DoubleNumber:
		return userType;
	}
	return ERROR_TYPE;
}
