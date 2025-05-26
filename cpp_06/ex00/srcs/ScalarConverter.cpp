//-------> ./srcs/ScalarConverter.cpp <-------//

#include "../includes/ScalarConverter.hpp"

		//-------> SConv class <-------//

SConv::SConv()
{}

SConv::SConv(const SConv& copy)
{
	*this = copy;
}

SConv&	SConv::operator=(const SConv& other)
{
	if (this != &other)
		return (*this);
	return (*this);
}

SConv::~SConv()
{}

		//-------> Other <-------//

// int		: (-2147483648 - 2147483647)
// float	: dot, exposant and f at the end (nanf -inff +inff)
// double	: dot and exposant (nan -inf +inf)

bool		checkTrim(t_trimUtils& u, const std::string& literal)
{
	// Règles générales
	if (u.i != literal.size())
		return (false);
	if (u.sign > 1 || u.dot > 1 || u.exp > 1)
		return (false);

	// Vérifie que le signe est bien en première position s'il existe
	if (u.sign == 1 && u.signPos > 0)
		return (false);

	// Vérifie la position du point par rapport à l'exposant
	if (u.expPos > -1 && u.dotPos > u.expPos)
		return (false);

	// Empêche . ou e au tout début (sauf si seul caractère)
	if (literal.size() > 1 && (u.dotPos == 0 || u.expPos == 0))
		return (false);

	// Empêche "+.1", "+e1", "-.1", "-e1"
	if (u.sign == 1 &&
		((u.dot == 1 && u.dotPos == 1) || (u.exp == 1 && u.expPos == 1)))
		return (false);

	// Empêche "1e", "1." etc.
	if ((u.exp == 1 && u.trimed.length() > 1 && u.expPos == (int)u.trimed.length() - 1) ||
		(u.dot == 1 && u.trimed.length() > 1 && u.dotPos == (int)u.trimed.length() - 1))
		return (false);

	// Empêche les cas type "1.e" ou "1e."
	if (u.dot == 1 && u.exp == 1 && u.expPos == u.dotPos + 1)
		return (false);

	return (true);
}

std::string	trimString(const std::string& literal)
{
	t_trimUtils	u;

	if (literal.size() == 1)
	{
		u.trimed += literal[0];
		return (u.trimed);
	}
	while (u.i < literal.size() && std::isspace(literal[u.i]))
		u.i++;
	while (u.i < literal.size() && !std::isspace(literal[u.i]))	
	{
		if (literal[u.i] == '+' || literal[u.i] == '-')
		{
			u.sign++;
			u.signPos = u.trimed.length();
		}
		else if (literal[u.i] == '.')
		{
			u.dot++;
			u.dotPos = u.trimed.length();
		}
		else if (literal[u.i] == 'e' || literal[u.i] == 'E')
		{
			u.exp++;
			u.expPos = u.trimed.length();
			if (literal[u.i + 1] && (literal[u.i + 1] == '+' || literal[u.i + 1] == '-'))
				u.i++;
		}
		u.trimed += literal[u.i];
		u.i++;
	}
	while (u.i < literal.size() && std::isspace(literal[u.i]))
		u.i++;
	if (checkTrim(u, literal))
		return (u.trimed);
	else
		return ("");
}

bool	isChar(const std::string& s)
{
	if (s.length() == 1 && std::isprint(s[0]) && !std::isdigit(s[0]))
		return (true);
	return (false);
}

bool	isInt(const std::string& s)
{
	std::size_t	i = 0;
	long		testConvL = 0;

	if (s[i] == '+' || s[i] == '-')
		i++;
	while (s[i] == '0')
		i++;
	if (i == s.length() && s[i] == '0')
		return (true);
	for (std::size_t idx = i; idx < s.length(); ++idx)
		if (!std::isdigit(s[idx]) || idx - i > 10)
			return (false);
	testConvL = std::atol(s.c_str());
	if (testConvL > 2147483647 || testConvL < -2147483648)
		return (false);
	return (true);
}

bool	isFloat(const std::string& s)
{
	if (s == "nanf" || s == "+inff" || s == "-inff")
		return (true);
	if (s[s.length() - 1] != 'f')
		return (false);
	if (s[s.length() - 2] == '.' || s[s.length() - 2] == 'e' || s[s.length() - 2] == 'E'
			|| s[s.length() - 2] == '+' || s[s.length() - 2] == '-')
		return (false);
	
	std::size_t	i = 0;

	if (s[i] == '+' || s[i] == '-')
		i++;
	for (std::size_t idx = i; idx < s.length() - 1; idx++)
	{
		if (!std::isdigit(s[idx]) && s[idx] != '.' && s[idx] != 'e' && s[idx] != 'E' && s[idx] != '-' && s[idx] != '+')
			return (false);
	}
	return (true);
}

bool	isDouble(const std::string& s)
{
	if (s == "nan" || s == "+inf" || s == "-inf")
		return (true);
	if (s[s.length() - 1] == '.' || s[s.length() - 1] == 'e' || s[s.length() - 1] == 'E'
			|| s[s.length() - 1] == '+' || s[s.length() - 1] == '-')
		return (false);
	if (s.find('.') == std::string::npos && s.find('e') == std::string::npos && s.find('E') == std::string::npos)
		return (false);

	std::size_t	i = 0;

	if (s[i] == '+' || s[i] == '-')
		i++;
	for (std::size_t idx = i; idx < s.length() - 1; idx++)
	{
		if (!std::isdigit(s[idx]) && s[idx] != '.' && s[idx] != 'e' && s[idx] != 'E' && s[idx] != '-' && s[idx] != '+')
			return (false);
	}
	return (true);
}

std::string	dtostr_cpp98(int value)
{
	std::ostringstream	oss;

	oss	<< value;
	return (oss.str());
}

void	printConv(const std::string& s, enum e_type type)
{
	std::string	strChar = "";
	int			cInt = 0;
	std::string	strInt = "";
	float		cFloat = 0.0f;
	std::string	strFloat = "";
	double		cDouble = 0.0;
	std::string	strDouble = "";

	if (type == CHAR_TYPE)
	{
		strChar = s[0];
		strInt = dtostr_cpp98((int)strChar[0]);
		strFloat = dtostr_cpp98((int)strChar[0]);
		strFloat += ".0f";
		strDouble = dtostr_cpp98((int)strChar[0]);
		strDouble += ".0";
	}
	else if (type == INT_TYPE)
	{
		cInt = std::atoi(s.c_str());
		strInt = dtostr_cpp98(cInt);
		if (cInt > -1 && cInt < 128)
		{
			if (std::isprint(cInt))
				strChar = (char)cInt;
			else
				strChar = "non displayable";
		}
		else
			strChar = "impossible";
		cFloat = static_cast<float>(cInt);
		strFloat = dtostr_cpp98(cFloat);	//	ne peut etre precis avec plus de 16 777 216
		strFloat += ".0f";
		strDouble = dtostr_cpp98(cInt);		// limite de precition 9 007 199 254 740 992
		strDouble += ".0";
	}
	/*else if (type == FLOAT_TYPE)
	{}
	else if (type == DOUBLE_TYPE)
	{}*/

	std::cout	<< "char: " << strChar << std::endl;
	std::cout	<< "int: " << strInt << std::endl;
	std::cout	<< "float: " << strFloat << std::endl;
	std::cout	<< "double: " << strDouble << std::endl;
}

		//-------> Checker utils <-------//

e_type	checkChar(const std::string& s)
{ return (isChar(s) ? CHAR_TYPE : UNKNOWN_TYPE); }

e_type	checkInt(const std::string& s)
{ return (isInt(s) ? INT_TYPE : UNKNOWN_TYPE); }

e_type	checkFloat(const std::string& s)
{ return (isFloat(s) ? FLOAT_TYPE : UNKNOWN_TYPE); }

e_type	checkDouble(const std::string& s)
{ return (isDouble(s) ? DOUBLE_TYPE : UNKNOWN_TYPE); }

t_checker	checkers[] =
{
	{ "char", checkChar, CHAR_TYPE },
	{ "int", checkInt, INT_TYPE },
	{ "float", checkFloat, FLOAT_TYPE },
	{ "double", checkDouble, DOUBLE_TYPE }
};

		//-------> Self methode <-------//

void	SConv::convert(const std::string& literal)
{
	std::string	literalTrimed = trimString(literal);
	if (literalTrimed.empty())
		throw unknownTypeException();
	for (int i = 0; i < 4; i++)
	{
		if (checkers[i].check(literalTrimed) != UNKNOWN_TYPE)
		{
			std::cout << checkers[i].name << std::endl;
			printConv(literalTrimed, checkers[i].type);
			return ;
		}
	}
	throw unknownTypeException();
}

		//-------> Self Exceptions <-------//

const char*	SConv::unknownTypeException::what() const throw()
{ return ("Unknown type provided!"); }

const char*	SConv::outOfRangeException::what() const throw()
{ return ("Variable is out of range!"); }
