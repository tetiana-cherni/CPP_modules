#include "Fixed.hpp"

Fixed::Fixed():
	raw_value_ (0)
{
	PrintMsg("Default constructor is called");
};

Fixed::~Fixed()
{
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

//free function - custom instruction - how to handle instance of my class
std::ostream& operator<<(std::ostream& output_stream, const Fixed& obj)
{
	output_stream << obj.toFloat();
	return output_stream;
}

void	PrintMsg(const std::string_view& msg)
{
	std::cout << msg << std::endl;
}

