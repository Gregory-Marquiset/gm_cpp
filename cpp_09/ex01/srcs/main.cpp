//-------> ./srcs/Main.cpp <-------//

#include "../includes/BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <cctype>
#include <cstdlib>

bool	IsLeapYear(int year)
{
	return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

bool	IsSpace(const char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (true);
	return (false);
}

bool	IsValidDate(const std::string& date)
{
	if (date.length() != 10)
		return (false);
	if (date[4] != '-' || date[7] != '-')
		return (false);

	for (std::size_t i = 0; i < date.length(); ++i) {
		if (i == 4 || i == 7)
			continue;
		if (!std::isdigit(date[i]))
			return (false);
	}

	int year = std::atoi(date.substr(0, 4).c_str());
	int month = std::atoi(date.substr(5, 2).c_str());
	int day = std::atoi(date.substr(8, 2).c_str());

	if (year < 0 || month < 1 || month > 12 || day < 1)
		return (false);

	int	maxDay = 31;

	if (month == 2)
		maxDay = IsLeapYear(year) ? 29 : 28;
	else if (month == 4 || month == 6 || month == 9 || month == 11)
		maxDay = 30;

	if (day > maxDay)
		return (false);

	return (true);
}

bool	IsAValideValue(const std::string& s)
{
	if (s.empty())
		return (false);

	std::size_t	i			= 0;
	bool		hasDigit	= false;
	bool		hasDot		= false;

	while(IsSpace(s[i]))
		++i;
	if (s[i] == '+' || s[i] == '-')
		++i;

	if (i >= s.length())
		return (false);

	for (; i < s.length(); ++i)
	{
		if (std::isdigit(s[i]))
			hasDigit = (true);
		else if (s[i] == '.')
		{
			if (hasDot)
				return (false);
			hasDot = (true);
		}
		else
			return (false);
	}

	if (!hasDigit)
		return (false);

	return (true);
}

bool	loadDatabase(const std::string& filename, std::map<std::string, float>& rates)
{
	std::ifstream	file(filename.c_str());
	if (!file)
	{
		std::cerr	<< "Error: could not open database file \"" 
					<< filename << "\"" << std::endl;
		return (false);
	}

	std::string		line;
	if (!std::getline(file, line))
		return (false);

	while (std::getline(file, line))
	{
		if (line.empty())
			continue;

		std::istringstream	ss(line);
		std::string			date_str, rate_str, trimDate, trimRate;
		std::size_t			i = 0;
		if (!std::getline(ss, date_str, ',') || !std::getline(ss, rate_str))
			continue;
		while (date_str[i])
		{
			if (!IsSpace(date_str[i]))
				trimDate += date_str[i];
			++i;
		}
		i = 0;
		while (rate_str[i])
		{
			if (!IsSpace(rate_str[i]))
				trimRate += rate_str[i];
			++i;
		}

		std::istringstream	rs(trimRate);
		float				rate;
		if (!IsAValideValue(trimRate) || !(rs >> rate))
			continue;
		if (rate < 0 || rate > 1000)
			continue;
		if (!IsValidDate(trimDate))
			continue;

		rates[trimDate] = rate;
	}

	return (true);
}

bool	readInputFile(const std::string& filename, const std::map<std::string, float>& Database)
{
	std::ifstream			file(filename.c_str());
	if (!file)
	{
		std::cerr	<< "Error: could not open input file \""
					<< filename << "\"" << std::endl;
		return (false);
	}
	if (Database.empty())
	{
		std::cerr	<< "Error: Empty DataBase." << std::endl;
		return (false);
	}

	std::string				line;
	if (!std::getline(file, line))
		return (false);

	while (std::getline(file, line))
	{
		std::istringstream	ss(line);
		std::string			date_str, rate_str, trimDate, trimRate;
		std::size_t			i = 0;
		if (line.empty())
			continue;
		else if (!std::getline(ss, date_str, '|') || !std::getline(ss, rate_str))
		{
			std::cerr << "Error: bad input => " 
					  << line << "\n";
			continue;
		}
		while (date_str[i])
		{
			if (!IsSpace(date_str[i]))
				trimDate += date_str[i];
			++i;
		}
		i = 0;
		while (rate_str[i])
		{
			if (!IsSpace(rate_str[i]))
				trimRate += rate_str[i];
			++i;
		}

		std::istringstream	rs(trimRate);
		float				rate;
		if (!IsAValideValue(trimRate) || !(rs >> rate))
		{
			std::cerr	<< "Error: bad input -> \"" 
						<< trimRate << "\" on line => "
						<< line << std::endl;
			continue;
		}
		if (rate < 0)
		{
			std::cerr	<< "Error: not a positive number."
						<< std::endl;
			continue;
		}
		if (rate > 1000)
		{
			std::cerr	<< "Error: too large a number."
						<< std::endl;
			continue;
		}
		if (!IsValidDate(trimDate))
		{
			std::cerr << "Error: invalid date \"" 
					  << trimDate << "\" on line => "
					  << line << std::endl;
			continue;
		}
		else
		{
			std::map<std::string, float>::const_iterator it = Database.lower_bound(trimDate);
			if (it != Database.end() && it->first == trimDate)
			{
				std::cout	<< trimDate << " => " << rate << " = " << it->second * rate	<< std::endl;
				continue;
			}
			else
			{
				if (it != Database.begin())
				{
					--it;
					std::cout	<< trimDate << " => " << rate << " = " << it->second * rate	<< std::endl;
				}
				else
					std::cerr << "Error: no date <= " << trimDate << " found in database." << std::endl;
			}
		}
	}
	return (true);
}

int	main(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cerr	<< "Error: could not open file." << std::endl;
		return (1);
	}

	std::string						DataFileName	= static_cast<std::string>(argv[1]);
	std::map<std::string, float>	BtcData;

	if (!loadDatabase("data.csv", BtcData))
		return (2);

	if (!readInputFile(DataFileName, BtcData))
		return (3);
	return (0);
}
