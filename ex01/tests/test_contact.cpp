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


