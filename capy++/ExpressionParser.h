#pragma once
#include <string>
#include <vector>
#include "TypeStructures.h"

using std::string;
using std::vector;
using namespace DataTypes;

/// <summary>
/// evaluates an identifiers overall expression type, no type checking
/// </summary>
/// <param name="expressionParts"></param>
/// <returns></returns>
AllTypes EvaluateExpressionType(const vector<AllTypes>& expressionParts);

/// <summary>
/// a namespace for expression parser to evaluate the expression types
/// </summary>
namespace expressionEvaluationUtil {
	AllTypes BoolFirstType(const vector<AllTypes>& expressionParts);

	AllTypes StringOrCharFirstType(const vector<AllTypes>& expressionParts);

	AllTypes IntFirstType(const vector<AllTypes>& expressionParts);

	AllTypes DoubleFirstType(const vector<AllTypes>& expressionParts);
}