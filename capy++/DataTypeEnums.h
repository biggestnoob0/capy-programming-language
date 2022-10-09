#pragma once
#include <string>
#include <vector>

using std::vector;
namespace DataTypes {

	enum DataTypeCategory
	{
		character,
		StringCat,
		integer,
		floatNumber,
		boolean
	};

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

	enum AllDataTypes
	{
		Character,
		U_Character,
		Character16,
		U_Character16,
		String,
		String16,
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
		ERROR_TYPE
	};

}