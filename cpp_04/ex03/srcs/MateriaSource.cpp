//-------> ./srcs.MateriaSource.cpp <-------//

#include "../includes/MateriaSource.hpp"

/*
class	MateriaSource : public IMateriaSource
{
	private:
		AMateria*	_templates[4];
	public:
		MateriaSource();
		MateriaSource( const MateriaSource& other );
		~MateriaSource();
		MateriaSource&	operator=( const MateriaSource& other );

		//-------> IMateriaSource interface <-------//
		void		learnMateria( AMateria* );
		AMateria*	createMateria( const std::string& type );

		//-------> Self methode <-------//
};
*/

MateriaSource::MateriaSource()
{
	std::cout	<< "MateriaSource constructor" << std::endl;

	for ( int i = 0; i < 4; i++ )
		_templates[i] = NULL;
}

MateriaSource::MateriaSource( const MateriaSource& other )
{
	std::cout	<< "MateriaSource constructor copy" << std::endl;

	for ( int i = 0; i < 4; i++ )
		_templates[i] = other._templates[i];
}

MateriaSource::~MateriaSource()
{
	std::cout	<< "MateriaSource destructor" << std::endl;
}

MateriaSource&	MateriaSource::operator=( const MateriaSource& other )
{
	std::cout	<< "AMateria copy assignment operator called"
				<< std::endl;

	if ( this != &other )
	{
		for ( int i = 0; i < 4; i++ )
			_templates[i] = other._templates[i];
	}
	return ( *this );
}

//-------> IMateriaSource interface <-------//

void		MateriaSource::learnMateria( AMateria* )
{
	
}

AMateria*	MateriaSource::createMateria( const std::string& type )
{
	std::cout	<< type << std::endl;

	return ( NULL );
}

//-------> Self methode <-------//
