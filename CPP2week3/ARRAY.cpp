#include "ARRAY.h"


template<class T>
ARRAY::ARRAY(sizeof initSize) : data(new T[initSize])
{
}

template<class T>
ARRAY::~ARRAY(void)
{
}

template<class T>
size_t ARRAY::length() const
{
	return sizeof(this->data)
}