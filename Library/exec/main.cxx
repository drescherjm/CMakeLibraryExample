#include <iostream>
#include "lib.h"
#include "MathLibrary.h"
#include <functional>

void testLibA()
{
	std::cout << lib_func() << std::endl;
}

void testLibB()
{
	// Initialize a Fibonacci relation sequence.
	fibonacci_init(1, 1);
	// Write out the sequence values until overflow.
	do {
		std::cout << fibonacci_index() << ": "
			<< fibonacci_current() << std::endl;
	} while (fibonacci_next());
	// Report count of values written before overflow.
	std::cout << fibonacci_index() + 1 <<
		" Fibonacci sequence values fit in an " <<
		"unsigned 64-bit integer." << std::endl;
}

int main()
{
	using Function = std::function<void()>;

	Function funcs[] = { testLibA,testLibB };

	for (auto& func : funcs) {
		func();
	}
}