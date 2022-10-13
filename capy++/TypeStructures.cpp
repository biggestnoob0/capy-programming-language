#include "TypeStructures.h"
using namespace DataTypes;

DataTypeMap::DataTypeMap()
{
	
	typesMapped["char"] = Character;
	typesMapped["string"] = String;
	typesMapped["bool"] = Boolean;
	typesMapped["byte"] = Byte;
	typesMapped["int16"] = Int16;
	typesMapped["int"] = Integer;
	typesMapped["int64"] = Int64;
	typesMapped["float"] = FloatNumber;
	typesMapped["double"] = DoubleNumber;

	typesMapped["usign byte"] = U_Byte;
	typesMapped["usign int16"] = U_Int16;
	typesMapped["usign int"] = U_Integer;
	typesMapped["usign int64"] = U_Int64;
	typesMapped["usign float"] = U_FloatNumber;
	typesMapped["usign double"] = U_DoubleNumber;
}