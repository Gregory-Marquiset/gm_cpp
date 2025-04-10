
#include "../includes/Floor.hpp"

Floor::Floor( void ) : _index( 0 )
{
	std::cout << "Floor constructor" << std::endl;
	_inventory = NULL;
}

Floor::Floor( const Floor& other ) : _index( 0 )
{
	std::cout << "Floor constructor copy" << std::endl;
	_inventory = other._inventory;
}

Floor::~Floor( void )
{
    std::cout << "Floor destructor" << std::endl;
	if ( _inventory )
		delete _inventory;
}

Floor&	Floor::operator=( const Floor& other )
{
	std::cout << "Floor assignement copy" << std::endl;
	if ( this != &other )
	{
		int	i = 0;
		while ( &other._inventory[i] )
			i++;
		_inventory = new AMateria[i];
		for ( int idx = 0; idx < i; idx++ )
			_inventory[idx] = other._inventory[idx];
	}
}

void	Floor::addMateria( AMateria& newMateria )
{
	if ( _index == 50 )
		_index = 0;
	delete _inventory[_index];
	_inventory[_index] = &newMateria;
	_index++;
}
