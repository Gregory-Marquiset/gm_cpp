
# include "../includes/Character.hpp"
# include "../includes/AMateria.hpp"
# include "../includes/Ice.hpp"

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

	Character	chara;
	std::cout << chara.getName() << std::endl;
	Ice			ice;
	std::cout << ice.getType() << std::endl;
	chara.equip( ice );
	chara.showInventory();
	
	return (0);
}
