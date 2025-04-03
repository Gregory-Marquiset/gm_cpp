# include "../includes/Animal.hpp"

Animal::Animal( void )
{
	_type = "Animal";
	std::cout << "Default constructor for Animal as been called"
			  << std::endl;
}

Animal::Animal( const Animal& copy )
{
	_type = copy._type;
	std::cout << "Copy constructor for Animal as been called"
			  << std::endl;
}

Animal::~Animal( void )
{
	std::cout << "Destructor for Animal as been called"
			  << std::endl;
}

Animal&	Animal::operator=( const Animal& other )
{
	std::cout << "Copy assignment operator called"
			  << std::endl;
	if (this != &other)
		_type = other.getType();
	return( *this );
}

std::string	Animal::getType() const
{
	return ( _type );
}

// void		Animal::makeSound() const
// {
// 	std::cout << "This "
// 			  << _type
// 			  << " make no sound"
// 			  << std::endl;
// }
