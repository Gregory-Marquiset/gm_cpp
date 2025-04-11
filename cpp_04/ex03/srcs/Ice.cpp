
#include "../includes/Ice.hpp"

/*
class	Ice
{
	private:
		std::string		_type;
	public:
		Ice();
		Ice( const Ice& other);
		~Ice();
};
*/

Ice::Ice( void ) : AMateria::AMateria( "ice" ), _type( "ice" )
{
	std::cout << _type << " constructeur" << std::endl;
}

Ice::Ice( const Ice& other ) : AMateria::AMateria( other ), _type( other._type )
{
	std::cout << _type << " constructeur copy" << std::endl;
}

Ice::Ice( const std::string& type ) : AMateria::AMateria( type ), _type( type )
{
	std::cout << _type << " constructeur type" << std::endl;
}

Ice::~Ice( void )
{
	std::cout << _type << " destructor" << std::endl;
}

AMateria*	Ice::clone( void ) const
{
	return ( new Ice( *this ));
}