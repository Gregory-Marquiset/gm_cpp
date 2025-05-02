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

// 		const std::string	getName() const;
// 		int					getGrade() const;
// 		void				incrementGrade();
// 		void				decrementGrade();
// };

// std::ostream&	operator<<(std::ostream& os, const Bureaucrat& b);

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{}

Bureaucrat::~Bureaucrat()
{}

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
	_grade--;
}

void				Bureaucrat::decrementGrade()
{
	_grade++;
}

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& b)
{
	os << b.getName() << ", bureaucrat grade " << b.getGrade();
	return (os);
}
