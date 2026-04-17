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
		Fixed(const Fixed& other);
		Fixed& operator=(const Fixed& other);
	
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

	// dummy (int) to determine post- 
		Fixed& operator++();
		Fixed operator++(int);
		Fixed& operator--();
		Fixed operator--(int);

	static Fixed& min(Fixed& a, Fixed& b);
	static const Fixed& min(const Fixed& a, const Fixed& b);
	static Fixed& max(Fixed& a, Fixed& b);
	static const Fixed& max(const Fixed& a, const Fixed& b);
};

	void	PrintMsg(const std::string_view& msg);
	std::ostream& operator<<(std::ostream& output_stream, const Fixed& f);


#endif