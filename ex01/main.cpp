#include "Fixed.hpp"

#define LOG_STEP() std::cout << "\033[1m" << "[Line " << __LINE__ + 1 << "] " << "\033[0m"  << std::endl

int main()
{
	PrintMsg("\n_____Constructors_____");
	LOG_STEP();
	Fixed a;
	LOG_STEP();
	Fixed const b(10);
	LOG_STEP();
	Fixed const c(42.42f);
	LOG_STEP();
	Fixed const d(b);

	LOG_STEP(); a = Fixed(1234.4321f);

	PrintMsg("\n_____number_____");
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;
	
	PrintMsg("\n_____toInt_____");
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;

	PrintMsg("\n_____Destructors_____");
	return 0;
}
