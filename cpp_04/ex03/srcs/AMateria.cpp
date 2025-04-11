
#include "../includes/AMateria.hpp"

/*
class	AMateria
{
	protected:

	public:
		AMateria();
		AMateria( std::string const & type );
		~AMateria();

		std::string	const &	getType() const; //Returns the materia type
		virtual AMateria*	clone() const = 0;
		//virtual void		use( ICharacter& target );
};
*/

AMateria::AMateria( void )
{
    std::cout << "AMateria constructor" << std::endl;
    _type = "Basique";
}

AMateria::AMateria( const std::string& type ) : _type( type )
{
    std::cout << "AMateria constructor type" << std::endl;
}

AMateria::~AMateria( void )
{
    std::cout << "AMateria destructor" << std::endl;
}

void    AMateria::setType( const std::string& type )
{
    _type = type;
}

const std::string& AMateria::getType( void ) const 
{
    return ( _type );
}