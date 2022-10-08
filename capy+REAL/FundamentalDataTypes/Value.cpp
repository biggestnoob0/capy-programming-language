#include "Value.h"

template <typename T>
Value<T>::Value(T val) {
	this->valueHeld = val;
}