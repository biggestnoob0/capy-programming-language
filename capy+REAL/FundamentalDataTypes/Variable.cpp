#include "Variable.h"
template <typename T>
Variable<T>::Variable(string name, T value) {
	this->varName = name;
	this->ValueHeld = value;
}