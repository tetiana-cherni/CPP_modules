#include "Fixed.hpp"

// #define LOG_STEP(msg) std::cout << "[Line " << __LINE__ << "] " << msg << std::endl

int main()
{
	Fixed a;
	Fixed const b(10);
	Fixed const c(42.42f);
	Fixed const d(b);

	a = Fixed(1234.4321f);

	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;
	
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;
	return 0;
}

// int main()
// {
// 	std::cout << "Next call: Fixed a;" << std::endl;
// 	Fixed a;

// 	std::cout << "Next call: Fixed const b(10);" << std::endl;
// 	Fixed const b(10);

// 	std::cout << "Next call: Fixed const c(42.42f);" << std::endl;
// 	Fixed const c(42.42f);

// 	std::cout << "Next call: Fixed const d(b);" << std::endl;
// 	Fixed const d(b);

// 	std::cout << "Next call: a = Fixed(1234.4321f);" << std::endl;
// 	a = Fixed(1234.4321f);

// 	std::cout << std::endl;
// 	std::cout << "a is " << a << std::endl;
// 	std::cout << "b is " << b << std::endl;
// 	std::cout << "c is " << c << std::endl;
// 	std::cout << "d is " << d << std::endl;
	
// 	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
// 	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
// 	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
// 	std::cout << "d is " << d.toInt() << " as integer" << std::endl;
// 	return 0;
// }