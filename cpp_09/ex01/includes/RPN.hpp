//-------> ./includes/RPN.hpp <-------//

#ifndef RPN_CPP
#define RPN_CPP

#include <stack>
#include <list>
#include <string>
#include <iostream>

class	RPN
{
	private:
		std::stack< float, std::list<float> > _Pile;
	public:
		RPN();
		RPN(const RPN& Other);
		RPN(const std::string& Equation);
		~RPN();
		RPN&    operator=(const RPN& Other);

		class	NoEquationException : public std::exception
		{
			const char*	what() const throw();
		};
		class	NumberTooHightException : public std::exception
		{
			const char*	what() const throw();
		};
};

#endif //	RPN_CPP
