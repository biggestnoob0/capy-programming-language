#include "Compiler.h"
int runtimeErrors{};
string directoryBase{};
string currentLogFile{};
string currentCompilingFile{};

void Compile(vector<string> files, string dir) {
	const size_t fileAmnt{ files.size() };
	directoryBase = dir;

	for (size_t fileIterator{ 0 }; fileIterator < files.size(); fileIterator++) {
		string file = files.at(fileIterator);
		currentCompilingFile = file;
		Parser parser{ file };
		SyntaxParser syntaxParser{};
		vector<std::unique_ptr<Identifer>> identifiers{};
		identifiers.push_back(syntaxParser.ParseAllIdentifiers(parser.identifierData));
	}
	if (runtimeErrors > 0) {
		StopApplication();
	}
}
void StopApplication() {
	exit(EXIT_FAILURE);
}