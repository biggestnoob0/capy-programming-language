#include "Compiler.h"

int runtimeErrors{};
string directoryBase{};
string currentLogFile{};
string currentCompilingFile{};

void Compile(vector<string> files, string dir) {
	const size_t fileAmnt{ files.size() };
	directoryBase = dir;
	// VARIABLE LAYERS
	// layer 1: all files contents
	// layer 2: a files contents
	// layer 3: a lines contents
	vector<vector<vector<string>>> fileContentsList{};

	for (string file : files) {
		currentCompilingFile = file;
		Parser parser{ file };
		SyntaxParser syntaxParser{};
		syntaxParser.ParseAllIdentifiers(parser.identifierData);
		fileContentsList.push_back(parser.identifierData);
	}
	if (runtimeErrors > 0) {
		StopApplication();
	}
}
void StopApplication() {
	exit(EXIT_FAILURE);
}