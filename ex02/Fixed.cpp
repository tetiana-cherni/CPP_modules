#include "Fixed.hpp"
#include <string_view>

Fixed::Fixed(): raw_value_ (0){
	PrintMsg("Default constructor is called");
};

Fixed::~Fixed(){
	PrintMsg("Default destructor is called");
};

Fixed::Fixed(const int num)
{
	PrintMsg("Int constructor called");
	raw_value_ = num << kFractionalBits;
}

Fixed::Fixed(const float num)
{
	PrintMsg("Float constructor called");
	raw_value_ = roundf(num * (1 << kFractionalBits));
}

//copy constructor
Fixed::Fixed(const Fixed& other)
{
	PrintMsg("Copy constructor is called");
	this->raw_value_ = other.getRawBits();
	//*this = other;
}

//always check this isn't self-assignment of class instance
Fixed& Fixed::operator=(const Fixed& other)
{
	PrintMsg("Copy assignment operator is called");
	if (this != &other)
	{
		this->raw_value_ = other.getRawBits();
		//*this = other;
	}
	return *this;
}


// member functions

int Fixed::getRawBits(void) const
{
	PrintMsg("getRawBits member function called");
	return raw_value_;
}

void Fixed::setRawBits(int const raw)
{
	PrintMsg("setRawBits member function called");
	raw_value_ = raw;
}

float Fixed::toFloat(void) const
{
	float n;
	n = raw_value_ / (float)(1 << kFractionalBits);
	return n;
}

int Fixed::toInt(void) const
{
	int n;

	n = raw_value_ >> kFractionalBits;
	return n;

}

//comparison operators
bool Fixed::operator>(const Fixed& right_side) const
{
	return raw_value_ > right_side.getRawBits();
}

bool Fixed::operator<(const Fixed& right_side) const
{
	return raw_value_ < right_side.getRawBits();
}

bool Fixed::operator>=(const Fixed& right_side) const
{
	return raw_value_ >= right_side.getRawBits();
}

bool Fixed::operator<=(const Fixed& right_side) const
{
	return raw_value_ <= right_side.getRawBits();
}

bool Fixed::operator==(const Fixed& right_side) const
{
	return raw_value_ == right_side.getRawBits();
}

bool Fixed::operator!=(const Fixed& right_side) const
{
	return raw_value_ != right_side.getRawBits();
}

//arithmetic operators
Fixed Fixed::operator+(const Fixed& right_side) const
{
	Fixed result;
	result.setRawBits(raw_value_ + right_side.getRawBits());
	return result;
}

Fixed Fixed::operator-(const Fixed& right_side) const
{
	Fixed result;
	result.setRawBits(raw_value_ - right_side.getRawBits());
	return result;
}

//be carefull with overflow
//https://en.cppreference.com/w/cpp/language/static_cast.html
//https://www.geeksforgeeks.org/cpp/static_cast-in-cpp/
Fixed Fixed::operator*(const Fixed& right_side) const
{
	Fixed result;
	long new_value = (static_cast<long>(raw_value_) * static_cast<long>(right_side.getRawBits())) / (1 << kFractionalBits);
	result.setRawBits( static_cast<int>(new_value));
	return result;
}

//scaling factor 2^8 to keep float part
Fixed Fixed::operator/(const Fixed& right_side) const
{
	Fixed result;
	long tmp;
	tmp = (static_cast<long>(raw_value_) << kFractionalBits )/ (right_side.getRawBits());
	result.setRawBits(static_cast<int>(tmp));
	return result;
}

//increment/decrement
//https://en.cppreference.com/w/cpp/language/operator_precedence.html
 Fixed& operator++();//pre-increment
{
	int tmp = raw_value_;
	raw_value + 256
	return tmp;
}

/*

Fixed operator++();//post
Fixed& operator--();//pre-decrement
Fixed operator--();//post */

//free function 
//https://en.cppreference.com/w/cpp/language/attributes/maybe_unused.html
void	PrintMsg([[maybe_unused]] const std::string_view& msg)
{
	#ifndef TEST_MODE
		std::cout << msg << std::endl;
	#endif
	// (void)msg;
}

//custom instruction - how to handle instance of my class
std::ostream& operator<<(std::ostream& output_stream, const Fixed& obj)
{
	output_stream << obj.toFloat();
	return output_stream;
}
