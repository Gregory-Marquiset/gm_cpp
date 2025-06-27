//-------> ./srcs/RPN.cpp <-------//

#include "../includes/RPN.hpp"

RPN::RPN()
{}

RPN::RPN(const RPN& Other)
{
	*this = Other;
}

RPN::RPN(const std::string& Equation)
{
	if (Equation.empty())
		throw(NoEquationException());
	std::cout	<< "Open with: " << Equation << std::endl;
}

RPN::~RPN()
{}

RPN&	RPN::operator=(const RPN& Other)
{
	if (this != &Other)
		_Pile = Other._Pile;
	return (*this);
}

const char*	RPN::NoEquationException::what() const throw()
{
	return ("no equation to solve.");
}

const char*	RPN::NumberTooHightException::what() const throw()
{
	return ("number greater than 10.");
}