//-------> ./includes.AMateria.hpp <-------//

# ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include "IMateriaSource.hpp"

class	ICharacter;

class	AMateria
{
	protected:
		std::string	_type;
	public:
		AMateria();
		AMateria( const AMateria& other );
		AMateria( const std::string& type );
		virtual ~AMateria();
		AMateria&	operator=( const AMateria& other );

		//-------> IMateriaSource interface <-------//
		void		learnMateria( AMateria* );
		AMateria*	createMateria( const std::string& type );

		//-------> Self methode <-------//
		void				setType( const std::string& type );
		const std::string&	getType( void ) const;
		virtual AMateria*	clone( void ) const = 0;
		virtual void		use( ICharacter& target );
};

#endif // AMATERIA_HPP
