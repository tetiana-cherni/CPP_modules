#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath> 

class Fixed {
	private:
		int					raw_value_; //mantissa M
		static const int	kFractionalBits = 8; //scaling factor 2^8	
	public:
		Fixed();
		~Fixed();
		Fixed(const int num);
		Fixed(const float num);
		Fixed(const Fixed& other); //copy constructor
		Fixed& operator=(const Fixed& other); //copy assignment operator
	
		int getRawBits(void) const;
		void setRawBits(int const raw);

		float toFloat(void) const;
		int toInt(void) const;

	//comparison operators
		bool operator>(const Fixed& right_side) const;
		bool operator<(const Fixed& right_side) const;
		bool operator>=(const Fixed& right_side) const;
		bool operator<=(const Fixed& right_side) const;
		bool operator==(const Fixed& right_side) const;
		bool operator!=(const Fixed& right_side) const;

	//arithmetic operators
		Fixed operator+(const Fixed& right_side) const;
		Fixed operator-(const Fixed& right_side) const;
		Fixed operator*(const Fixed& right_side) const;
		Fixed operator/(const Fixed& right_side) const;

	// increment/decrement

	//min/max

};

	std::ostream& operator<<(std::ostream& output_stream, const Fixed& f);


// colors, inline makes only one copy of variable (from standart 17)
	// static inline const std::string kRed = "\033[1;31m";
	// static inline const std::string kBlue = "\033[1;34m";
	// static inline const std::string kGreen = "\033[1;32m";
	// static inline const std::string kMagenta = "\033[1;35m";
	// static inline const std::string kCyn = "\e[1;36m";
	// static inline const std::string kBlack = "\e[0;30m";
	// static inline const std::string kResetColor = "\033[0m";

#endif