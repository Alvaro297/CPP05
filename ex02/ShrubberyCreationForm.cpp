#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string const newTarget) : AForm("ShrubberyCreationForm", 137, 145), target(newTarget) { std::cout << "ShrubberyCreationForm created" << std::endl; }

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other) { std::cout << "ShrubberyCreationForm created" << std::endl; }

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		this->target = other.getTarget();
	}
	std::cout << "ShrubberyCreationForm assigned" << std::endl;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() { std::cout << "ShrubberyCreationForm destroyed" << std::endl; }

const std::string& ShrubberyCreationForm::getTarget(void) const { return this->target; }

void ShrubberyCreationForm::execute(Bureaucrat const &b) const
{
	std::string filename = this->target + "_shrubbery";
	if (this->getIsSigned() && (b.getGrade() < this->getGradeToExecute()))
	{
		std::ofstream file(filename.c_str());
		if (file.is_open())
		{
			file << "       _-_-\n";
			file << "    /~~   ~~\\\n";
			file << " /~~         ~~\\\n";
			file << "{               }\n";
			file << " \\  _-     -_  /\n";
			file << "   ~  \\ //  ~\n";
			file << "_- -   | | _- _\n";
			file << "  _ -  | |   -_\n";
			file << "      // \\\\ \n";
			file.close();
			std::cout << "Shrubbery created in " << filename << std::endl;
		}
		else
		{
			std::cerr << "Error: Could not open file " << filename << std::endl;
		}
	}
	else if (b.getGrade() > this->getGradeToExecute())
		throw GradeTooLowException();
	else if (!this->getIsSigned())
		throw FormNotSignedException();
}
