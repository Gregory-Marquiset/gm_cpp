# include "../includes/Brain.hpp"

Brain::Brain( void )
{
	std::cout << "Default constructor for Brain as been called"
			  << std::endl;
}

Brain::Brain( const Brain& copy )
{
	*this = copy;
	std::cout << "Copy constructor for Brain as been called"
			  << std::endl;
}

Brain::~Brain( void )
{
	std::cout << "Destructor for Brain as been called"
			  << std::endl;
}

Brain&	Brain::operator=( const Brain& other )
{
	std::cout << "Copy assignment operator called"
			  << std::endl;
	if ( this != &other )
	{
		for ( int i = 0; i < 100; i++ )
			ideas[i] = other.ideas[i];
	}
	return( *this );
}

std::string Brain::getIdea( int i ) const
{
	if ( i < 0 || i >= 100 )
		return ( "" );
	return ( ideas[i] );
}

void        Brain::setIdea( int i, std::string idea )
{
	if ( i < 0 || i >= 100 )
		return ;
	ideas[i] = idea;
	return ;
}