
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

Ice::Ice( void ) : AMateria::AMateria( "Ice" )
{
	std::cout << "Ice constructeur" << std::endl;
	//_type = "Ice";
}

Ice::Ice( const Ice& other ) : AMateria::AMateria( other )
{
	std::cout << "Ice constructeur copy" << std::endl;
	_type = other._type;
}

Ice::Ice( const std::string& type ) : AMateria::AMateria( type )
{
	std::cout << "Ice constructeur type" << std::endl;
	_type = type;
}

Ice::~Ice( void )
{
	std::cout << "Ice destructor" << std::endl;
}

AMateria*	Ice::clone( void ) const
{
	return ( new Ice( *this ));
}