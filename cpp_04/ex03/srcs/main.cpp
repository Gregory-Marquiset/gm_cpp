
# include "../includes/Character.hpp"
# include "../includes/AMateria.hpp"
# include "../includes/Ice.hpp"
# include "../includes/Cure.hpp"
# include "../includes/Floor.hpp"

int	main()
{
	// IMateriaSource*	src = new MateriaSource();
	// src->learnMateria( new Ice());
	// src->learnMateria( new Cure());
	// ICharacter*	me = new Character( "me" );
	// AMateria*	tmp;
	// tmp = src->createMateria( "ice" );
	// me->equip(tmp);
	// tmp = src->createMateria( "cure" );
	// me->equip(tmp);
	// ICharacter*	bob = new Character( "bob" );
	// me->use( 0, *bob );
	// me->use( 1, *bob );
	// delete bob;
	// delete me;
	// delete src;

	//Floor		floor;
	Character	A( "A" );
	Character	B( "B" );

	// A.setFloor( &floor );
	// B.setFloor( &floor );

	Ice		ice;
	Ice		ice2( ice );
	Cure	cure;
	Cure	cure2( cure );
	// A.equip( ice );
	// A.equip( cure );
	// A.equip( ice );
	// A.equip( cure );
	// A.equip( ice );
	A.showInventory();
	A.unequip( 1 );
	// B.equip( ice );
	// B.equip( cure );
	// B.unequip( 1 );
	// B.showInventory();

	return (0);
}
