//-------> ./srcs/Main.cpp <-------//

# include "../includes/Bureaucrat.hpp"

int	main()
{
	Bureaucrat b("greg", 42);
	std::cout << b << std::endl;
	b.incrementGrade();
	std::cout << b << std::endl;
	b.decrementGrade();
	std::cout << b << std::endl;
	return ( 0 );
}
