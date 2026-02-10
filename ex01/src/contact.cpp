#include "contact"

// utility methods

bool Contact::IsEmptyLine(const std::string& line) const
{
	return line.find_first_not_of(" \t\n") == std::string::npos;
}

bool Contact::IsValidPhoneNumber(const std::string& line) const
{

}

//setter

bool Contact::SetFirstName(std::string line)
{
	if (IsEmptyLine(line))
		return false;
	first_name_ = line;
	return true;
}

bool Contact::SetLasttName(std::string line)
{
	if (IsEmptyLine(line))
		return false;
	last_name_ = line;
}

bool Contact::SetNickname(std::string line)
{
	if (IsEmptyLine(line))
		return false;
	nickname_ = line;
}

bool Contact::SetPhoneNumber(std::string line)
{
	if (IsEmptyLine(line))
		return false;
	//is digit
	phone_number_ = line;
}

bool Contact::SetDarkestSecret(std::string line)
{
	if (IsEmptyLine(line))
		return false;
	darkest secret_ = line;
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
