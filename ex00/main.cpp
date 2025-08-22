#include "Bureaucrat.hpp"

int main()
{
	try {
		Bureaucrat b1("Alice", 42);
		std::cout << b1 << std::endl;
		b1.incrementGrade();
		std::cout << b1 << std::endl;
		b1.decrementGrade();
		std::cout << b1 << std::endl;
		Bureaucrat b2("Bob", 151);
	}
	catch (const std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
	return 0;
}