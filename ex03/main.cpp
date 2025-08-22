
#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
	try
	{
		Bureaucrat b1("Alice", 130);
		ShrubberyCreationForm form1("garden");
		std::cout << "Antes de firmar: " << form1.getIsSigned() << std::endl;
		form1.beSigned(b1);
		std::cout << "Después de firmar: " << form1.getIsSigned() << std::endl;
		b1.executeForm(form1);
		form1.beExecuted(b1);
	}
	catch (const std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat b2("Bob", 150);
		ShrubberyCreationForm form2("patio");
		form2.beSigned(b2);
		b2.executeForm(form2);
		form2.beExecuted(b2);
	}
	catch (const std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat b3("Charlie", 130);
		ShrubberyCreationForm form3("balcony");
		b3.executeForm(form3);
		form3.beExecuted(b3);
	}
	catch (const std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	return 0;
}