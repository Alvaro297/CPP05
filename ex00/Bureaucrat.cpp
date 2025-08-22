#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const Bureaucrat& other) : name(other.name), grade(other.grade) {std::cout << "Bureaucrat created" << std::endl;}

Bureaucrat::Bureaucrat(std::string newName, int newGrade) : name(newName), grade(newGrade) {std::cout << "Bureaucrat created" << std::endl;}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this != &other)
	{
		this->grade = other.grade;
	}
	std::cout << "Bureaucrat assigned" << std::endl;
	return *this;
}

Bureaucrat::~Bureaucrat() {std::cout << "Bureaucrat destroyed" << std::endl;}