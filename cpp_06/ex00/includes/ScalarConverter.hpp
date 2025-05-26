//-------> ./includes/ScalarConverter.hpp <-------//

# ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <cstdlib>
#include <cctype>
#include <sstream>

		//-------> Checker utils <-------//

enum	e_type
{
	CHAR_TYPE,
	INT_TYPE,
	FLOAT_TYPE,
	DOUBLE_TYPE,
	UNKNOWN_TYPE,
	OUT_TYPE
};

typedef	e_type	(*typeChecker)(const std::string&);

typedef struct	s_checker
{
	const char*	name;
	typeChecker	check;
	e_type		type;
}	t_checker;

		//-------> SConv class <-------//

class	SConv
{
	private :
		SConv();
		SConv(const SConv& copy);
		~SConv();
		SConv&	operator=(const SConv& other);
		static const t_checker	_checkerTable[4];
	public :
		//-------> Self methode <-------//
		static void	convert(const std::string& literal);

		//-------> Self Exceptions <-------//
		class	unknownTypeException : public std::exception
		{
			public :
				const char*	what() const throw();
		};
		class	outOfRangeException : public std::exception
		{
			public :
				const char*	what() const throw();
		};
};

		//-------> Other <-------//

typedef struct	s_trimUtils
{
	std::string	trimed;
	std::size_t	i;
	std::size_t	sign;
	int			signPos;
	std::size_t	dot;
	int			dotPos;
	std::size_t	exp;
	int			expPos;
	s_trimUtils() :
		trimed(""), i(0), sign(0), signPos(-1), dot(0), dotPos(-1), exp(0), expPos(-1) {}
}	t_trimUtils;

#endif //	SCALARCONVERTER_HPP