//-------> ./includes.Character.hpp <-------//

# ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <../includes/ICharacter.hpp>
#include "../includes/Floor.hpp"

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

		//-------> Self methode <-------//
		void				setName( const std::string& name );
		void				setFloor( Floor* floor );
		Floor*				getFloor( void ) const;
		void				showInventory( void ) const;
};

#endif // CHARACTER_HPP
