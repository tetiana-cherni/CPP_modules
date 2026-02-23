#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>
#include <cctype>

class Contact {
	private:
		std::string	first_name_;
		std::string	last_name_;
		std::string	nickname_;
		std::string	phone_number_;
		std::string	darkest_secret_;

		bool IsEmptyLine(const std::string& line) const;
		bool IsValidPhoneNumber(const std::string& line) const;

	public:
		enum class CheckError{
			Ok,
			EmptyLine,
			NotNumber
		};

		static const int kFieldsNum = 5;
		Contact();
		~Contact();

		CheckError SetFirstName(std::string line);
		CheckError SetLastName(std::string line);
		CheckError SetNickname(std::string line);
		CheckError SetPhoneNumber(std::string line);
		CheckError SetDarkestSecret(std::string line);
		const std::string& first_name() const;
		const std::string& last_name() const;
		const std::string& nickname() const;
		const std::string& phone_number() const;
		const std::string& darkest_secret() const;
};

#endif

// #ifndef MYCLASS_HPP
// #define MYCLASS_HPP

// #include <string>

// class MyClass {
// private:
//     // Атрибути (naming convention: m_ prefix або _suffix)
//     int m_value;
//     std::string m_name;
//     static int s_count; // Static member declaration

// public:
//     // Constructors
//     MyClass();                           // Default Constructor
//     MyClass(int value, std::string name); // Parameterized Constructor
    
//     // Destructor
//     ~MyClass();
    
//     // Methods (prototypes)
//     void doSomething();
//     int getValue() const;           // Getter (const = не змінює об'єкт)
//     void setValue(int value);       // Setter
    
//     // Static method
//     static int getCount();
// };

// #endif