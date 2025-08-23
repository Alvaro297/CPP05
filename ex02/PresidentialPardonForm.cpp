#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string const newTarget) : AForm("PresidentialPardonForm", 5, 25), target(newTarget) { std::cout << "PresidentialPardonForm created" << std::endl; }

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm(other) { std::cout << "PresidentialPardonForm created" << std::endl; }

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		this->target = other.getTarget();
	}
	std::cout << "PresidentialPardonForm assigned" << std::endl;
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm() { std::cout << "PresidentialPardonForm destroyed" << std::endl; }

const std::string& PresidentialPardonForm::getTarget(void) const { return this->target; }

void PresidentialPardonForm::execute(Bureaucrat const &b) const
{
	if (this->getIsSigned() && (b.getGrade() < this->getGradeToExecute()))
		std::cout << "Informs that " << this->target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
	else if (b.getGrade() > this->getGradeToExecute())
		throw GradeTooLowException();
	else if (!this->getIsSigned())
		throw FormNotSignedException();
}