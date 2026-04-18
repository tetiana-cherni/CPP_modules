#include "Fixed.hpp"

Fixed::Fixed(): 
	fixed_value_ (0)
{
	PrintMsg("Default constructor is called");
};

Fixed::~Fixed()
{
	PrintMsg("Default destructor is called");
};

Fixed::Fixed(const Fixed& other)
{
	PrintMsg("Copy constructor is called");
	this->fixed_value_ = other.getRawBits();
}

//always check this isn't self-assignment of class instance
Fixed& Fixed::operator=(const Fixed& other)
{
	PrintMsg("Copy assignment operator is called");
	if (this != &other)
	{
		this->fixed_value_ = other.getRawBits();
	}
	return *this;
}

int Fixed::getRawBits(void) const
{
	PrintMsg("getRawBits member function called");
	return fixed_value_;
}

void Fixed::setRawBits(int const raw)
{
	PrintMsg("setRawBits member function called");
	fixed_value_ = raw;
}

void	Fixed::PrintMsg(const std::string_view& msg) const
{
	std::cout << std::left << std::setw(35) 
		<< msg << " " << "\033[1m" << this << "\033[0m" 
		<< std::endl;
}
