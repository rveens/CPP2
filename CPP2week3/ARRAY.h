#pragma once

#include <exception>

template<typename T>
class ARRAY
{
// public functions
public:
	ARRAY(void) : mpData(new T[DEFAULT_SIZE]() ), mCapacity(DEFAULT_SIZE)
	{
		
	}

	ARRAY(size_t initSize) : mpData(new T[initSize]() ), mCapacity(initSize)
	{
		
	}

	virtual ~ARRAY(void)
	{
		delete[] this->mpData;
	}

	T &operator[](size_t position)
	{
		size_t t = this->capacity();

		if (position < 0 || position > (this->capacity() - 1) )
			throw std::out_of_range("ARRAY position out of range");

		return this->mpData[position];
	}

	size_t length() const
	{
		size_t tempSizeCounter, tempCapacity;

		tempSizeCounter = 0;
		tempCapacity = this->capacity();

		for (size_t i = 0; i < tempCapacity; ++i)
			if (this->mpData[i])
				tempSizeCounter++;

		return tempSizeCounter;
	}

	size_t capacity() const
	{
		return mCapacity;
	}

	bool append(T newObject)
	{
		return false;
		//if (this->mIndex < this->capacity()) {
		//	for(size_t i = 0; i < this->capacity(); ++i)
		//		if (!this->mpData[i]) {
		//			this->mpData[this->size++];
		//			break;
		//		}
		//	return true;
		//} else if (this->mIndex == this->capacity()) { // hij is vol
		//	 TODO maak een kopie, vernietig het oude, alloceer nieuw en zet terug.

		//	 kopie maken
		//	T *mpDataTemporaryCopy = new T[this->capacity()];
		//	memcpy(mpDataTemporaryCopy, mpData, this->capacity());

		//	 nieuwe array grootte maken.
		//	delete[] this->mpData;
		//	this->mpData = new T[sizeof(mpDataTemporaryCopy) + 1];

		//	 oude data terug zetten
		//	memcpy(this->mpData, mpDataTemporaryCopy, sizeof(mpDataTemporaryCopy));

		//	 nieuw object toevoegen
		//	this->mpData[this->mIndex++];
		//} else
		//	return false;
	}

// private members
private:
	T *mpData;
	size_t mCapacity;
	static const unsigned int DEFAULT_SIZE = 1;
};

