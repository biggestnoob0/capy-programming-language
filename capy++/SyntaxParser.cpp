#include "SyntaxParser.h"

void SyntaxParser::ParseAllIdentifiers(vector<vector<string>>& linesInFile) {
	for (size_t lineIndex = 0; lineIndex < linesInFile.size(); lineIndex++) {
		vector<string> line = linesInFile.at(lineIndex);
		int size = line.size();
		if (size > 2) {
			for (int tokenIterator = size - 1; tokenIterator >= 0; tokenIterator--) {
				char firstChar = line.at(tokenIterator).at(0);
				string token = line.at(tokenIterator);
				if (std::isdigit(firstChar)) {
					int dots = std::count(token.begin(), token.end(), '.');
					if (dots == 0) {

					}
					else if (dots == 1) {

					}
					else {
						//error
					}
				}
				// else if string or char
				else if (firstChar == '\'') {
					CharSyntaxChecker(token, lineIndex);
				}
				else if (firstChar == '\"') {
					StringSyntaxChecker(token, lineIndex);
				}
			}
		}
		else {

		}
	}
}

AllDataTypes SyntaxParser::CharSyntaxChecker(string& token, size_t &lineIndex)
{
	if (token.size() == 3)
	{
		return Character;
	}
	else {
		if (token.size() == 2 && token == "\'\'") {
			return Character;
		}
		else {
			Error error{ "Expected a single character", (int)lineIndex, "SYNTAX-ERROR" };
			return ERROR_TYPE;
		}
	}
}

AllDataTypes SyntaxParser::StringSyntaxChecker(string& token, size_t& lineIndex)
{
	if (token.size() > 3 && token.at(token.size() - 1) == '\"') {
		return String;
	}
	else {
		Error error{ "Expected a quote mark before the end of line", (int)lineIndex, "SYNTAX-ERROR" };
		return ERROR_TYPE;
	}
}
