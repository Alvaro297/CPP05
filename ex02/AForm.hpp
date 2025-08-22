#ifndef AFORM_HPP
# define AFORM_HPP

#include "Bureaucrat.hpp"

class AForm
{
private:
	const std::string	name;
	bool				isSigned;
	const int			gradeToExecute;
	const int			gradeToSign;
public:
	AForm(std::string newName, const int newGradeToExecute, const int newGradeToSign, bool isSigned = false);
	AForm(const AForm& other);
	AForm& operator=(const AForm& other);
	virtual const std::string getName(void) const;
	virtual bool getIsSigned(void) const;
	virtual const int getGradeToExecute(void) const;
	virtual const int getGradeToSign(void) const;
	virtual void beSigned(const Bureaucrat &b);
	virtual void beExecuted(const Bureaucrat &b) const = 0;
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
};


std::ostream& operator<<(std::ostream& os, const AForm& f);

#endif