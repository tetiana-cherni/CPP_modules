#include "phone_book.hpp"

//constructor
PhoneBook::PhoneBook()
{
	#ifdef DEBUG
		std::cout << "PhoneBook constructor called" << std::endl;
	#endif
	next_index_ = 0;
	total_cont_num_ = 0;
}

//destructor
PhoneBook::~PhoneBook()
{
	#ifdef DEBUG
		std::cout << "PhoneBook destructor called" << std::endl;
	#endif
}

//helper
void PhoneBook::PrintErrorMsg(const std::string& err_msg ) const
{
	PrintMsg(err_msg, kRed, true);
}

void PhoneBook::PrintShortMsg(std::string str) const
{
	if (str.length() > 10)
		str = str.substr(0,9) + ".";
	std::cout << std::setw(10) << std::right << str;
}

void PhoneBook::PrintHeaderTable()
{
	PrintShortMsg("Index");
	std::cout << " | ";
	PrintShortMsg("First name");
	std::cout << " | ";
	PrintShortMsg("Last name");
	std::cout << " | ";
	PrintShortMsg("Nickname");
	std::cout << std::endl;
	for (int i = 0; i < 49; i++)
		std::cout << "_" ;
	std::cout << std::endl;
}

void PhoneBook::PrintContact(int index)
{
	PrintMsg("First name: ", kGreen, false);
	PrintMsg(contacts_[index].first_name(), kBlack, true);
	PrintMsg("Last name: ", kGreen, false);
	PrintMsg(contacts_[index].last_name(), kBlack, true);
	PrintMsg("Nickname: ", kGreen, false);
	PrintMsg(contacts_[index].nickname(), kBlack, true);
	PrintMsg("Phone number: ", kGreen, false);
	PrintMsg(contacts_[index].phone_number(), kBlack, true);
	PrintMsg("Darkest secret: ", kGreen, false);
	PrintMsg(contacts_[index].darkest_secret(), kBlack, true);
}

//methods
void PhoneBook::PrintMsg(const std::string& str, const std::string& color, bool print_endl) const
{
	std::cout << color << str << PhoneBook::kResetColor;
	if (print_endl)
		std::cout << std::endl;
}

void PhoneBook::PrintBasicMsg() const
{
	PrintMsg("Choose one of the following commands to use the phone book:", PhoneBook::kMagenta, true);
	PrintMsg("ADD – add a new contact", PhoneBook::kBlue, true);
	PrintMsg("SEARCH – find a contact", PhoneBook::kBlue, true);
	PrintMsg("EXIT – exit the program", PhoneBook::kBlue, true);
}

std::string PhoneBook::ReadLine()
{
	std::string	line;

	if (!std::getline(std::cin, line))
	{
		std::cout << std::endl;
		std::exit(0);
	}
	return line;
}

void PhoneBook::AddContact()
{
	Contact		current_contact;

	AddFirstName(current_contact);
	AddLastName(current_contact);
	AddNickname(current_contact);
	AddPhoneNumber(current_contact);
	AddDarkestSecret(current_contact);

	contacts_[next_index_] = current_contact;
	next_index_ = (next_index_ + 1) % kMaxNum;
	if (total_cont_num_ < kMaxNum)
		total_cont_num_ += 1;
	PrintMsg("Contact added successfully.", kMagenta, true);
}

void PhoneBook::AddFirstName(Contact& contact)
{
	Contact::CheckError	code;
	std::string			line;

	do {
		PrintMsg("First name: ", kCyn, false);
		line = ReadLine();
		code = contact.SetFirstName(line);
		if (code == Contact::CheckError::EmptyLine)
			PrintErrorMsg(kEmptyLine);
	} while (code != Contact::CheckError::Ok);
}

void PhoneBook::AddLastName(Contact& contact)
{
	Contact::CheckError	code;
	std::string			line;

	do {
		PrintMsg("Last name: ", kCyn, false);
		line = ReadLine();
		code = contact.SetLastName(line);
		if (code == Contact::CheckError::EmptyLine)
			PrintErrorMsg(kEmptyLine);
	} while (code != Contact::CheckError::Ok);
}

void PhoneBook::AddNickname(Contact& contact)
{
	Contact::CheckError	code;
	std::string			line;

	do {
		PrintMsg("Nickname: ", kCyn, false);
		line = ReadLine();
		code = contact.SetNickname(line);
		if (code == Contact::CheckError::EmptyLine)
			PrintErrorMsg(kEmptyLine);
	} while (code != Contact::CheckError::Ok);
}

void PhoneBook::AddPhoneNumber(Contact& contact)
{
	Contact::CheckError	code;
	std::string			line;

	do {
		PrintMsg("Phone number: ", kCyn, false);
		line = ReadLine();
		code = contact.SetPhoneNumber(line);
		if (code == Contact::CheckError::EmptyLine)
			PrintErrorMsg(kEmptyLine);
		else if (code == Contact::CheckError::NotNumber)
			PrintErrorMsg(kNotDigit);
	} while (code != Contact::CheckError::Ok);
}

void PhoneBook::AddDarkestSecret(Contact& contact)
{
	Contact::CheckError	code;
	std::string			line;

	do {
		PrintMsg("Darkest Secret: ", kCyn, false);
		line = ReadLine();
		code = contact.SetDarkestSecret(line);
		if (code == Contact::CheckError::EmptyLine)
			PrintErrorMsg(kEmptyLine);
	} while (code != Contact::CheckError::Ok);
}


bool PhoneBook::ShowAllContacts()
{
	std::string	str;

	if (total_cont_num_ == 0)
	{
		PrintMsg("The phonebook is currently empty.", kRed, true);
		return false;
	}
	PrintHeaderTable();
	for (int i = 0; i < total_cont_num_; i++)
	{
		str = std::to_string(i);
		PrintShortMsg(str);
		std::cout << " | ";
		PrintShortMsg(contacts_[i].first_name());
		std::cout << " | ";
		PrintShortMsg(contacts_[i].last_name());
		std::cout << " | ";
		PrintShortMsg(contacts_[i].nickname());
		std::cout << std::endl;
	}
	return true;
}

void PhoneBook::ShowContact()
{
	std::string	input;
	std::string	num;

	num = std::to_string(total_cont_num_ - 1);
	while (1)
	{
		PrintMsg("Enter contact index: ", kCyn, false);
		input = ReadLine();
		if (input.length() == 1 && input.find_first_not_of("01234567") == std::string::npos)
		{
			if (std::stoi(input) < total_cont_num_)
				break;
		}
		PrintMsg("Invalid input. Please enter a single digit from 0 to " + num, kRed, true);
	}
	PrintContact(std::stoi(input));
}

// void PhoneBook::ShowContact()
// {
// 	std::string	input;
// 	std::string	num;

// 	num = std::to_string(total_cont_num_ - 1);
// 	while (1)
// 	{
// 		PrintMsg("Enter contact index: ", kCyn, false);
// 		input = ReadLine();
// 		if (input.length() == 1 && input.find_first_not_of("01234567") == std::string::npos)
// 		{
// 			if (std::stoi(input) >= total_cont_num_)
// 			{
// 				PrintMsg("This index doesn't exist. Check what we have in th phone book", kRed, true);
// 				ShowAllContacts();
// 			}
// 			else
// 				break;
// 		}
// 		else
// 			PrintMsg("Invalid input. Please enter a single digit from 0 to " + num, kRed , true);
// 	}
// 	PrintContact(std::stoi(input));
// }