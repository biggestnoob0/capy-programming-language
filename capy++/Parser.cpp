#include "Parser.h"

Parser::Parser(string file) {
	std::ifstream reader{ file };
	std::string line{};
	while (std::getline(reader, line)) {
		if (line.size() == 0)
			continue;
		while (line.at(0) == ' ') {
			line = line.substr(1);
		}
		if (line.at(0) == '$') {
			line = line.substr(1);
			this->identifierData.push_back(ParseIdentifier(line));
		}
	}
	reader.close();
}

IdentifierAttributes Parser::ParseIdentifier(string& statement) {
	// get rid of trailing white space
	while (statement.at(0) == ' ') {
		statement = statement.substr(1);
	}
	size_t statementSize{ statement.size() };
	// get rid of end white space
	while (statement.at(statementSize - 1) == ' ') {
		statement = statement.substr(0, statementSize - 1);
		statementSize--;
	}
	bool initalised{false};

	size_t pos{};
	size_t prevPos{};
	size_t diff{};
	size_t i{ 0 };
	char prevChar{};
	bool inQuotes{false};
	std::vector<string> identifierAttribs{};
	// splits identifier up into words using spaces
	while (true) {
		for (; true; i++) {
			char letter{ statement.at(i) };
			if (i >= statementSize - 1) {
				pos = i + 1;
				break;
			}
			if (letter == '\'' || letter == '\"') {
				inQuotes = !inQuotes;
			}

			if (letter == ' ') {
				if (!inQuotes) {
					if (prevChar != ' ') {
						pos = i;
						prevChar = ' ';
						break;
					}
					else {
						prevPos++;
					}
				}
			}
			prevChar = letter;
		}
		diff = pos - prevPos;
		identifierAttribs.push_back(statement.substr(prevPos, diff));

		prevPos = pos;

		if (i >= statementSize - 1) {
			break;
		}
	}
	for (size_t i = 0; i < identifierAttribs.size(); i++) {
		if (identifierAttribs.at(i).size() == 1 && identifierAttribs.at(i).at(0) == '=') {
			initalised = true;
		}
	}
	return IdentifierAttributes{identifierAttribs, initalised};
}