#pragma once
#include "Parser.h"
#include "Globals.h"
#include "SyntaxParser.h"
#include "VariableConstructor.h"
#include <string>
#include <vector>
//testing only
#include "DebugConsole.h"

using std::string;
using std::vector;

void Compile(vector<string> files, string dir);

void StopApplication();
