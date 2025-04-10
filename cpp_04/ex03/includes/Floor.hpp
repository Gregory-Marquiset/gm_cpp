
# ifndef FLOOR_HPP
#define FLOOR_HPP

#include "AMateria.hpp"

class Floor
{
	private:
		AMateria*	_inventory;
		int			_index;
	public:
		Floor();
		Floor( const Floor& other );
		~Floor();
		Floor&	operator=( const Floor& other );
		
		void	addMateria( AMateria& newMateria );
};

#endif // CHEST_HPP