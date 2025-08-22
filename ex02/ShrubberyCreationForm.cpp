#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string newName, const int newGradeToExecute = 137, const int newGradeToSign = 145, bool isSigned = false)
: AForm(newName, 137, 145){ std::cout << "ShrubberyCreationForm created" << std::endl; }

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other) { std::cout << "ShrubberyCreationForm created" << std::endl; }

ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other) : AForm(other)
{
	std::cout << "ShrubberyCreationForm created" << std::endl;
}