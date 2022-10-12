#include "TypeStructures.h"
using namespace DataTypes;

DataTypeMap::DataTypeMap()
{
	typesAsStringsNoUnsigned["char"] = "char";
	typesAsStringsNoUnsigned["string"] = "string";
	typesAsStringsNoUnsigned["bool"] = "bool";
	typesAsStringsNoUnsigned["byte"] = "byte";
	typesAsStringsNoUnsigned["int16"] = "int16";
	typesAsStringsNoUnsigned["int"] = "int";
	typesAsStringsNoUnsigned["int64"] = "int64";
	typesAsStringsNoUnsigned["float"] = "float";
	typesAsStringsNoUnsigned["double"] = "double";
}