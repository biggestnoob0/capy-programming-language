#pragma once
#include "Parser.h"
#include "Globals.h"
#include "SyntaxParser.h"
#include <string>
#include <vector>

using std::string;
using std::vector;

void Compile(vector<string> files, string dir);

void StopApplication();
