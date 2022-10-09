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

vector<string> Parser::ParseIdentifier(string& statement) {
	while (statement.at(0) == ' ') {
		statement = statement.substr(1);
	}
	size_t pos{};
	size_t prevPos{};
	size_t diff{};
	size_t i{ 0 };
	char prevChar{};
	size_t statementSize{ statement.size() };
	std::vector<string> identifierAttribs{};
	while (true) {
		for (; true; i++) {
			if (i == statementSize) {
				break;
			}
			if (statement.at(i) == ' ') {
				if (prevChar != ' ') {
					pos = i;
					prevChar = ' ';
					break;
				}
				else {
					prevPos++;
				}
			}
			prevChar = statement.at(i);
		}
		diff = pos - prevPos;
		identifierAttribs.push_back(statement.substr(prevPos, diff));

		prevPos = pos;

		if (i == statementSize) {
			break;
		}
	}
	return identifierAttribs;
}