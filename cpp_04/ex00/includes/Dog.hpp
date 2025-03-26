# ifndef DOG_HPP
#define DOG_HPP

# include "Animal.hpp"

class Dog : public Animal
{
	protected:
		std::string	_sound;
	public:
		Dog();
		Dog( const Dog& copy );
		~Dog();

		Dog&	operator=( const Dog& other );

		void		setSound( std::string sound );
		std::string	getSound( void ) const;
		void		makeSound( void ) const;
};

#endif	//DOG_HPP