#ifndef AFORM_HPP
# define AFORM_HPP

#include <string>
#include <ostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
protected:
	const std::string	name;
	bool				isSigned;
	const int			gradeToExecute;
	const int			gradeToSign;
public:
	AForm(std::string newName, const int newGradeToExecute, const int newGradeToSign);
	AForm(const AForm& other);
	AForm& operator=(const AForm& other);
	const std::string& getName(void) const;
	bool getIsSigned(void) const;
	int getGradeToExecute(void) const;
	int getGradeToSign(void) const;
	void beSigned(const Bureaucrat &b);
	virtual void execute(Bureaucrat const &b) const = 0;
	virtual ~AForm();

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

	class FormNotSignedException : public std::exception
	{
		public:
			const char* what() const throw() { return "Form is not signed"; };
	};
};


std::ostream& operator<<(std::ostream& os, const AForm& f);

#endif