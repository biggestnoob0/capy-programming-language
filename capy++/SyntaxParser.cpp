#include "SyntaxParser.h"

void SyntaxParser::ParseAllIdentifiers(const vector<vector<string>>& linesInFile) {
	vector<Identifier> identifiersLineSorted{};
	for (size_t lineIndex = 0; lineIndex < linesInFile.size(); lineIndex++) {
		Identifier currentIdentifier{};
		vector<string> line = linesInFile.at(lineIndex);
		int size = line.size();
		if (size > 2) {
			for (int tokenIterator = size - 1; tokenIterator >= 0; tokenIterator--) {
				string token = line.at(tokenIterator);
				char firstChar = token.at(0);
				AllTypes dataType{};
				if (firstChar == '=') {
					break;
				}
				if (firstChar == '!') {
					firstChar = token.at(1);
				}
				if (std::isdigit(firstChar) || firstChar == '-') {
					int dots = std::count(token.begin(), token.end(), '.');
					dataType = NumberSyntaxChecker(token, dots, lineIndex);
					if (dataType != ERROR_TYPE) {
						currentIdentifier.AddExpressionPart(token, dataType);
					}
				}
				else {
					// else if non-numerical
					switch (firstChar) {
					case '\'':
						dataType = CharSyntaxChecker(token, lineIndex);
						if (dataType != ERROR_TYPE) {
							currentIdentifier.AddExpressionPart(token, dataType);
						}
						break;
					case '\"':
						dataType = StringSyntaxChecker(token, lineIndex);
						if (dataType != ERROR_TYPE) {
							currentIdentifier.AddExpressionPart(token, dataType);
						}
						break;
					case 't':
						dataType = BoolTrueSyntaxChecker(token, lineIndex);
						if (dataType != ERROR_TYPE) {
							currentIdentifier.AddExpressionPart(token, dataType);
						}
						break;
					case 'f':
						dataType = BoolFalseSyntaxChecker(token, lineIndex);
						if (dataType != ERROR_TYPE) {
							currentIdentifier.AddExpressionPart(token, dataType);
						}
						break;
					case '+':
						if (token.size() == 1) {
							currentIdentifier.AddExpressionPart(token, Addition);
						}
						break;
					case '-':
						if (token.size() == 1) {
							currentIdentifier.AddExpressionPart(token, Subtraction);
						}
						break;
					case '*':
						if (token.size() == 1) {
							currentIdentifier.AddExpressionPart(token, Multiplication);
						}
						break;
					case '/':
						if (token.size() == 1) {
							currentIdentifier.AddExpressionPart(token, Division);
						}
						break;

					case '%':
						if (token.size() == 1) {
							currentIdentifier.AddExpressionPart(token, Multiplication);
						}
						break;
					}

					if (token == "&&") {
						currentIdentifier.AddExpressionPart(token, AND);
					}
					else if (token == "||") {
						currentIdentifier.AddExpressionPart(token, OR);
					}
					// DO TYPE AND NAME CHECKS
				}
			}
			identifiersLineSorted.push_back(currentIdentifier);
		}
	}
}
AllTypes SyntaxParser::CharSyntaxChecker(string& token, size_t& lineIndex)
{
	// if only 1 character
	if (token.size() == 3)
	{
		return Character;
	}
	else {
		// if null character
		if (token.size() == 2 && token == "\'\'") {
			return Character;
		}
		else {
			Error error{ "Expected a single character", (int)lineIndex, "SYNTAX-ERROR" };
			return ERROR_TYPE;
		}
	}
}

AllTypes SyntaxParser::StringSyntaxChecker(string& token, size_t& lineIndex)
{
	// if 1 or more characters and quote at end
	if (token.size() >= 3 && token.at(token.size() - 1) == '\"') {
		return String;
	}
	else {
		Error error{ "Expected a quote mark before the end of line", (int)lineIndex, "SYNTAX-ERROR" };
		return ERROR_TYPE;
	}
}

AllTypes SyntaxParser::NumberSyntaxChecker(string& token, int& dots, size_t& lineIndex)
{
	for (size_t i = 0; i < token.size(); i++) {
		if (!std::isdigit(token.at(i))) {
			if (token.at(i) == '.') {
				continue;
			}
			return ERROR_TYPE;
		}
	}
	if (dots == 0) {
		if (token.size() > 9) {
			return Int64;
		}
		else {
			return Integer;
		}
	}
	else if (dots == 1) {
		return DoubleNumber;
	}
	else {
		Error error{ "More than 1 decimal point", (int)lineIndex, "SYNTAX-ERROR" };
		return ERROR_TYPE;
	}
}

AllTypes SyntaxParser::BoolTrueSyntaxChecker(string& token, size_t& lineIndex)
{
	if (token == "true" || token == "!true") {
		return Boolean;
	}
	Error error{ "No quote marks specified", (int)lineIndex, "SYNTAX-ERROR" };
	return ERROR_TYPE;
}

AllTypes SyntaxParser::BoolFalseSyntaxChecker(string& token, size_t& lineIndex)
{
	if (token == "false" || token == "!false") {
		return Boolean;
	}
	Error error{ "No quote marks specified", (int)lineIndex, "SYNTAX-ERROR" };
	return ERROR_TYPE;
}
