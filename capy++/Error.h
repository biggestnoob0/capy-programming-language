#pragma once
#include <iostream>
#include <filesystem>
#include <fstream>
#include <chrono>
#include <string>
#include "Compiler.h"
using std::string;


struct Error
{
	Error(string message, int line, string type);
};

