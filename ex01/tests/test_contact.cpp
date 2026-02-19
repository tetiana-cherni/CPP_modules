// c++ -Wall -Wextra -Werror -std=c++17 -o test_contact test_contact.cpp ../src/contact.cpp -I./ -I../include/ -pthread

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "contact.hpp"

TEST_CASE("ContactTests: ConstructorInitialization") {
	Contact c;
	
	CHECK(c.GetFirstName() == "");
	CHECK(c.GetLastName() == "");
	CHECK(c.GetNickname() == "");
	CHECK(c.GetPhoneNumber() == "");
	CHECK(c.GetDarkestSecret() == "");
}

TEST_CASE("ContactTests, SetFirstName") {
	Contact c;
	CHECK(c.SetFirstName("John") == Contact::CheckError::Ok);
	CHECK(c.GetFirstName() == "John");
}

TEST_CASE("ContactTests, SetFirstNameEmpty") {
	Contact c;
	CHECK(c.SetFirstName("") == Contact::CheckError::EmptyLine);
}

TEST_CASE("ContactTests, SetLastName") {
	Contact c;
	CHECK(c.SetLastName("Ride") == Contact::CheckError::Ok);
	CHECK(c.GetLastName() == "Ride");
}

TEST_CASE("ContactTests, SetLastNameEmpty") {
	Contact c;
	CHECK(c.SetLastName("") == Contact::CheckError::EmptyLine);
}

TEST_CASE("ContactTests, SetNickname") {
	Contact c;
	CHECK(c.SetNickname("Ukraine") == Contact::CheckError::Ok);
	CHECK(c.GetNickname() == "Ukraine");
}

TEST_CASE("ContactTests, SetNicknameEmpty") {
	Contact c;
	CHECK(c.SetNickname("") == Contact::CheckError::EmptyLine);
}

TEST_CASE("ContactTests, SetPhoneNumber") {
	Contact c;
	CHECK(c.SetPhoneNumber("+3429844678") == Contact::CheckError::Ok);
	CHECK(c.GetPhoneNumber() == "+3429844678");
	CHECK(c.SetPhoneNumber("123456789") == Contact::CheckError::Ok);
	CHECK(c.GetPhoneNumber() == "123456789");
}

TEST_CASE("ContactTests, SetPhoneNumberEmpty") {
	Contact c;
	CHECK(c.SetPhoneNumber("") == Contact::CheckError::EmptyLine);
}

TEST_CASE("ContactTests, SetPhoneNumberNotNumber") {
	Contact c;
	CHECK(c.SetPhoneNumber("-348") == Contact::CheckError::NotNumber);
	CHECK(c.SetPhoneNumber("12abcd") == Contact::CheckError::NotNumber);
	CHECK(c.SetPhoneNumber("abcd") == Contact::CheckError::NotNumber);
	CHECK(c.SetPhoneNumber("12O34") == Contact::CheckError::NotNumber);
	CHECK(c.SetPhoneNumber("3+48") == Contact::CheckError::NotNumber);
}

TEST_CASE("ContactTests, SetDarkestSecret"){
	Contact c;
	CHECK(c.SetDarkestSecret("DarkestSecret = 42!") == Contact::CheckError::Ok);
	CHECK(c.GetDarkestSecret() == "DarkestSecret = 42!");
}

TEST_CASE("ContactTests, SetDarkestSecretEmpty"){
	Contact c;
	CHECK(c.SetDarkestSecret("") == Contact::CheckError::EmptyLine);
}
