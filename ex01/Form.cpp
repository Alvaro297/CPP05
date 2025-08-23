#include <iostream>
#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(std::string newName, const int newGradeToExecute, const int newGradeToSign) : name(newName), isSigned(false), gradeToExecute(newGradeToExecute), gradeToSign(newGradeToSign)
{
	this->isSigned = false;
	if (newGradeToSign < 1 || newGradeToExecute < 1)
		throw GradeTooHighException();
	else if (newGradeToSign > 150 || newGradeToExecute > 150)
		throw GradeTooLowException();
	std::cout << "Form created" << std::endl;
}

Form::Form(const Form& other) : name(other.name), isSigned(other.isSigned), gradeToExecute(other.gradeToExecute), gradeToSign(other.gradeToSign)
{
	if (other.gradeToSign < 1 || other.gradeToExecute < 1)
		throw GradeTooHighException();
	else if (other.gradeToSign > 150 || other.gradeToExecute > 150)
		throw GradeTooLowException();
	std::cout << "Form created" << std::endl;
}

Form::~Form(void) { std::cout << "Form destroyed" << std::endl; }

//** Getters **//
const std::string& Form::getName(void) const { return this->name; }
bool Form::getIsSigned(void) const { return this->isSigned; }
int Form::getGradeToExecute(void) const { return this->gradeToExecute; }
int Form::getGradeToSign(void) const { return this->gradeToSign; }


void Form::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() > this->getGradeToSign())
		throw GradeTooLowException();
	this->isSigned = true;
}

Form& Form::operator=(const Form& other)
{
	if (this != &other)
		this->isSigned = other.isSigned;
	std::cout << "Form assigned" << std::endl;
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Form& f)
{
	os << "Form: " << f.getName()
	   << ", grade to sign: " << f.getGradeToSign()
	   << ", grade to execute: " << f.getGradeToExecute()
	   << ", signed: " << (f.getIsSigned() ? "yes" : "no");
	return os;
}