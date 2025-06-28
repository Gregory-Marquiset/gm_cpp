//-------> ./includes/PMERGEME.hpp <-------//

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <sstream>
#include <fstream>
#include <typeinfo>

class	PmergeMe
{
	private:
		void	CheckUserInput(const std::string& Input);

	public:
		PmergeMe();
		PmergeMe(const PmergeMe& Other);
		~PmergeMe();
		PmergeMe&	operator=(const PmergeMe& Other);
		template<typename Container>
		PmergeMe(const std::string& Input, Container& C)
		{
			if (typeid(C) != typeid(std::vector<int>) &&
				typeid(C) != typeid(std::deque<int>))
				throw(InvalideContainerException());
			CheckUserInput(Input);
		}

	class	InvalideContainerException : public std::exception
	{
		const char*	what() const throw();
	};
	class	ZeroIntegerException : public std::exception
	{
		const char*	what() const throw();
	};
	class	NegatifIntegerException : public std::exception
	{
		const char*	what() const throw();
	};
	class	InvalideTokenException : public std::exception
	{
		const char*	what() const throw();
	};
};

#endif //	PMERGEME_HPP
