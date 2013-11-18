#pragma once

template<class T>
class ARRAY
{
// public functions
public:
	ARRAY(sizeof initSize);
	virtual ~ARRAY(void);
	size_t length() const;

// private members
private:
	T *data;
	static const unsigned int DEFAULT_SIZE = 1;
};

