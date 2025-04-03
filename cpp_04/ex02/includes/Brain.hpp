#ifndef BRAIN_CPP
# define BRAIN_CPP

#include <iostream>

/*Implémentez une classe Brain (cerveau) contenant un tableau de 100 std::string
appelé ideas (idées).*/

class	Brain
{
	private:
		std::string	ideas[100];
	public:
		Brain();
		Brain( const Brain& copy );
		~Brain();
		Brain&	operator=( const Brain& other );

		std::string	getIdea( int i ) const;
		void		setIdea( int i, std::string idea );
};

#endif //BRAIN_CPP