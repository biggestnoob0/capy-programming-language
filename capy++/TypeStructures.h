#pragma once
#include <string>
#include <vector>
#include <unordered_map>

using std::vector;
using std::string;
namespace DataTypes {

	/*enum DataTypeCategory
	{
		character,
		StringCat,
		integer,
		floatNumber,
		boolean
	};*/

	//enum CharacterDataTypes
	//{
	//	character,
	//	u_Character,
	//	character16,
	//	u_Character16
	//};
	//enum StringDataTypes
	//{
	//	String,
	//	u_String,
	//	string16,
	//	u_String16
	//};
	//enum IntegerDataTypes
	//{
	//	byte,
	//	u_Byte,
	//	int16,
	//	u_Int16,
	//	integer,
	//	u_Integer,
	//	int64,
	//	u_Int64
	//};
	//enum FloatDataTypes
	//{
	//	currency,
	//	floatNumber,
	//	u_FloatNumber,
	//	doubleNumber,
	//	u_DoubleNumber
	//};
	//enum boolDataTypes
	//{
	//	boolean
	//};

	enum AllTypes
	{
		Character,
		String,
		Byte,
		U_Byte,
		Int16,
	    U_Int16,
		Integer,
		U_Integer,
		Int64,
		U_Int64,
		Currency,
		FloatNumber,
		U_FloatNumber,
		DoubleNumber,
		U_DoubleNumber,
		Boolean,
		Addition,
		Subtraction,
		Multiplication,
		Division,
		Integer_Division,
		Modulus,
		AND,
		OR,
		NOT,
		ERROR_TYPE,
		NO_TYPE
	};
	struct DataTypeMap
	{
		std::unordered_map<string, AllTypes> typesMapped{};
		DataTypeMap();
	};
}