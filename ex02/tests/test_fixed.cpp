// c++ -Wall -Wextra -Werror -std=c++17 -o test_contact test_contact.cpp ../src/contact.cpp -I./ -I../include/ -pthread

// doctest::Approx safely compares floats, handling the fixed-point resolution limit of 1/256.
//precision error / margin of error / resolution
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../Fixed.hpp"

struct FixedTestFixture {
	Fixed a;
	Fixed b;
	Fixed c;
	Fixed zero;
	Fixed negative_a;
	Fixed negative_b;
	Fixed fraction;

	FixedTestFixture() 
		: a(10.5f), 
		  b(2.0f), 
		  c(10.5f), 
		  zero(0), 
		  negative_a(-10.5f), 
		  negative_b(-2.0f),
		  fraction(0.25f) {}
};

TEST_CASE_FIXTURE(FixedTestFixture, "Testing comparison operators with edge cases") {
	SUBCASE("Equality and Inequality") {
		CHECK(a == c);
		CHECK(a != b);
		CHECK(zero == Fixed(0));
		CHECK(negative_a != a);
	}

	SUBCASE("Greater and Less than") {
		CHECK(a > b);
		CHECK(b < a);
		CHECK(zero > negative_a);
		CHECK(negative_b > negative_a);
	}

	SUBCASE("Greater/Less or Equal") {
		CHECK(a >= c);
		CHECK(b <= a);
		CHECK(zero <= b);
		CHECK(negative_a <= zero);
	}
}

TEST_CASE_FIXTURE(FixedTestFixture, "Testing arithmetic operators with full flow") {
	SUBCASE("Addition flow") {
		CHECK((a + b).toFloat() == doctest::Approx(12.5f).epsilon(0.0039f));
		CHECK((a + zero).toFloat() == doctest::Approx(10.5f).epsilon(0.0039f));
		CHECK((a + negative_a).toFloat() == doctest::Approx(0.0f).epsilon(0.0039f));
		CHECK((negative_a + negative_b).toFloat() == doctest::Approx(-12.5f).epsilon(0.0039f));
	}

	SUBCASE("Subtraction flow") {
		CHECK((a - b).toFloat() == doctest::Approx(8.5f).epsilon(0.0039f));
		CHECK((a - c).toFloat() == doctest::Approx(0.0f).epsilon(0.0039f));
		CHECK((zero - a).toFloat() == doctest::Approx(-10.5f).epsilon(0.0039f));
		CHECK((negative_b - negative_a).toFloat() == doctest::Approx(8.5f).epsilon(0.0039f));
	}

	SUBCASE("Multiplication flow") {
		CHECK((a * b).toFloat() == doctest::Approx(21.0f).epsilon(0.0039f));
		CHECK((a * zero).toFloat() == doctest::Approx(0.0f).epsilon(0.0039f));
		CHECK((negative_a * b).toFloat() == doctest::Approx(-21.0f).epsilon(0.0039f));
		CHECK((negative_a * negative_b).toFloat() == doctest::Approx(21.0f).epsilon(0.0039f));
		CHECK((b * fraction).toFloat() == doctest::Approx(0.5f).epsilon(0.0039f));
	}


	SUBCASE("Division flow") {
		CHECK((a / b).toFloat() == doctest::Approx(5.25f).epsilon(0.0039f));
		CHECK((negative_a / b).toFloat() == doctest::Approx(-5.25f).epsilon(0.0039f));
		CHECK((negative_a / negative_b).toFloat() == doctest::Approx(5.25f).epsilon(0.0039f));
		CHECK((b / fraction).toFloat() == doctest::Approx(8.0f).epsilon(0.0039f));
	}
}

	TEST_CASE_FIXTURE(FixedTestFixture, "Testing increment and decrement operators") {
	SUBCASE("Pre-increment") {
		Fixed val(0);
		Fixed res = ++val;
		// Перевіряємо через сирі біти, оскільки крок має дорівнювати рівно 1
		CHECK(val.getRawBits() == 1);
		CHECK(res.getRawBits() == 1);
	}

	SUBCASE("Post-increment") {
		Fixed val(0);
		Fixed res = val++;
		CHECK(val.getRawBits() == 1);
		CHECK(res.getRawBits() == 0);
	}

	SUBCASE("Pre-decrement") {
		Fixed val(0);
		Fixed res = --val;
		CHECK(val.getRawBits() == -1);
		CHECK(res.getRawBits() == -1);
	}

	SUBCASE("Post-decrement") {
		Fixed val(0);
		Fixed res = val--;
		CHECK(val.getRawBits() == -1);
		CHECK(res.getRawBits() == 0);
	}
}

TEST_CASE_FIXTURE(FixedTestFixture, "Testing min and max functions") {
	SUBCASE("Min function (non-const)") {
		CHECK(Fixed::min(a, b) == b);
		CHECK(Fixed::min(b, a) == b);
		CHECK(Fixed::min(negative_a, negative_b) == negative_a);
	}

	SUBCASE("Min function (const)") {
		const Fixed const_a(10.5f);
		const Fixed const_b(2.0f);
		CHECK(Fixed::min(const_a, const_b) == const_b);
	}

	SUBCASE("Max function (non-const)") {
		CHECK(Fixed::max(a, b) == a);
		CHECK(Fixed::max(negative_a, zero) == zero);
	}

	SUBCASE("Max function (const)") {
		const Fixed const_negative_a(-10.5f);
		const Fixed const_zero(0);
		CHECK(Fixed::max(const_negative_a, const_zero) == const_zero);
	}
}

TEST_CASE_FIXTURE(FixedTestFixture, "Testing edge cases for arithmetic and comparison") {
	SUBCASE("Max and Min int limit representation") {
		// Оскільки 8 біт йде на дріб, на цілу частину залишається 23 біти + 1 біт знака.
		// Максимальне ціле значення: (1 << 23) - 1 = 8388607
		Fixed large(8388607); 
		Fixed large_negative(-8388608);
		
		CHECK(large > zero);
		CHECK(large > a);
		CHECK(large_negative < zero);
		CHECK(large_negative < negative_a);
	}

	SUBCASE("Smallest possible fraction step") {
		// Найменше значення, більше за нуль, яке може зберігати клас
		Fixed step;
		step.setRawBits(1); // 1/256 = 0.00390625
		
		Fixed res = zero + step;
		CHECK(res.getRawBits() == 1);
		CHECK(std::abs(res.toFloat() - 0.00390625f) <= 0.0001f);
	}

	SUBCASE("Multiplication by smallest step") {
		Fixed step;
		step.setRawBits(1);
		Fixed res = a * step; // 10.5 * 0.00390625 = 0.041015625
		CHECK(std::abs(res.toFloat() - 0.041015625f) <= 0.004f);
	}
	
	SUBCASE("Addition resulting in zero") {
		Fixed max_val(1000);
		Fixed min_val(-1000);
		CHECK((max_val + min_val) == zero);
		CHECK((max_val + min_val).getRawBits() == 0);
	}
}

	/*     
		// Якщо твій клас має обробку ділення на нуль, її теж треба тестувати.
		// У doctest для перевірки виключень (exceptions) використовується CHECK_THROWS.
		// Наприклад, якщо оператор / кидає std::runtime_error при діленні на нуль:
		// CHECK_THROWS(a / zero); 
	 */
