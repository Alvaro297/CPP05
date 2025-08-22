#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string const newTarget) : target(newTarget) , AForm("ShrubberyCreationForm", 137, 145) { std::cout << "ShrubberyCreationForm created" << std::endl; }

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other) { std::cout << "ShrubberyCreationForm created" << std::endl; }

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	if(this != &other)
	{
		this->target = other.target;
		this->isSigned = other.isSigned;
	}
	std::cout << "ShrubberyCreationForm created" << std::endl;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() { std::cout << "ShrubberyCreationForm destroyed" << std::endl; }

void ShrubberyCreationForm::getTarget(void) { return this->target; }

void ShrubberyCreationForm::execute(Bureaucrat const &b);
{
	std::string filename;

	filename = this->target + "_shrubbery";
	if (this->isSigned && (b.getGrade() > this->gradeToExecute))
	{
		std::ofstream file(filename);
		if (file.is_open())
		{
			file << "       _-_-\\n";
			file << "    /~~   ~~\\\\\\n";
			file << " /~~         ~~\\\\\\n";
			file << "{               }\\n";
			file << " \\\\  _-     -_  /\\n";
			file << "   ~  \\\\ //  ~\\n";
			file << "_- -   | | _- _\\n";
			file << "  _ -  | |   -_\\n";
			file << "      // \\\\ \\n";
			file.close();
			std::cout << "Shrubbery created in " << filename << std::endl;
		}
		else
		{
			std::cerr << "Error: Could not open file " << filename << std::endl;
		}
	}
	else if (b.getGrade() < this->gradeToExecute)
		throw GradeTooLowException();
	else
		std::cout << "Error file not signed" << std::endl;
}
