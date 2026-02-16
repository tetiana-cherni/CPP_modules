#include "contact"

//constructor
Contact::Contact()
{
	#ifndef DEBUG
		std::cout << "Contact constructor called" << std::endl;
	#endif

	first_name_ = "";
	last_name_ = "";
	nickname_ = "";
	phone_number_ = "";
	darkest_secret_ = "";
}

//destructor
Contact::~Contact()
{
	#ifndef DEBUG
		std::cout << "Contact constructor called" << std::endl;
	#endif
}

// utility methods
bool Contact::IsEmptyLine(const std::string& line) const
{
	return line.find_first_not_of(" \t\n") == std::string::npos;
}

bool Contact::IsValidPhoneNumber(const std::string& line) const
{
	return line.find_first_not_of("+0123456789") == std::string::npos;
}

//setter

CheckError Contact::SetFirstName(std::string line)
{
	if (IsEmptyLine(line))
		return CheckError::EmptyLine;
	first_name_ = line;
	return CheckError::Ok;
}

CheckError Contact::SetLasttName(std::string line)
{
	if (IsEmptyLine(line))
		return CheckError::EmptyLine;
	last_name_ = line;
	return CheckError::Ok;
}

CheckError Contact::SetNickname(std::string line)
{
	if (IsEmptyLine(line))
		return CheckError::EmptyLine;
	nickname_ = line;
	return CheckError::Ok;
}

CheckError Contact::SetPhoneNumber(std::string line)
{
	if (IsEmptyLine(line))
		return CheckError::EmptyLine;
	if (IsValidPhoneNumber(line))
		return CheckError::NotNumber;
	phone_number_ = line;
	return CheckError::Ok;
}

CheckError Contact::SetDarkestSecret(std::string line)
{
	if (IsEmptyLine(line))
		return CheckError::EmptyLine;
	darkest secret_ = line;
	return CheckError::Ok;
}

//getter

const std::string& Contact::GetFirstName()
{
	return first_name_ ;
}

const std::string& Contact::GetLasttName()
{
	return last_name_ ;
}

const std::string& Contact::GetNickname()
{
	return nickname_ ;
}

const std::string& Contact::GetPhoneNumber()
{
	return phonenumber_ ;
}

const std::string& Contact::GetDarkestSecret()
{
	return darkestsecret_ ;
}
