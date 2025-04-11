
#include "../includes/Floor.hpp"

Floor::Floor( void ) : _inventory( NULL ), _index( 0 )
{
	std::cout << "Floor constructor" << std::endl;
}

Floor::Floor( const Floor& other ) : _index( 0 )
{
	std::cout << "Floor constructor copy" << std::endl;

	if ( other._inventory )
	{
		int	i = 0;
		while ( other._inventory[i] )
			i++;
		_inventory = new AMateria*[i];
		while ( other._inventory[_index] )
		{
			_inventory[_index] = other._inventory[_index]->clone();
			_index++;
		}
		_inventory[_index] = NULL;
	}
	else
		_inventory = NULL;
}

Floor::~Floor( void )
{
    std::cout << "Floor destructor" << std::endl;

	while ( _inventory )
	{
		for (int i = 0; i < _index; i++)
			delete _inventory[i];
		delete[] _inventory;
		_inventory = NULL;
	}
}

Floor&	Floor::operator=( const Floor& other )
{
	std::cout << "Floor assignement copy" << std::endl;

	if ( this != &other )
	{
		if ( _inventory )
		{
			for ( int i = 0; _inventory[i]; i++ )
				delete _inventory[i];
		}
		delete[] _inventory;
		int i = 0;
		while ( other._inventory[i] )
			i++; 
		_inventory = new AMateria*[i];
		for ( int idx = 0; idx < i; idx++ )
			_inventory[idx] = other._inventory[idx];
	}
	return ( *this );
}

void	Floor::addMateria( AMateria* newMateria )
{
	std::cout << newMateria->getType() << " drop on the foor" << std::endl;

	AMateria**	tmp = new AMateria*[_index + 2];
	if ( _inventory )
	{
		for ( int i = 0; _inventory[i]; i++ )
			tmp[i] = _inventory[i];
	}
	delete[] _inventory;
	tmp[_index] = newMateria;
	tmp[_index + 1] = NULL;
	_inventory = tmp;
	_index++;
}
