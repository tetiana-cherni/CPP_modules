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

Fixed::Fixed(const Fixed& other)
{
	PrintMsg("Copy constructor is called");
	this->raw_value_ = other.getRawBits();
}

Fixed& Fixed::operator=(const Fixed& other)
{
	PrintMsg("Copy assignment operator is called");
	if (this != &other)
	{
		this->raw_value_ = other.getRawBits();
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

Fixed Fixed::operator*(const Fixed& right_side) const
{
	Fixed result;
	long new_value = (static_cast<long>(raw_value_) * static_cast<long>(right_side.getRawBits())) / (1 << kFractionalBits);
	result.setRawBits( static_cast<int>(new_value));
	return result;
}

Fixed Fixed::operator/(const Fixed& right_side) const
{
	Fixed result;
	long tmp;
	if (right_side.getRawBits() == 0)
	{
		throw std::runtime_error("Division by zero");
	}
	tmp = (static_cast<long>(raw_value_) << kFractionalBits )/ (right_side.getRawBits());
	result.setRawBits(static_cast<int>(tmp));
	return result;
}

//prefix increment
// prefix increment/decrement
// overloaded operators return current implicit object for chaining
Fixed& Fixed::operator++()
{
	raw_value_ += 1;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed	tmp(*this);

	raw_value_ += 1;
	return tmp;
}

Fixed& Fixed::operator--()
{
	raw_value_ -= 1;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed	tmp(*this);

	raw_value_ -= 1;
	return tmp;
}

//min-max
Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	if (a < b)
		return a;
	return b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	if (a < b)
		return a;
	return b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	if (a > b)
		return a;
	return b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	if (a > b)
		return a;
	return b;
}

//free function
void	PrintMsg([[maybe_unused]] const std::string_view& msg)
{
	#ifndef TEST_MODE
		std::cout << msg << std::endl;
	#endif
}

std::ostream& operator<<(std::ostream& output_stream, const Fixed& obj)
{
	output_stream << obj.toFloat();
	return output_stream;
}
