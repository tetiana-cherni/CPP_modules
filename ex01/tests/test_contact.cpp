// c++ -Wall -Wextra -Werror -std=c++17 -o test_contact test_contact.cpp ../src/contact.cpp -I./ -I../include/ -pthread

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "contact.hpp"

TEST_SUITE("Contact"){

	TEST_CASE("ConstructorInitialization") {
		Contact c;

		CHECK(c.GetFirstName() == "");
		CHECK(c.GetLastName() == "");
		CHECK(c.GetNickname() == "");
		CHECK(c.GetPhoneNumber() == "");
		CHECK(c.GetDarkestSecret() == "");
	}

	TEST_CASE("Setters validation and modofocation"){

		Contact c;

		SUBCASE("FirstName") {
			CHECK(c.SetFirstName("John") == Contact::CheckError::Ok);
			CHECK(c.GetFirstName() == "John");
			CHECK(c.SetFirstName("") == Contact::CheckError::EmptyLine);
		}

		SUBCASE("LastName"){
			CHECK(c.SetLastName("Ride") == Contact::CheckError::Ok);
			CHECK(c.GetLastName() == "Ride");
			CHECK(c.SetLastName("") == Contact::CheckError::EmptyLine);
		}

		SUBCASE("Nickname"){
			CHECK(c.SetNickname("Ukraine") == Contact::CheckError::Ok);
			CHECK(c.GetNickname() == "Ukraine");
			CHECK(c.SetNickname("") == Contact::CheckError::EmptyLine);
		}

		SUBCASE("PhoneNumber"){
			//valid input
				CHECK(c.SetPhoneNumber("+3429844678") == Contact::CheckError::Ok);
				CHECK(c.GetPhoneNumber() == "+3429844678");
				CHECK(c.SetPhoneNumber("123456789") == Contact::CheckError::Ok);
				CHECK(c.GetPhoneNumber() == "123456789");
				
			// invalid input
				CHECK(c.SetPhoneNumber("") == Contact::CheckError::EmptyLine);
				CHECK(c.SetPhoneNumber("-348") == Contact::CheckError::NotNumber);
				CHECK(c.SetPhoneNumber("12abcd") == Contact::CheckError::NotNumber);
				CHECK(c.SetPhoneNumber("abcd") == Contact::CheckError::NotNumber);
				CHECK(c.SetPhoneNumber("12O34") == Contact::CheckError::NotNumber);
				CHECK(c.SetPhoneNumber("3+48") == Contact::CheckError::NotNumber);
		}

		SUBCASE("DarkestSecret"){
				CHECK(c.SetDarkestSecret("DarkestSecret = 42!") == Contact::CheckError::Ok);
				CHECK(c.GetDarkestSecret() == "DarkestSecret = 42!");
				CHECK(c.SetDarkestSecret("") == Contact::CheckError::EmptyLine);
		}
	}
}
