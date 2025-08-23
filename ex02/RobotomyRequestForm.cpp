#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm(std::string const newTarget) : AForm("RobotomyRequestForm", 45, 72), target(newTarget) { std::cout << "RobotomyRequestForm created" << std::endl; }

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other) { std::cout << "RobotomyRequestForm created" << std::endl; }

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		this->target = other.getTarget();
	}
	std::cout << "RobotomyRequestForm assigned" << std::endl;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() { std::cout << "RobotomyRequestForm destroyed" << std::endl; }

const std::string& RobotomyRequestForm::getTarget(void) const { return this->target; }

void RobotomyRequestForm::execute(Bureaucrat const &b) const
{
	if (this->getIsSigned() && (b.getGrade() < this->getGradeToExecute()))
	{
		std::cout << "BZZZZZZZZ" << std::endl;
		if (std::rand() % 2 == 0)
			std::cout << "Robotomized success " << this->target << std::endl;
		else
			std::cout << "Failed robotomized " << this->target << std::endl;
	}
	else if (b.getGrade() > this->getGradeToExecute())
		throw GradeTooLowException();
	else if (!this->getIsSigned())
		throw FormNotSignedException();
}