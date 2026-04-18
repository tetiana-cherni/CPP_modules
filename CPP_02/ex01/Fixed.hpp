#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string_view>
#include <cmath> 

class Fixed {
	private:
		int					raw_value_;
		static const int	kFractionalBits = 8; //scaling factor 2^8

	public:
		Fixed();
		~Fixed();
		Fixed(const int num);
		Fixed(const float num);
		Fixed(const Fixed& other);
		Fixed& operator=(const Fixed& other);

		int getRawBits(void) const;
		void setRawBits(int const raw);

		float toFloat(void) const;
		int toInt(void) const;
};

	std::ostream& operator<<(std::ostream& output_stream, const Fixed& f);
	void PrintMsg(const std::string_view& msg);

#endif