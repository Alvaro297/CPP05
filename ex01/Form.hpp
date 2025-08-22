#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"

class Form
{
private:
	const std::string	name;
	bool				isSigned;
	const int			gradeToExecute;
	const int			gradeToSign;
public:
	Form::Form(std::string newName, const int newGradeToExecute, const int newGradeToSign);
	Form(const Form& other);
	Form& operator=(const Form& other);
	const std::string getName(void) const;
	bool getIsSigned(void) const;
	const int getGradeToExecute(void) const;
	const int getGradeToSign(void) const;
	void beSigned(const Bureaucrat &b);
	~Form();

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


std::ostream& operator<<(std::ostream& os, const Form& f);

#endif