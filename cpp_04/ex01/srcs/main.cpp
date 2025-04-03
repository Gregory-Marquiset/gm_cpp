# include "../includes/Cat.hpp"
# include "../includes/Dog.hpp"

int	main()
{
	const int	n = 4;
	Animal*		animals[n];

	std::cout << "\n--- Creating Cats and Dogs ---\n" << std::endl;
	for ( int i = 0; i < n; i++ )
	{
		if (i % 2 == 0)
			animals[i] = new Cat();
		else
			animals[i] = new Dog();
	}

	std::cout << "\n--- Making Sounds ---\n" << std::endl;
	for ( int i = 0; i < n; i++ )
		animals[i]->makeSound();

	std::cout << "\n--- Deleting Animals ---\n" << std::endl;
	for ( int i = 0; i < n; i++ )
		delete animals[i];

	std::cout << "\n--- Deep Copy Brain Test ---\n" << std::endl;
	Cat	cat1;
	cat1.getBrain()->setIdea( 0, "Je veux dormir" );
	cat1.getBrain()->setIdea( 1, "Je veux manger" );

	Cat cat2( cat1 );
	cat2.setSound( "Miiiiiiaou" );

	cat1.getBrain()->setIdea( 0, "Je veux grimper" );

	std::cout << "\ncat1 sound: " << cat1.getSound() << std::endl;
	std::cout << "cat2 sound: " << cat2.getSound() << std::endl;

	std::cout << "\ncat1 idea[0]: " << cat1.getBrain()->getIdea( 0 ) << std::endl;
	std::cout << "cat2 idea[0]: " << cat2.getBrain()->getIdea( 0 ) << std::endl << std::endl;

	return ( 0 );
}
