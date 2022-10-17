#include "Variable.h"
template <typename T>
Variable<T>::Variable(string name, T value, AllTypes type) {
	this->varName = name;
	this->ValueHeld = value;
	this->varType = type;
}