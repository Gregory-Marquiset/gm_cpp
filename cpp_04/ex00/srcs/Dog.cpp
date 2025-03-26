# include "../includes/Dog.hpp"

Dog::Dog( void )
{
	_type = "Dog";
	std::cout << "Default constructor for Dog as been called"
			  << std::endl;
}

Dog::Dog( const Dog& copy ) : Animal( copy )
{
	*this = copy;
	std::cout << "Copy constructor for Dog as been called"
			  << std::endl;
}

Dog::~Dog( void )
{
	std::cout << "Destructor for Dog as been called"
			  << std::endl;
}

Dog&	Dog::operator=( const Dog& other )
{
	std::cout << "Copy assignment operator called"
			  << std::endl;
	if ( this != &other )
	{
		_type = other.getType();
		_sound = other.getSound();
	}
	return ( *this );
}

void		Dog::setSound( std::string sound )
{
	_sound = sound;
}

std::string	Dog::getSound( void ) const
{
	return ( _sound );
}

void		Dog::makeSound( void ) const
{
	std::cout << "This "
			  << _type
			  << " make a "
			  << _sound
			  << std::endl;
}
