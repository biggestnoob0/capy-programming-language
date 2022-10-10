#include "SyntaxParser.h"

void SyntaxParser::ParseAllIdentifiers(const vector<vector<string>>& linesInFile) {
	vector<Identifier> identifiersLineSorted{};
	for (size_t lineIndex = 0; lineIndex < linesInFile.size(); lineIndex++) {
		Identifier currentIdentifier{};
		vector<string> line = linesInFile.at(lineIndex);
		int size = line.size();
		if (size > 2) {
			for (int tokenIterator = size - 1; tokenIterator >= 0; tokenIterator--) {
				char firstChar = line.at(tokenIterator).at(0);
				AllTypes dataType{};
				string token = line.at(tokenIterator);
				if (token == "=") {
					break;
				}
				if (std::isdigit(firstChar)) {
					int dots = std::count(token.begin(), token.end(), '.');
					dataType = NumberSyntaxChecker(token, dots, lineIndex);
					if (dataType != ERROR_TYPE) {
						currentIdentifier.AddExpressionPart(token, dataType);
					}
				}
				// else if string or char
				else if (firstChar == '\'') {
					dataType = CharSyntaxChecker(token, lineIndex);
					if (dataType != ERROR_TYPE) {
						currentIdentifier.AddExpressionPart(token, dataType);
					}
				}
				else if (firstChar == '\"') {
					dataType = StringSyntaxChecker(token, lineIndex);
					if (dataType != ERROR_TYPE) {
						currentIdentifier.AddExpressionPart(token, dataType);
					}
				}
			}
			// DO TYPE AND NAME CHECKS
		}
		else {

		}
		identifiersLineSorted.push_back(currentIdentifier);
	}
}

AllTypes SyntaxParser::CharSyntaxChecker(string& token, size_t &lineIndex)
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

AllTypes SyntaxParser::NumberSyntaxChecker(string& token, int &dots, size_t& lineIndex)
{
	for (size_t i = 0; i < token.size(); i++) {
		if (!std::isdigit(token.at(i))) {
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
