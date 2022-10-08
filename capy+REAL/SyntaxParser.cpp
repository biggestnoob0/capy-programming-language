#include "SyntaxParser.h"

void SyntaxParser::ParseAllIdentifiers(vector<vector<string>>& linesInFile) {
	for (vector<string> line : linesInFile) {
		int size = line.size();
		if (size > 2) {
			for (int i = size; i >= 0; i--) {
				char firstChar = line.at(i).at(0);
				string token = line.at(i);
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
				else if (std::strchr("\"\'", firstChar)) {

				}
			}
		}
		else {

		}
	}
}