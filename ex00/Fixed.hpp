
// https://cppreference.net/cpp/language/as_operator.html
// https://cppreference.net/cpp/language/classes.html
// https://www.geeksforgeeks.org/cpp/shallow-copy-and-deep-copy-in-c/
// https://www.linkedin.com/pulse/understanding-bitwise-copying-c-what-every-developer-should-el-bana-sqa1f/
// https://stackoverflow.com/questions/42749439/what-is-the-difference-between-memberwise-copy-bitwise-copy-shallow-copy-and-d

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <iomanip>
#include <string_view>

class Fixed {
	private:
		int					fixed_value_;
		static const int	kFractionValue_ = 8;
	
	public:
		Fixed();
		~Fixed();
		Fixed(const Fixed& other);
		Fixed& operator=(const Fixed& other);
	
		int getRawBits(void) const;
		void setRawBits(int const raw);
		void PrintMsg(const std::string_view& msg) const;

};

#endif