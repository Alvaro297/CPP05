#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>

class Bureaucrat;

class Form
{
private:
	const std::string	name;
	bool				isSigned;
	const int			gradeToExecute;
	const int			gradeToSign;
public:
	Form(std::string newName, const int newGradeToExecute, const int newGradeToSign);
	Form(const Form& other);
	Form& operator=(const Form& other);
	const std::string& getName(void) const;
	bool getIsSigned(void) const;
	int getGradeToExecute(void) const;
	int getGradeToSign(void) const;
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