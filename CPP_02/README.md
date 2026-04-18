# Ad-hoc polymorphism, operator overloading and the Orthodox Canonical class form

## Key Concepts

1. Orthodox Canonical Class Form
	This approach relates to the Rule of Three, which has evolved into the Rule of Five and the Rule of Zero in modern C++ standards to handle move semantics and resource ownership more effectively.

2. Ad-hoc Polymorphism
	It is implemented by overloading standard operators (such as arithmetic + - * /, comparison < > ==, and stream insertion <<) for the custom Fixed class. This allows our fixed-point numbers to be manipulated intuitively, exactly like built-in types (e.g., int or float), with the compiler resolving the correct operation at compile-time.

3. Fixed-point Numbers vs Floating-point
	Unlike floating-point numbers, fixed-point representation uses a fixed number of bits for the fractional part. For this module, 8 bits are reserved for the fractional part (providing 256 combinations, represented as 1 << 8). The raw integer value is calculated by multiplying the decimal number by 256, and converting it back involves dividing by 256.

## Debugging and Testing 

- ex00: Object lifecycles are tracked by printing memory addresses.
- ex01: The __LINE__ macro is used to link log outputs directly to source code lines.
- ex02: Testing is managed using the doctest.h framework.

## Resources

### Orthodox Canonical Form and Memory
- [Stanford CS106L Handout: Copy Constructor and Assignment Operator](https://web.stanford.edu/class/archive/cs/cs106b/cs106b.1084/cs106l/handouts/170_Copy_Constructor_Assignment_Operator.pdf)
- [GeeksforGeeks: Shallow Copy and Deep Copy in C++](https://www.geeksforgeeks.org/cpp/shallow-copy-and-deep-copy-in-c/)

### Fixed-Point Arithmetic and Types
- [IEEE 754 Standard for Floating-Point Arithmetic](https://en.wikipedia.org/wiki/IEEE_754)
- [GeeksforGeeks: Bitwise Operators in C/C++](https://www.geeksforgeeks.org/c/bitwise-operators-in-c-cpp/)
- [LearnCpp: Bitwise Operators](https://www.learncpp.com/cpp-tutorial/bitwise-operators/)
- [GeeksforGeeks: static_cast in C++](https://www.geeksforgeeks.org/cpp/static_cast-in-cpp/)

### Operator Overloading
- [LearnCpp: Overloading Increment and Decrement Operators](https://www.learncpp.com/cpp-tutorial/overloading-the-increment-and-decrement-operators/)
- [StackOverflow: Prefix vs Postfix Operators](https://stackoverflow.com/questions/7031326/what-is-the-difference-between-prefix-and-postfix-operators)

### Language Mechanics
- [LearnCpp: Value Categories (lvalues and rvalues)](https://www.learncpp.com/cpp-tutorial/value-categories-lvalues-and-rvalues/)
- [Cppreference: maybe_unused Attribute](https://en.cppreference.com/w/cpp/language/attributes/maybe_unused.html)