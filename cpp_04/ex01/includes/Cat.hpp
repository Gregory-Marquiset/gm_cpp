# ifndef CAT_HPP
#define CAT_HPP

# include "Animal.hpp"

class Cat : public Animal
{
	protected:
		std::string	_sound;
		Brain*		_brain;
	public:
		Cat();
		Cat( const Cat& copy );
		~Cat();

		Cat& operator=( const Cat& other );

		void		setSound( std::string sound );
		std::string	getSound() const;
		void		makeSound() const;
		Brain*		getBrain() const;
};

#endif	//CAT_HPP