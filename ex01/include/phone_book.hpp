#ifndef PHONE_BOOK_HPP
#define PHONE_BOOK_HPP

#include "contact.hpp"
#include <iomanip>

class PhoneBook {
	private:
		static const int	kMaxNum = 8;
		Contact 			contacts_[kMaxNum];
		int					next_index_;
		int					total_cont_num_;

		// error messages
		const std::string kEmptyLine = "This field cannot be empty. Please try again.";
		const std::string kNotDigit = "Phone number must contain only digits. Please try again.";

		void PrintErrorMsg(const std::string& err_msg ) const;
		void PrintShortMsg(std::string str) const;
		void PrintHeaderTable();
		void PrintContact(int index);

	public:

// colors, inline makes only one copy of variable (from standart 17)
	static inline const std::string kRed = "\033[1;31m";
	static inline const std::string kBlue = "\033[1;34m";
	static inline const std::string kGreen = "\033[1;32m";
	static inline const std::string kMagenta = "\033[1;35m";
	static inline const std::string kCyn = "\e[1;36m";
	static inline const std::string kBlack = "\e[0;30m";
	static inline const std::string kResetColor = "\033[0m";

	PhoneBook();
	~PhoneBook();

	void AddContact();
	void AddFirstName(Contact& contact);
	void AddLastName(Contact& contact);
	void AddNickname(Contact& contact);
	void AddPhoneNumber(Contact& contact);
	void AddDarkestSecret(Contact& contact);

	void PrintMsg(const std::string& str, const std::string& color, bool print_endl) const;
	void PrintBasicMsg() const;
	std::string ReadLine();
	bool ShowAllContacts();
	void ShowContact();

};

#endif

