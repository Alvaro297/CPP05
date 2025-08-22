#include "Form.hpp"
#include "Bureaucrat.hpp"

int main()
{
	try {
		Bureaucrat b1("Alice", 50);
		Form f1("Document", 30, 40);
		std::cout << f1 << std::endl;
		f1.beSigned(b1);
		std::cout << "After signing: " << f1 << std::endl;
		Bureaucrat b2("Bob", 100);
		Form f2("Secret", 20, 20);
		f2.beSigned(b2);
	} catch (const std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
	return 0;
}