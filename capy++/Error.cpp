#include "Error.h"

Error::Error(string message, int line, string type) {
	//TESTING ONLY
	std::cout << "ERROR" << std::endl;
	namespace fs = std::filesystem;
	int i = 0;
	if (currentLogFile.empty()) {
		while (true) {
			if (!fs::exists(directoryBase + "\\logs\\Log-" + std::to_string(i) + ".txt")) {
				if (!fs::exists(directoryBase + "\\logs")) {
					fs::create_directory(directoryBase + "\\logs");
				}
				std::fstream stream{ directoryBase + "\\logs\\Log-" + std::to_string(i) + ".txt", std::ios::out };
				currentLogFile = directoryBase + "\\logs\\Log-" + std::to_string(i) + ".txt";
				stream << type + ":" << std::endl << message << std::endl << "AT LINE: " + std::to_string(line + 1) << std::endl << "IN FILE: " + currentCompilingFile << std::endl;
				std::cout << "log file generated at " + currentLogFile << std::endl;
				break;
			}
			i++;
		}
	}
	else {
		std::fstream stream{ currentLogFile, std::ios_base::app };
		stream << type + ":" << std::endl << message << std::endl << "AT LINE: " + std::to_string(line + 1) << std::endl << "IN FILE: " + currentCompilingFile << std::endl;
	}
}