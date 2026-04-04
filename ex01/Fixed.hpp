
// https://cppreference.net/cpp/language/as_operator.html
// https://cppreference.net/cpp/language/classes.html
// https://www.geeksforgeeks.org/cpp/shallow-copy-and-deep-copy-in-c/
// https://www.linkedin.com/pulse/understanding-bitwise-copying-c-what-every-developer-should-el-bana-sqa1f/
// https://stackoverflow.com/questions/42749439/what-is-the-difference-between-memberwise-copy-bitwise-copy-shallow-copy-and-d
// https://www.geeksforgeeks.org/c/bitwise-operators-in-c-cpp/
// https://www.learncpp.com/cpp-tutorial/bitwise-operators/

/*  scientific notation / exponential notation for real numbers = for float type
N = M * n^p

N — number to write
M — mantissa;
n — basis of the exponential function;;
p (integer) — order (power exponent);
n^p — characteristic of a number. 

for our task int = 4 byte = 4 * 8 bit 
8 bit = 2^8 combinations 0&1 = 256 = [0, 255]
we reserve fractional_bits_ (8) for storing  characteristic of a number
N (our decimal) = M (int raw_value_) * (n (2 as represent 0&1) ^ (-fractional_bits_))
M = N / 2^(-fractional_bits)
M = N * 2^(fracrional_bits)
*/


#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath> 

class Fixed {
	private:
		int					raw_value_; //mantissa M
		static const int	kFractionalBits_ = 8; //scaling factor 2^8	
	public:
		Fixed();
		~Fixed();
		Fixed(const int num);
		Fixed(const float num);
		Fixed(const Fixed& other); //copy constructor
		Fixed& operator=(const Fixed& other); //copy assignment operator
	
		int getRawBits( void ) const;
		void setRawBits( int const raw );

		float toFloat(void) const;
		int toInt(void) const;
};

	std::ostream& operator<<(std::ostream& output_stream, const Fixed&  f);

#endif