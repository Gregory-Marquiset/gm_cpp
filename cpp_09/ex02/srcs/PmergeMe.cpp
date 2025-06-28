//-------> ./srcs/PMERGEME.cpp <-------//

#include "../includes/PmergeMe.hpp"

PmergeMe::PmergeMe()
{}

PmergeMe::PmergeMe(const PmergeMe& Other)
{
	*this = Other;
}

PmergeMe::~PmergeMe()
{}

PmergeMe&	PmergeMe::operator=(const PmergeMe& Other)
{
	if (this != &Other)
	{
		std::cout	<< "copy called." << std::endl;
	}
	return (*this);
}

const char*	PmergeMe::InvalideContainerException::what() const throw()
{
	return ("invalide container type.");
}

const char*	PmergeMe::ZeroIntegerException::what() const throw()
{
	return ("zero value is not allowed.");
}

const char*	PmergeMe::NegatifIntegerException::what() const throw()
{
	return ("negative value is not allowed.");
}

const char*	PmergeMe::InvalideTokenException::what() const throw()
{
	return ("only positive integer is allowed.");
}

//__________________________________________//

void	PmergeMe::CheckUserInput(const std::string& Input)
{
	std::istringstream	Split(Input);
	std::string			Token;
	int					Num;

	while (Split >> Token)
	{
		std::istringstream	conv(Token);

		if(!(conv >> Num) || !(conv.eof()))
			throw(InvalideTokenException());
		if (Num == 0)
			throw(ZeroIntegerException());
		else if (Num < 0)
			throw(NegatifIntegerException());
	}
}
