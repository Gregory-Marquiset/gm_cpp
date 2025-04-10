# ifndef ICE_HPP
#define ICE_HPP

#include <iostream>
#include "AMateria.hpp"

class	Ice : public AMateria
{
	private:
		std::string		_type;
	public:
		Ice();
		Ice( const Ice& other);
		Ice( const std::string& type);
		~Ice();

		AMateria*	clone() const;
};

#endif //ICE_HPP