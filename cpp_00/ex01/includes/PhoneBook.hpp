#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
	private:
		Contact	contacts[8];
		int		currentIndex;
	public:
		PhoneBook();
		void	addContact();
};

#endif //PHONEBOOK_HPP