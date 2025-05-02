//-------> ./includes/Bureaucrat.cpp <-------//

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <string>
#include <iostream>


class	Bureaucrat
{
	private:
		std::string		_name;
		int				_grade;
	public:
		Bureaucrat(std::string name, int grade);
		~Bureaucrat();

		const std::string	getName() const;
		int					getGrade() const;
		void				incrementGrade();
		void				decrementGrade();
};

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& b);

# endif	//	BUREAUCRAT_HPP