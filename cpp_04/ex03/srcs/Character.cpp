
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

// 	//void	unequip();
// 	//void	use( int i, ICharacter& chara );
// };

Character::Character( void )
{}

Character::Character( const Character& other )
{}

Character::Character( const std::string& name )
{}

Character::~Character( void )
{
    std::cout << "destructeur" << std::endl;
}