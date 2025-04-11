
#include "../includes/Character.hpp"

// class	Character //: public	ICharacter
// {
// 	private:
// 		std::string	_name;
// 		//AMateria*	_inventory[4];
// 	public:
// 			Character();
// 			Character( const Character& other );
// 			Character( const std::string& name );
// 			~Character();

// 	std::string	getName() const;
// 	void		setName( std::string name );
//	void				equip( const AMateria& newMateria );
// 	//void	unequip();
// 	//void	use( int i, ICharacter& chara );
// };

Character::Character( void ) : _name( "Greg" ), _floor( NULL )
{
	std::cout << "Character constructor" << std::endl;
	for ( int i = 0; i < 4; i++ )
		_inventory[i] = NULL;
}

Character::Character( const std::string& name ) : _name( name ), _floor( NULL )
{
	std::cout << "Character constructor name" << std::endl;
	for ( int i = 0; i < 4; i++ )
		_inventory[i] = NULL;
}

Character::Character( const Character& other ) : _name( other._name ), _floor( other._floor )
{
	std::cout << "Character constructor copy" << std::endl;

	for ( int i = 0; i < 4; i++ )
		_inventory[i] = other._inventory[i];
}

Character::~Character( void )
{
	std::cout << "Character destructor" << std::endl;

	int	i = 0;
	while ( i < 4)
	{
		if ( _inventory[i] )
		{
			delete _inventory[i];
			_inventory[i] = NULL;
		}
		i++;
	}
}

void				Character::setFloor( Floor* floor )
{
	if (floor == NULL)
		std::cout << _name << " has no floor assigned!" << std::endl;
	else
		std::cout << _name << " now knows the floor." << std::endl;

	_floor = floor;
}

std::string	const &	Character::getName( void ) const
{
	return ( _name );
}

void		Character::setName( const std::string& name )
{
	_name = name;
}

void	Character::showInventory( void ) const
{
	std::cout << _name << " inventory:" << std::endl;

	for ( int i = 0; i < 4; i++ )
	{
		if ( _inventory[i] != NULL)
			std::cout << i + 1 << ": "<< _inventory[i]->getType() << std::endl;
	}
}

void		Character::equip( const AMateria& newMateria )
{
	std::cout << _name << " equip a new materia" << std::endl;

	for ( int i = 0; i < 4; i++ )
	{
		if ( _inventory[i] == NULL )
		{
			_inventory[i] = newMateria.clone();
			break ;
		}
	}
}

void		Character::unequip( const int idx )
{
	if ( _inventory[idx - 1] && _floor)
	{
		std::cout << _name << " unequip " << _inventory[idx - 1]->getType() << std::endl;
	
		_floor->addMateria( _inventory[idx - 1] );
		_inventory[idx - 1] = NULL;
	}
}