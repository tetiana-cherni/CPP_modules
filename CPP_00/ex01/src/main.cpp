//check Makefile rules to clean test exe_files

#include "phone_book.hpp"

int	main()
{
	PhoneBook	phone_book;
	std::string	line;

	phone_book.PrintBasicMsg();
	while (1)
	{
		phone_book.PrintMsg("Enter command: ", PhoneBook::kCyn, false);
		line = phone_book.ReadLine();
		if (line.compare("ADD") == 0)
		{
			phone_book.PrintMsg("Adding a new contact to the phone book", PhoneBook::kMagenta, true);
			phone_book.AddContact();
		}
		else if (line.compare("SEARCH") == 0)
		{
			if (phone_book.ShowAllContacts())
				phone_book.ShowContact();
		}
		else if (line.compare("EXIT") == 0)
		{
			phone_book.PrintMsg("Close the program. Bye!", PhoneBook::kMagenta, true);
			return (0);
		}
		else
		{
			phone_book.PrintMsg("Unknown command.", PhoneBook::kRed, true);
			phone_book.PrintBasicMsg();
		}
	}
	return (0);
}
