# include "../includes/Cat.hpp"

Cat::Cat( void ) : Animal()
{
	_type = "Cat";
	_brain = new Brain();
	_sound = "Miaou";
	std::cout << "Default constructor for Cat as been called"
			  << std::endl;
}

Cat::Cat( const Cat& copy ) : Animal( copy)
{
	*this = copy;
	_brain = new Brain( *copy._brain );
	_sound = copy._sound;
	std::cout << "Copy constructor for Cat as been called"
			  << std::endl;
}

Cat::~Cat( void )
{
	delete	_brain;
	std::cout << "Destructor for Cat as been called"
			  << std::endl;
}

Cat&	Cat::operator=( const Cat& other )
{
	std::cout << "Copy assignment operator called"
			  << std::endl;
	if (this != &other)
	{
		_type = other.getType();
		_sound = other.getSound();
	}
	return( *this );
}

void	Cat::makeSound( void ) const
{
	std::cout << "This "
			  << _type
			  << " make a "
			  << _sound
			  << std::endl;
}

void	Cat::setSound( std::string sound )
{
	_sound = sound;
}

std::string	Cat::getSound( void ) const
{
	return ( _sound );
}

Brain*	Cat::getBrain() const
{
	return ( _brain );
}