#include "Array.hpp"

template <typename T>
Array<T>::Array(void) : _content(NULL), _size(0)
{}

// It init the content to 0 (beacause they're pointers)
template <typename T>
Array<T>::Array(unsigned int n) : _content(new T[n]), _size(n)
{}

template <typename T>
Array<T>::~Array(void)
{
	// Check if the content is initialized
	if (_content)
		delete[] _content;
}
