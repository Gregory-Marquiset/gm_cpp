# ifndef CAT_HPP
#define CAT_HPP

# include "Animal.hpp"

class Cat : public Animal
{
	protected:
		std::string	_sound;
	public:
		Cat();
		Cat( const Cat& copy );
		~Cat();

		Cat& operator=( const Cat& other );

		void		setSound( std::string sound );
		std::string	getSound() const;
		void		makeSound() const;
};

#endif	//CAT_HPP