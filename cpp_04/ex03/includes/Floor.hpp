//-------> ./includes.Floor.hpp <-------//

# ifndef FLOOR_HPP
#define FLOOR_HPP

#include "AMateria.hpp"

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

#endif // FLOOR_HPP
