#pragma once

#include <exception>

template<typename T>
class ARRAY
{
// public functions
public:
	ARRAY(void) : mpData(nullptr), mCapacity(DEFAULT_SIZE)
	{
		
	}

	ARRAY(size_t initSize) : mpData(new T[initSize]() ), mCapacity(initSize)
	{
		
	}

	virtual ~ARRAY(void)
	{
		delete[] this->mpData;
	}

	T &operator[](int position)
	{
		int t = this->capacity();

		if (position == -1) {
			this->increaseSize(1);
			position = this->capacity() - 1;
		}

		if (position < 0 || position > (this->capacity() - 1) )
			throw std::out_of_range("ARRAY position out of range");

		return this->mpData[position];
	}

	int length() const
	{
		int tempSizeCounter, tempCapacity;

		tempSizeCounter = 0;
		tempCapacity = this->capacity();

		for (int i = 0; i < tempCapacity; ++i)
			if (this->mpData[i])
				tempSizeCounter++;

		return tempSizeCounter;
	}

	int capacity() const
	{
		return mCapacity;
	}

	void increaseSize(size_t amount)
	{
		T *mpDataTemporaryCopy = nullptr;

		// kopie maken
		if (this->mpData) {
			mpDataTemporaryCopy = new T[this->capacity()]();
			memcpy(mpDataTemporaryCopy, mpData, this->capacity());

			delete[] this->mpData;
		}

		// nieuwe array grootte maken.
		this->mpData = new T[this->capacity() + amount]();

		// oude data terug zetten
		if (mpDataTemporaryCopy) {
			memcpy(this->mpData, mpDataTemporaryCopy, this->capacity());
			delete[] mpDataTemporaryCopy;
		}

		// capacity is nu een groter geworden.
		this->mCapacity += amount;
	}

	bool append(T newObject)
	{
		// zoek een leeg plekje.
		if (this->mpData) {
		for (int i = 0; i < this->capacity() - 1; ++i)
			if (!this-mpData[i]) {
				// leeg plekje gevonden.
				this->mpData[i] = newObject;
				return true;
			}
		}

		// geen leeg plekje gevonden. we moeten geheugen alloceren.
		increaseSize(1);

		// gegeven waarden achteraan gooien.
		this->mpData[this->capacity() - 1] = newObject;

		return true;
	}

// private members
private:
	T *mpData;
	int mCapacity;
	static const unsigned int DEFAULT_SIZE = 0;
};

