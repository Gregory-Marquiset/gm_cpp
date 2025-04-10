
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

Character::Character( void )
{
	std::cout << "constructeur" << std::endl;
	_name = "Greg";
	for ( int i = 0; i < 4; i++ )
		_inventory[i] = NULL;
}

Character::Character( const std::string& name )
{
	std::cout << "constructeur name" << std::endl;
	_name = name;
	for ( int i = 0; i < 4; i++ )
		_inventory[i] = NULL;
}

Character::Character( const Character& other )
{
	std::cout << "constructeur copy" << std::endl;
	_name = other._name;
	for ( int i = 0; i < 4; i++ )
		_inventory[i] = other._inventory[i];
}

Character::~Character( void )
{
	std::cout << "destructeur" << std::endl;
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
	for ( int i = 0; i < 3; i++ )
	{
		if ( _inventory[i] != NULL)
			std::cout << "1: "<< _inventory[i]->getType() << std::endl;
	}
}

void		Character::equip( const AMateria& newMateria )
{
	for ( int i = 0; i < 4; i++ )
	{
		if ( _inventory[i] == NULL )
		{
			_inventory[i] = newMateria.clone();
			break ;
		}
	}
}