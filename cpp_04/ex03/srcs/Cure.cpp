
#include "../includes/Cure.hpp"

Cure::Cure( void ) : AMateria::AMateria( "cure" ), _type( "cure" )
{
    std::cout << _type << " constructor" << std::endl;
}

Cure::Cure( const Cure& other ) : AMateria::AMateria( other ), _type( other._type )
{
    std::cout << _type << " constructor copy" << std::endl;
}

Cure::Cure( const std::string& type ) : AMateria::AMateria( type ), _type( type )
{
    std::cout << _type << " constructor type" << std::endl;
}

Cure::~Cure( void )
{
    std::cout << _type << " destructor" << std::endl;
}

AMateria*       Cure::clone( void ) const
{
    return ( new Cure( *this ));
}