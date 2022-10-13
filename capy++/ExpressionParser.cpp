#include "ExpressionParser.h"

using namespace expressionEvaluationUtil;

/// <summary>
/// evalutes the expressions overall type using the parts of the expression
/// </summary>
/// <param name="expressionParts"></param>
/// <returns></returns>
AllTypes EvaluateExpressionType(const vector<AllTypes>& expressionParts)
{
	switch (expressionParts.at(expressionParts.size() - 1)) {
	case Boolean:
		return BoolFirstType(expressionParts);
	case String:
	case Character:
		return StringOrCharFirstType(expressionParts);
	case Integer:
	case Int64:
		return IntFirstType(expressionParts);
	case DoubleNumber:
		return DoubleFirstType(expressionParts);
	default:
		return ERROR_TYPE;
	}
	return ERROR_TYPE;
}
namespace expressionEvaluationUtil {
	/// <summary>
	/// logic to tell if the types are compatible with bool
	/// </summary>
	/// <param name="expressionParts"></param>
	/// <returns></returns>
	AllTypes BoolFirstType(const vector<AllTypes>& expressionParts) {
		AllTypes previous{ Boolean };
		for (int i = expressionParts.size() - 2; i > 0; i--) {
			AllTypes current = expressionParts.at(i);

			switch (current) {
			case Boolean:
				if (previous != Boolean) {
					continue;
				}
				else {
					return ERROR_TYPE;
				}
				break;
			case AND:
			case OR:
			case Addition:
			case Subtraction:
				if (previous == Boolean) {
					continue;
				}
				else {
					return ERROR_TYPE;
				}
			default:
				return ERROR_TYPE;
			}

			previous = expressionParts.at(i);
		}
		return Boolean;
	}
	/// <summary>
	/// logic to tell if the types are compatible with string or char
	/// </summary>
	/// <param name="expressionParts"></param>
	/// <returns></returns>
	AllTypes StringOrCharFirstType(const vector<AllTypes>& expressionParts)
	{
		AllTypes previous{ String };
		for (int i = expressionParts.size() - 2; i > 0; i--) {
			AllTypes current = expressionParts.at(i);

			switch (current)
			{
			case Character:
			case String:
				if (previous == Addition) {
					continue;
				}
				else {
					return ERROR_TYPE;
				}
				break;
			case Addition:
				if (previous == Character || previous == String) {
					continue;
				}
				else {
					return ERROR_TYPE;
				}
				break;
			default:
				return ERROR_TYPE;
				break;
			}

			previous = expressionParts.at(i);
		}
		return String;
	}
	/// <summary>
	/// logic to tell if types are compatible with ints
	/// </summary>
	/// <param name="expressionParts"></param>
	/// <returns></returns>
	AllTypes IntFirstType(const vector<AllTypes>& expressionParts)
	{
		AllTypes previous{ expressionParts.at(0) };
		bool is64Bit{ false };
		for (int i = expressionParts.size() - 2; i > 0; i--) {
			AllTypes current = expressionParts.at(i);

			switch (current) {
			case Integer:
				if (previous == Addition || previous == Multiplication || previous == Division || previous == Subtraction) {
					continue;
				}
				else {
					return ERROR_TYPE;
				}
				break;
			case Int64:
				is64Bit = true;
				if (previous == Addition || previous == Multiplication || previous == Division || previous == Subtraction) {
					continue;
				}
				else {
					return ERROR_TYPE;
				}
				break;
			case Addition:
			case Multiplication:
				is64Bit = true;
				if (previous == Integer || previous == Int64) {
					continue;
				}
				else {
					return ERROR_TYPE;
				}
				break;
			case Division:
			case Subtraction:
				if (previous == Integer || previous == Int64) {
					continue;
				}
				else {
					return ERROR_TYPE;
				}
				break;
			default:
				return ERROR_TYPE;
				break;
			}

			previous = expressionParts.at(i);
		}
		if (is64Bit) {
			return Int64;
		}
		else {
			return Integer;
		}
	}
	/// <summary>
	/// logic to tell if the types are compatible with double
	/// </summary>
	/// <param name="expressionParts"></param>
	/// <returns></returns>
	AllTypes DoubleFirstType(const vector<AllTypes>& expressionParts)
	{
		AllTypes previous{ expressionParts.at(0) };
		for (int i = expressionParts.size() - 2; i > 0; i--) {
			AllTypes current = expressionParts.at(i);

			switch (current)
			{
			case Integer:
			case Int64:
			case DoubleNumber:
				if (previous == Addition || previous == Multiplication || previous == Division || previous == Subtraction) {
					continue;
				}
				else {
					return ERROR_TYPE;
				}
				break;
			case Addition:
			case Subtraction:
			case Multiplication:
			case Division:
				if (previous == DoubleNumber || previous == Integer || previous == Int64) {
					continue;
				}
				else {
					return ERROR_TYPE;
				}
				break;
			default:
				return ERROR_TYPE;
				break;
			}
			previous = expressionParts.at(i);

		}
		return DoubleNumber;
	}
}