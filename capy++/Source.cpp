#pragma once
#include <string>
#include <vector>
#include "Compiler.h"
#include <filesystem>
#include <iostream>
// testing
#include <chrono>

using std::string;
using std::vector;
using std::cout;
using std::cin;

vector<string> srcFiles{};

int main() {
	namespace fs = std::filesystem;
	cout << "Enter directory of files here:";
	string dirstr{};
	cin >> dirstr;
	fs::path dir{ dirstr };
	if (fs::exists(dir)) {
		for (fs::directory_entry file : fs::recursive_directory_iterator(dir))
		{
			string str{ file.path().generic_string() };
			if (str.substr(str.size() - 5) == ".capy") {
				srcFiles.push_back(file.path().generic_string());
			}
		}
		auto start = std::chrono::high_resolution_clock::now();
		Compile(srcFiles, dirstr);
		auto end = std::chrono::high_resolution_clock::now();
		auto timeTaken = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
		cout << "Time Taken To Compile: " << timeTaken.count() << "ms" << std::endl;
	}
	else {
		cout << "invalid directory";
	}
}