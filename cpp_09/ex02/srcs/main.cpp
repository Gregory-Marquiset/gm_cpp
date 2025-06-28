//-------> ./srcs/Main.cpp <-------//

#include "../includes/PmergeMe.hpp"

int	main(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cerr	<< "Error: must have two arguments." << std::endl;
		return (1);
	}

	std::string	Input = argv[1];

	std::vector<int>	Vector;
	try
	{
		PmergeMe	Merge(Input, Vector);
	}
	catch(const std::exception& e)
	{
		std::cerr	<< "Error: " << e.what() << std::endl;
	}

	std::deque<int>	Deque;
	try
	{
		PmergeMe	Merge(Input, Deque);
	}
	catch(const std::exception& e)
	{
		std::cerr	<< "Error: " << e.what() << std::endl;
	}

	return (0);
}
