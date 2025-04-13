//-------> ./srcs.Floor.cpp <-------//

#include "../includes/Floor.hpp"

/*
class	Floor
{
	private:
		AMateria**	_inventory;
		int			_index;
	public:
		Floor();
		Floor( const Floor& other );
		~Floor();
		Floor&	operator=( const Floor& other );

		//-------> Self methode <-------//
		void	addMateria( AMateria* newMateria );
		void	floorCheck( void ) const;
};
*/

Floor::Floor( void ) : _inventory( NULL ), _index( 0 )
{
	std::cout	<< "Floor constructor" << std::endl;
}

Floor::Floor( const Floor& other ) : _index( 0 )
{
	std::cout	<< "Floor constructor copy" << std::endl;

	if ( other._inventory )
	{
		int	i = 0;

		while ( other._inventory[i] )
			i++;
		_inventory = new AMateria*[i + 1];
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
    std::cout	<< "Floor destructor" << std::endl;

	if ( _inventory )
	{
		for ( int i = 0; i < _index; i++ )
			delete _inventory[i];
		delete[] _inventory;
	}
}

Floor&	Floor::operator=( const Floor& other )
{
	std::cout	<< "Floor assignement copy" << std::endl;

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
			_inventory[idx] = other._inventory[idx]->clone();
		_index = i;
		_inventory[_index] = NULL;
	}

	return ( *this );
}

//-------> Self methode <-------//

void	Floor::addMateria( AMateria* newMateria )
{
	std::cout	<< newMateria->getType()
				<< " drop on the foor" << std::endl;

	AMateria**	tmp = new AMateria*[_index + 2];
	for ( int i = 0; i < _index; i++ )
		tmp[i] = _inventory[i];
	tmp[_index] = newMateria;
	tmp[_index + 1] = NULL;
	delete[] _inventory;
	_inventory = tmp;
	_index++;
}

void	Floor::floorCheck( void ) const
{
	std::cout	<< "There is " << _index
				<< " materia on the floor" << std::endl;
}