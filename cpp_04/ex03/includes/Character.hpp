
# ifndef CHARACTER_HPP
#define CHARACTER_HPP

//#include <../includes/ICharacter.hpp>
#include <iostream>
#include "AMateria.hpp"

/*
Le Character a un inventaire de 4 items, soit 4 Materias maximum.
À la construction, l’inventaire est vide.
Les Materias sont équipées au premier emplacement vide trouvé,
soit dans l’ordre suivant : de l’emplacement 0 au 3.
Dans le cas où on essaie d’ajouter une Materia à un inventaire plein,
ou d’utiliser/retirer une Materia qui n’existe pas,
ne faites rien (cela n’autorise pas les bugs pour autant).
La fonction membre unequip() ne doit PAS delete la Materia !
Occupez-vous des Materias laissées au sol par votre personnage comme vous le sentez.
Vous pouvez enregistrer l’adresse avant d’appeler unequip(), ou autre,
du moment que vous n’avez pas de fuites de mémoire.
La fonction membre use(int, ICharacter&) utilisera la Materia de l’emplacement[idx],
et passera la cible en paramètre à la fonction AMateria::use.
Votre Character doit comporter un constructeur prenant son nom en paramètre.
Toute copie (avec le constructeur par recopie ou l’opérateur d’affectation) d’un Character doit être profonde.
Ainsi, lors d’une copie, les Materias du Character doivent être
delete avant que les nouvelles ne les remplacent dans l’inventaire.
Bien évidemment, les Materias doivent aussi être supprimées à la destruction d’un Character.
*/

class	Character //: public	ICharacter
{
	private:
		std::string	_name;
		AMateria*	_inventory[4];
	public:
				Character();
				Character( const Character& other );
				Character( const std::string& name );
				~Character();

	const std::string&	getName() const;
	void				setName( const std::string& name );
	void				showInventory() const;
	void				equip( const AMateria& newMateria );
	//void	unequip();
	//void	use( int i, ICharacter& chara );
};

#endif //CHARACTER_HPP