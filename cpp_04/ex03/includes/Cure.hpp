
# ifndef CURE_HPP
#define CURE_HPP

#include <iostream>
#include "AMateria.hpp"

class   Cure : public AMateria
{
    private:
        std::string    _type;
    public:
        Cure();
        Cure( const Cure& other );
        Cure ( const std::string& type );
        ~Cure();

        AMateria*   clone() const;
};

#endif //CURE_HPP