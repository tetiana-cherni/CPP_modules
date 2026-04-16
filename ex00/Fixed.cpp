#include "Fixed.hpp"
#include <string_view>
//anonimus namespace, visible only in this cpp
namespace {
	void	PrintMsg(const std::string_view& msg)
	{
		std::cout << msg << std::endl;
	}
}

Fixed::Fixed(): 
	fixed_value_ (0)
{
	PrintMsg("Default constructor is called");
};

Fixed::~Fixed()
{
	PrintMsg("Default destructor is called");
};

//https://web.stanford.edu/class/archive/cs/cs106b/cs106b.1084/cs106l/handouts/170_Copy_Constructor_Assignment_Operator.pdf
Fixed::Fixed(const Fixed& other)
{
	PrintMsg("Copy constructor is called");
	this->fixed_value_ = other.getRawBits();
	//*this = other; bad practice; rule of Zero
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

int Fixed::getRawBits( void ) const
{
	PrintMsg("getRawBits member function called");
	return fixed_value_;
}

void Fixed::setRawBits( int const raw )
{
	PrintMsg("setRawBits member function called");
	fixed_value_ = raw;
}
