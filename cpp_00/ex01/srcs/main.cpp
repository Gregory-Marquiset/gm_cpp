# include "../includes/PhoneBook.hpp"

int	main()
{
	PhoneBook phoneBook;
	std::string command;

	while (true)
	{
		std::cout << "Enter command: ";
		std::getline(std::cin, command);
		if (command == "EXIT")
			break ;
		else if (command == "ADD")
			std::cout << "Command ADD." << std::endl;
		else if (command == "SEARCH")
			std::cout << "Command SEARCH." << std::endl;
		else
			std::cout << "Command invalide." << std::endl;
	}
	return (0);
}