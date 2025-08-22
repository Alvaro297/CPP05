#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const Bureaucrat& other) : name(other.name), grade(other.grade)
{
	if (other.grade < 1)
		throw GradeTooHighException();
	else if (other.grade > 150)
		throw GradeTooLowException();
	std::cout << "Bureaucrat created" << std::endl;
}

Bureaucrat::Bureaucrat(std::string newName, int newGrade) : name(newName), grade(newGrade)
{
	if (newGrade < 1)
		throw GradeTooHighException();
	else if (newGrade > 150)
		throw GradeTooLowException();
	std::cout << "Bureaucrat created" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this != &other)
	{
		if (other.grade < 1)
			throw GradeTooHighException();
		else if (other.grade > 150)
			throw GradeTooLowException();
		this->grade = other.grade;
	}
	std::cout << "Bureaucrat assigned" << std::endl;
	return *this;
}

Bureaucrat::~Bureaucrat() {std::cout << "Bureaucrat destroyed" << std::endl;}

const std::string Bureaucrat::getName(void) const { return this->name; }
int Bureaucrat::getGrade(void) const { return this->grade; }

void Bureaucrat::incrementGrade(void)
{
	this->grade -= 1;
	if (this->grade < 1)
		throw GradeTooHighException();
}

void Bureaucrat::decrementGrade(void)
{
	this->grade += 1;
	if (this->grade > 1)
		throw GradeTooLowException();
}

void Bureaucrat::executeForm(AForm const & form) const
{
	if (form.getIsSigned() && (form.getGradeToExecute() <= this->grade))
		std::cout << this->name << " executed " << form.getName() << std::endl;
	else if (form.getGradeToExecute() > this->grade)
		throw GradeTooLowException()
	else
		std::cout << "Error file not signed" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b)
{
	os << b.getName() << ", bureaucrat grade " << b.getGrade();
	return os;
}