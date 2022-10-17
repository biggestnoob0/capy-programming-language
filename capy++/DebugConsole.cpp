#include "DebugConsole.h"
using namespace Debugging;

void Debugging::WriteIdentifierToConsole(Identifier& identifier)
{
	cout << "name: " + identifier.name << endl;
	cout << "user defined type: " + std::to_string(identifier.userDefinedType) << endl;
	cout << "overall type: " + std::to_string(identifier.type) << endl;
}
