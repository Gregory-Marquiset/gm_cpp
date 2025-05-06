//-------> ./srcs/Bureaucrat.cpp <-------//

# include "../includes/Bureaucrat.hpp"

// class	Bureaucrat
// {
// 	private:
// 		std::string		_name;
// 		int				_grade;
// 	public:
// 		Bureaucrat(std::string name, int grade);
// 		~Bureaucrat();

// 		//-------> Self methode <-------//
// 		const std::string	getName() const;
// 		int					getGrade() const;
// 		void				incrementGrade();
// 		void				decrementGrade();

// 		//-------> Self Exceptions <-------//
// 		class	GradeTooHighException : public std::exception
// 		{
// 			public:
// 				const char*	what() const throw();
// 		};
// 		class	GradeTooLowException : public std::exception
// 		{
// 			public:
// 				const char* what() const throw();
// 		};
// };

//		//-------> Other <-------//
// std::ostream&	operator<<(std::ostream& os, const Bureaucrat& b);


Bureaucrat::Bureaucrat(std::string name, int grade) :
	_name(name)
{
	if (grade < 1)
		throw GradeTooLowException();
	if (grade > 150)
		throw GradeTooHighException();
	_grade = grade;
}

Bureaucrat::~Bureaucrat()
{}

 		//-------> Self methode <-------//

const std::string	Bureaucrat::getName() const
{
	return (_name);
}

int					Bureaucrat::getGrade() const
{
	return (_grade);
}

void				Bureaucrat::incrementGrade()
{
	if (_grade - 1 < 1)
		throw GradeTooHighException();
	_grade--;
}

void				Bureaucrat::decrementGrade()
{
	if (_grade + 1 > 150)
		throw GradeTooLowException();
	_grade++;
}

 		//-------> Self Exceptions <-------//

const char*	Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char*	Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

		//-------> Other <-------//

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& b)
{
	os << b.getName() << ", bureaucrat grade " << b.getGrade();
	return (os);
}
