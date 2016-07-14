#pragma once

template< class T>
class Wrapper
{
public:
	Wrapper()
	{
		DataPtr = 0;
	}

	Wrapper(const T& inner)
	{
		DataPtr = inner.clone();
	}

	Wrapper(const Wrapper<T>& original)
	{
		if (original.DataPtr != 0) {
			DataPtr = original.DataPtr->clone();
		}
		else {
			DataPtr = 0;
		}
	}

	Wrapper(T* fDataPtr)
	{
		DataPtr = fDataPtr;
	}

	~Wrapper()
	{
		if (DataPtr != 0)
			delete DataPtr
	}
	
	T& operator=(const Wrapper<T>& original)
	{
		if (this != &original) {
			delete DataPtr;
			DataPtr = original.DataPtr != 0 ? original.DataPtr->clone() : 0;
		}
		
		return *this;
	}

	T& operator* ()
	{
		return *DataPtr;
	}

	const T& operator*() const
	{
		return *DataPtr;
	}

	const T* const operator->() const
	{
		return DataPtr;
	}

	T* operator->()
	{
		return DataPtr;
	}

private:
	T* DataPtr;

};