# ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>

class	AMateria
{
	protected:
		std::string	_type;
	public:
		AMateria();
		AMateria( const std::string& type );
		~AMateria();

		void				setType( const std::string& type );
		const std::string&	getType() const; //Returns the materia type
		virtual AMateria*	clone() const = 0;
		//virtual void		use( ICharacter& target );
};

#endif //AMATERIA_HPP