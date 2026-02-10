#ifndef CONTACT_H
#define CONTACT_H

// #include <iostream>
#include <string>

class Contact {
	private:
		std::string	first_name_;
		std::string	last_name_;
		std::string	nickname_;
		std::string	phone_number_;
		std::string	darkest_secret_;

		bool IsEmptyLine(std::string line);

	public:
		Contact();
		~Contact();

		bool SetFirstName(std::string line);
		bool SetLastName(std::string line);
		bool SetNickname(std::string line);
		bool SetPhoneNumber(std::string line);
		bool SetDarkestSecret(std::string line);
		const std::string& GetFirstName() const;
		const std::string& GetLastName() const;
		const std::string& GetNickname() const;
		const std::string& GetPhoneNumber() const;
		const std::string& GetDarkestSecret() const;
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