#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string const newTarget) : target(newTarget), AForm("RobotomyRequestForm", 45, 72) { std::cout << "RobotomyRequestForm created" << std::endl; }

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other) { std::cout << "RobotomyRequestForm created" << std::endl; }

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if (this != &other)
	{
		this->target = other.target;
		this->isSigned = other.isSigned;
	}
	std::cout << "RobotomyRequestForm created" << std::endl;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() { std::cout << "RobotomyRequestForm destroyed" << std::endl; }

void RobotomyRequestForm::getTarget(void) { return this->target; }

void RobotomyRequestForm::execute(Bureaucrat const &b)
{
	if (this->isSigned && (b.getGrade() > this->gradeToExecute))
	{
		std::cout << "BZZZZZZZZ" << std::endl;
		if(rand() % 2 == 0)
			std::cout << "Robotomized success " << this->target << std::endl;
		else
			std::cout << "Failed robotomized " << this->target << std::endl;
	}
	else if (b.getGrade() < this->gradeToExecute)
		throw GradeTooLowException();
	else
		std::cout << "Error file not signed" << std::endl;
}