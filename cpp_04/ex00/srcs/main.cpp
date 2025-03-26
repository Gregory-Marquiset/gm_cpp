# include "../includes/Cat.hpp"
# include "../includes/Dog.hpp"

int	main( void )
{
	Animal	Ani1;
	Cat		Cat1;

	Cat1.setSound( "Miaou" );

	Cat		Cat2( Cat1 );

	Ani1.makeSound();
	Cat1.makeSound();
	Cat2.makeSound();

	Dog		Dog1;

	Dog1.setSound( "Waaf" );

	Dog		Dog2( Dog1 );

	Dog1.makeSound();
	Dog2.makeSound();
	return (0);
}
