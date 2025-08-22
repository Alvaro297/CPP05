#ifndef PRESIDENTIALPARDOMFORM_HPP
# define PRESIDENTIALPARDOMFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : AForm
{
private:
	std::string target;
public:
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(const PresidentialPardonForm& other);
	PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
	~PresidentialPardonForm();
	std::string getTarget(void) const;
	void execute(Bureaucrat const &b);
};


#endif