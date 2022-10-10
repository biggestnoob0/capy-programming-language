#include "ExpressionParser.h"

using namespace expressionEvaluationUtil;

AllTypes EvaluateExpressionType(const vector<AllTypes>& expressionParts)
{
		switch (expressionParts.at(0)) {
		case Boolean:
			return BoolFirstType(expressionParts);
		case String:
		case Character:
			return StringOrCharFirstType(expressionParts);

		case Byte:
		case Int16:
		case Integer:


		}
}
namespace expressionEvaluationUtil {
	AllTypes BoolFirstType(const vector<AllTypes> &expressionParts) {
		for (size_t i = 1; i < expressionParts.size(); i++) {
			AllTypes current = expressionParts.at(i);
			if (current != Boolean && current != AND && current != OR) {
				return ERROR_TYPE;
			}
		}
		return Boolean;
	}
	AllTypes StringOrCharFirstType(const vector<AllTypes>& expressionParts)
	{
		for (size_t i = 1; i < expressionParts.size(); i++) {

		}
	}
	AllTypes IntOrBelowFirstType(const vector<AllTypes>& expressionParts)
	{
		for (size_t i = 1; i < expressionParts.size(); i++) {
			AllTypes current = expressionParts.at(i);
			//FINISH THIS
		}
	}
}