#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

// The third parameter can be an instantiated function template
template<typename T, typename Func>
void	iter(T *array_addr, int len, Func func)
{
	for (int i = 0; i < len; i++)
		func(array_addr[i]);
}

#endif