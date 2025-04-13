//-------> ./srcs.Character.cpp <-------//

#include "../includes/Character.hpp"

/*
class	Character : public	ICharacter
{
	private:
		std::string	_name;
		AMateria*	_inventory[4];
		Floor*		_floor;
	public:
		Character();
		Character( const Character& other );
		Character( const std::string& name );
		~Character();
		Character&	operator=( const Character& other );

		//-------> ICharacter interface <-------//
		const std::string&	getName() const;
		void				equip( AMateria* m );
		void				unequip( int idx );
		void				use( int idx, ICharacter& target ) const;	

		//-------> Character methode <-------//
		void				setName( const std::string& name );
		void				setFloor( Floor* floor );
		Floor*		getFloor( void ) const;
		void				showInventory( void ) const;
};
*/

Character::Character() : _name( "Anonymous" ), _floor( NULL )
{
	std::cout	<< _name << " character constructor" << std::endl;

	for ( int i = 0; i < 4; i++ )
		_inventory[i] = NULL;
}

Character::Character( const Character& other ) : _name( other.getName() ), _floor( other.getFloor() )
{
	std::cout	<< _name << " character constructor copy" << std::endl;

	for ( int i = 0; i < 4; i++ )
	{
		if ( other._inventory[i] )
			_inventory[i] = other._inventory[i]->clone();
		else
			_inventory[i] = NULL;
	}
}

Character::Character( const std::string& name ) : _name( name ), _floor( NULL )
{
	std::cout << _name << " character constructor name" << std::endl;

	for ( int i = 0; i < 4; i++ )
		_inventory[i] = NULL;
}

Character::~Character()
{
	std::cout << _name << " character destructor" << std::endl;

	int	i = 0;

	while ( i < 4 )
	{
		if ( _inventory[i] )
		{
			delete _inventory[i];
			_inventory[i] = NULL;
		}
		i++;
	}
}

Character&	Character::operator=( const Character& other )
{
	std::cout	<< "Character copy assignment operator called"
				<< std::endl;

	_name = other.getName();
	for ( int i = 0; i < 4; i++ )
	{
		if ( _inventory[i] )
		{
			delete _inventory[i];
			_inventory[i] = NULL;
		}
		if ( other._inventory[i] )
			_inventory[i] = other._inventory[i]->clone();
	}
	_floor = other._floor;

	return ( *this );
}

//-------> ICharacter interface <-------//

const std::string&	Character::getName( void ) const
{
	return ( _name );
}

void				Character::equip( AMateria* m )
{
	if ( !m )
	{
		std::cout	<< "No materia to equip" << std::endl;
		return ;
	}

	for ( int i = 0; i < 4; i++ )
	{
		if ( _inventory[i] == NULL )
		{
			_inventory[i] = m->clone();
			std::cout	<< _name << " equip a new materia type "
						<< m->getType() << std::endl;		
			return ;
		}
	}
}

void				Character::unequip( int idx )
{
	if (idx < 0 || idx >= 4 || !_inventory[idx])
	{
		std::cout	<< "Bad index" << std::endl;
		return ;
	}
	if ( !_floor )
	{
		std::cout	<< "dont find the floor unable to droop materia"
					<< std::endl;
		return ;
	}

	std::cout	<< _name << " unequip "
				<< _inventory[idx]->getType() << std::endl;
	_floor->addMateria( _inventory[idx] );
	_inventory[idx] = NULL;
}

void				Character::use( int idx, ICharacter& target ) const
{
	if ( _inventory[idx] )
		_inventory[idx]->use( target );
}

//-------> Self methode <-------//

void	Character::setName( const std::string& name )
{
	_name = name;
}

void			Character::setFloor( Floor* floor )
{
	if (floor == NULL)
		std::cout	<< _name << " has no floor assigned!" << std::endl;
	else
		std::cout	<< _name << " now knows the floor." << std::endl;
	_floor = floor;
}

Floor*	Character::getFloor( void ) const
{
	return ( _floor );
}

void			Character::showInventory( void ) const
{
	std::cout	<< _name << " inventory:" << std::endl;

	for ( int i = 0; i < 4; i++ )
	{
		std::cout	<< i << ": ";
		if ( _inventory[i])
			std::cout	<< _inventory[i]->getType() << std::endl;
		else
			std::cout	<< "slot vide" << std::endl;
	}
}
