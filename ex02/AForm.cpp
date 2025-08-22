#include "AForm.hpp"

AForm::AForm(std::string newName, const int newGradeToExecute, const int newGradeToSign, bool isSigned = false) : name(newName), gradeToExecute(newGradeToExecute), gradeToSign(newGradeToSign)
{
	if (newGradeToSign < 1 || newGradeToExecute < 1)
		throw GradeTooHighException();
	else if (newGradeToSign > 150 || newGradeToExecute > 150)
		throw GradeTooLowException();
	std::cout << "AForm created" << std::endl;
}

AForm::AForm(const AForm& other) : name(other.name), gradeToExecute(other.gradeToExecute), gradeToSign(other.gradeToSign), isSigned(other.isSigned)
{
	if (other.gradeToSign < 1 || other.gradeToExecute < 1)
		throw GradeTooHighException();
	else if (other.gradeToSign > 150 || other.gradeToExecute > 150)
		throw GradeTooLowException();
	std::cout << "AForm created" << std::endl;
}

AForm::~AForm(void) { std::cout << "AForm destroyed" << std::endl; }

//** Getters **//
const std::string AForm::getName(void) const { return this->name; }
bool AForm::getIsSigned(void) const { return this->isSigned; }
const int AForm::getGradeToExecute(void) const { return this->gradeToExecute; }
const int AForm::getGradeToSign(void) const { return this->gradeToSign; }


void AForm::beSigned(const Bureaucrat& b)
{
	if (this->getGradeToSign() < b.getGrade())
		throw GradeTooLowException();
	this->isSigned = true;
}

AForm& AForm::operator=(const AForm& other)
{
	if (this != &other)
		this->isSigned = other.isSigned;
	std::cout << "AForm assigned" << std::endl;
	return *this;
}

std::ostream& operator<<(std::ostream& os, const AForm& f)
{
	os << "AForm: " << f.getName()
	   << ", grade to sign: " << f.getGradeToSign()
	   << ", grade to execute: " << f.getGradeToExecute()
	   << ", signed: " << (f.getIsSigned() ? "yes" : "no");
	return os;
}