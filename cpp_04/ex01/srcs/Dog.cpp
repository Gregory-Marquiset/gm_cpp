# include "../includes/Dog.hpp"

Dog::Dog( void )
{
	_type = "Dog";
	_brain = new Brain();
	_sound = "Waaf";
	std::cout << "Default constructor for Dog as been called"
			  << std::endl;
}

Dog::Dog( const Dog& copy ) : Animal( copy )
{
	*this = copy;
	_brain = new Brain( *copy._brain );
	_sound = copy._sound;
	std::cout << "Copy constructor for Dog as been called"
			  << std::endl;
}

Dog::~Dog( void )
{
	delete	_brain;
	std::cout << "Destructor for Dog as been called"
			  << std::endl;
}

Dog&	Dog::operator=( const Dog& other )
{
	std::cout << "Copy assignment operator called"
			  << std::endl;
	if ( this != &other )
	{
		Animal::operator=( other );
		delete _brain;
		_brain = new Brain( *other._brain );
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

Brain*	Dog::getBrain() const
{
	return ( _brain );
}