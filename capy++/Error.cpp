#include "Error.h"

Error::Error(string message, int line, string type) {
	//TESTING ONLY
	std::cout << "ERROR" << std::endl;
	namespace fs = std::filesystem;
	int i = 0;
	if (currentLogFile.empty()) {
		while (true) {
			if (!fs::exists(directoryBase + "/logs/Log-" + std::to_string(i) + ".txt")) {
				std::ofstream stream{ directoryBase + "/logs/Log-" + std::to_string(i) + ".txt" };
				currentLogFile = directoryBase + "/logs/Log-" + std::to_string(i) + ".txt";
				stream << type + ":" << std::endl << message + " AT: " + std::to_string(line) << std::endl;
				break;
			}
		}
	}
	else {
		std::ofstream stream{ currentLogFile };
		stream << type + ":" << std::endl << message + " AT: " + std::to_string(line) << std::endl;
	}
}