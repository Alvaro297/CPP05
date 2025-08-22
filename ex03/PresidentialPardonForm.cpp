#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string const newTarget) : target(newTarget), AForm("PresidentialPardonForm", 5, 25) { std::cout << "PresidentialPardonForm created" << std::endl; }

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm(other) { std::cout << "PresidentialPardonForm created" << std::endl; }

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	if (this != &other)
	{
		this->target = other.target;
		this->isSigned = other.isSigned;
	}
	std::cout << "PresidentialPardonForm created" << std::endl;
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm() { std::cout << "PresidentialPardonForm destroyed" << std::endl; }

void PresidentialPardonForm::getTarget(void) { return this->target; }

void PresidentialPardonForm::execute(Bureaucrat const &b)
{
	if (this->isSigned && (b.getGrade() > this->gradeToExecute))
		std::cout << "Informs that " << this->target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
	else if (b.getGrade() < this->gradeToExecute)
		throw GradeTooLowException();
	else
		std::cout << "Error file not signed" << std::endl;
}