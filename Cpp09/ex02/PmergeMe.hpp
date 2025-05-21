#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <list>

class PmergeMe
{
	private:
		PmergeMe(const PmergeMe &src);
		PmergeMe&	operator=(const PmergeMe &pmergeMe);

	public:
		PmergeMe();
		~PmergeMe();

		std::vector<int>	sortVector(const std::vector<int>& array);
		std::list<int>		sortList(const std::list<int>& list);
};

#endif