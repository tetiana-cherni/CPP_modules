// c++ -Wall -Wextra -Werror -std=c++17 -o test_contact test_contact.cpp ../src/contact.cpp -I./ -I../include/ -pthread

// doctest::Approx safely compares floats, handling the fixed-point resolution limit of 1/256.
//precision error / margin of error / resolution
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../Fixed.hpp"

static const float STEP = 1.0f / 256.0f; // smallest representable value

struct FixedTestFixture {
	Fixed a;
	Fixed b;
	Fixed c;
	Fixed zero;
	Fixed neg_a;
	Fixed neg_b;
	Fixed fraction;

	FixedTestFixture() 
		: a(10.5f), 
		  b(2.0f), 
		  c(10.5f), 
		  zero(0), 
		  neg_a(-10.5f), 
		  neg_b(-2.0f),
		  fraction(0.25f) {}
};

TEST_CASE_FIXTURE(FixedTestFixture, "Comparison operators") {
	SUBCASE("Equality and Inequality") {
		CHECK(a == c);
		CHECK(a != b);
		CHECK(zero == Fixed(0));
		CHECK(neg_a != a);
	}

	SUBCASE("Greater and Less than") {
		CHECK(a > b);
		CHECK(b < a);
		CHECK(zero > neg_a);
		CHECK(neg_b > neg_a);
	}

	SUBCASE("Greater/Less or Equal") {
		CHECK(a >= c);
		CHECK(b <= a);
		CHECK(zero <= b);
		CHECK(neg_a <= zero);
	}
}

// ---------------------------------------------------------------------------
// Arithmetic
// ---------------------------------------------------------------------------

TEST_CASE_FIXTURE(FixedTestFixture, "Addition") {
    CHECK((a + b).toFloat()       == doctest::Approx(12.5f).epsilon(STEP / 12.5f));
    CHECK((a + zero).toFloat()    == doctest::Approx(10.5f).epsilon(STEP / 10.5f));
    CHECK((a + neg_a).getRawBits() == 0); // exact cancellation — check bits directly
    CHECK((neg_a + neg_b).toFloat() == doctest::Approx(-12.5f).epsilon(STEP / 12.5f));
}

TEST_CASE_FIXTURE(FixedTestFixture, "Subtraction") {
    CHECK((a - b).toFloat()          == doctest::Approx(8.5f).epsilon(STEP / 8.5f));
    CHECK((a - a).getRawBits()       == 0);
    CHECK((zero - a).toFloat()       == doctest::Approx(-10.5f).epsilon(STEP / 10.5f));
    CHECK((neg_b - neg_a).toFloat()  == doctest::Approx(8.5f).epsilon(STEP / 8.5f));
}

TEST_CASE_FIXTURE(FixedTestFixture, "Multiplication") {
    CHECK((a * b).toFloat()         == doctest::Approx(21.0f).epsilon(STEP / 21.0f));
    CHECK((a * zero).getRawBits()   == 0);
    CHECK((neg_a * b).toFloat()     == doctest::Approx(-21.0f).epsilon(STEP / 21.0f));
    CHECK((neg_a * neg_b).toFloat() == doctest::Approx(21.0f).epsilon(STEP / 21.0f));
    CHECK((b * fraction).toFloat()  == doctest::Approx(0.5f).epsilon(STEP / 0.5f));
}

TEST_CASE_FIXTURE(FixedTestFixture, "Division") {
    CHECK((a / b).toFloat()         == doctest::Approx(5.25f).epsilon(STEP / 5.25f));
    CHECK((neg_a / b).toFloat()     == doctest::Approx(-5.25f).epsilon(STEP / 5.25f));
    CHECK((neg_a / neg_b).toFloat() == doctest::Approx(5.25f).epsilon(STEP / 5.25f));
    CHECK((b / fraction).toFloat()  == doctest::Approx(8.0f).epsilon(STEP / 8.0f));
}

// ---------------------------------------------------------------------------
// Increment / Decrement
// One step == 1 raw bit (1/256). Checked via getRawBits() — no float needed.
// ---------------------------------------------------------------------------

TEST_CASE("Pre-increment returns the incremented value") {
    Fixed val(0);
    Fixed res = ++val;
    CHECK(val.getRawBits() == 1);
    CHECK(res.getRawBits() == 1); // res and val are the same object after ++
}

TEST_CASE("Post-increment returns the value before increment") {
    Fixed val(0);
    Fixed res = val++;
    CHECK(val.getRawBits() == 1);
    CHECK(res.getRawBits() == 0); // res is a copy taken before the increment
}

TEST_CASE("Pre-decrement returns the decremented value") {
    Fixed val(0);
    Fixed res = --val;
    CHECK(val.getRawBits() == -1);
    CHECK(res.getRawBits() == -1);
}

TEST_CASE("Post-decrement returns the value before decrement") {
    Fixed val(0);
    Fixed res = val--;
    CHECK(val.getRawBits() == -1);
    CHECK(res.getRawBits() == 0);
}

// ---------------------------------------------------------------------------
// Min / Max
// ---------------------------------------------------------------------------

TEST_CASE_FIXTURE(FixedTestFixture, "min — returns the smaller of two values") {
    CHECK(Fixed::min(a, b)         == b);
    CHECK(Fixed::min(neg_a, neg_b) == neg_a); // -10.5 < -2.0

    const Fixed ca(10.5f), cb(2.0f);
    CHECK(Fixed::min(ca, cb) == cb);          // const overload
}

TEST_CASE_FIXTURE(FixedTestFixture, "max — returns the larger of two values") {
    CHECK(Fixed::max(a, b)         == a);
    CHECK(Fixed::max(neg_a, zero)  == zero);

    const Fixed cneg(-10.5f), czero(0);
    CHECK(Fixed::max(cneg, czero) == czero);  // const overload
}

// ---------------------------------------------------------------------------
// Edge cases
// ---------------------------------------------------------------------------

TEST_CASE("Smallest representable step above zero") {
    Fixed step;
    step.setRawBits(1); // 1/256 = 0.00390625
    CHECK(step.getRawBits() == 1);
    CHECK(step.toFloat() == doctest::Approx(0.00390625f).epsilon(0.0001f));
}

TEST_CASE("Largest representable integer value") {
    // With 8 fractional bits, the integer range is [-2^23, 2^23 - 1]
    Fixed large(8388607);
    Fixed large_neg(-8388608);
    Fixed zero(0);

    CHECK(large     > zero);
    CHECK(large_neg < zero);
    CHECK(large     > large_neg);
}

TEST_CASE("Addition that cancels to exactly zero") {
    Fixed pos(1000), neg(-1000);
    CHECK((pos + neg).getRawBits() == 0);
}