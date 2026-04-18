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