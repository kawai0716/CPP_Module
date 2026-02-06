template <typename T>
const char* Array<T>::OutOfBounds::what() const throw()
{
	return "Array index out of bounds";
}

template <typename T>
Array<T>::Array() : _data(0), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : _data(0), _size(n)
{
	if (_size > 0)
		_data = new T[_size]();
}

template <typename T>
Array<T>::Array(const Array& other) : _data(0), _size(other._size)
{
	if (_size > 0)
	{
		_data = new T[_size]();
		for (unsigned int i = 0; i < _size; ++i)
			_data[i] = other._data[i];
	}
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other)
{
	if (this == &other)
		return *this;
	T* newData = 0;
	if (other._size > 0)
	{
		newData = new T[other._size]();
		for (unsigned int i = 0; i < other._size; ++i)
			newData[i] = other._data[i];
	}
	delete[] _data;
	_data = newData;
	_size = other._size;
	return *this;
}

template <typename T>
Array<T>::~Array()
{
	delete[] _data;
}

template <typename T>
unsigned int Array<T>::size() const
{
	return _size;
}

template <typename T>
T& Array<T>::operator[](unsigned int index)
{
	if (index >= _size)
		throw OutOfBounds();
	return _data[index];
}

template <typename T>
const T& Array<T>::operator[](unsigned int index) const
{
	if (index >= _size)
		throw OutOfBounds();
	return _data[index];
}
