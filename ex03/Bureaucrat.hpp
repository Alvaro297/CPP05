#ifndef BUREAUCHAT_HPP
# define BUREAUCHAT_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"

class Bureaucrat
{
private:
	const std::string name;
	int grade;
public:
	Bureaucrat(const Bureaucrat& other);
	Bureaucrat(const std::string name, int grade);
	Bureaucrat& operator=(const Bureaucrat& other);
	~Bureaucrat();
	int getGrade(void) const;
	const std::string getName(void) const;
	void incrementGrade(void);
	void decrementGrade(void);
	void executeForm(AForm const & form) const;

	class GradeTooHighException : public std::exception
	{
		public:
			const char* what() const throw() { return "Grade too high"; };
	};

	class GradeTooLowException : public std::exception
	{
		public:
			const char* what() const throw() { return "Grade too Low"; };
	};
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif